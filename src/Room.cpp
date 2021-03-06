/*!
 * \file src/Room.cpp
 * \brief Room in World
 *
 * \author xythobuz
 */

#include "global.h"
#include "Camera.h"
#include "Log.h"
#include "Room.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/intersect.hpp>

bool Room::showBoundingBox = false;
bool Room::showRoomModels = true;
bool Room::showRoomSprites = true;
bool Room::showRoomGeometry = true;

Room::Room(glm::vec3 _pos, BoundingBox* _bbox, RoomMesh* _mesh, unsigned int f,
           int a, int x, int z, int i) : pos(_pos), bbox(_bbox), mesh(_mesh), flags(f),
    alternateRoom(a), numXSectors(x), numZSectors(z), roomIndex(i) {
    model = glm::translate(glm::mat4(1.0f), pos);
}

void Room::display(glm::mat4 VP) {
    if (showRoomGeometry) {
        mesh->display(VP * model);
    }

    if (showRoomModels) {
        for (auto& m : models) {
            m->display(VP);
        }
    }

    if (showRoomSprites) {
        for (auto& s : sprites) {
            s->display(VP);
        }
    }

    if (showBoundingBox) {
        bbox->display(VP, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f));
    }

    if (Portal::getShowBoundingBox()) {
        for (auto& p : portals) {
            p->display(VP);
        }
    }
}

bool Room::isWall(unsigned long sector) {
    orAssertLessThan(sector, sectors.size());

    //! \fixme is (sector > 0) correct??
    return ((sector > 0) && sectors.at(sector)->isWall());
}

long Room::getSector(float x, float z, float* floor, float* ceiling) {
    orAssert(floor != nullptr);
    orAssert(ceiling != nullptr);

    long sector = getSector(x, z);

    if ((sector >= 0) && (sector < (long)sectors.size())) {
        *floor = sectors.at(sector)->getFloor();
        *ceiling = sectors.at(sector)->getCeiling();
    }

    return sector;
}

long Room::getSector(float x, float z) {
    long sector = (((((int)x - (int)pos[0]) / 1024) *
                    numZSectors) + (((int)z - (int)pos[2]) / 1024));

    if (sector < 0)
        return -1;

    return sector;
}

void Room::getHeightAtPosition(float x, float* y, float z) {
    long sector = getSector(x, z);
    if ((sector >= 0) && (sector < (long)sectors.size()))
        *y = sectors.at(sector)->getFloor();
}

int Room::getAdjoiningRoom(float x, float y, float z,
                           float x2, float y2, float z2) {
    glm::vec3 orig(x, y, z);
    glm::vec3 dir(x2 - x, y2 - y, z2 - z);
    glm::vec3 intersect;

    for (unsigned long i = 0; i < portals.size(); i++) {
        if ((glm::intersectLineTriangle(orig, dir, portals.at(i)->getVertex(0),
                                        portals.at(i)->getVertex(1),
                                        portals.at(i)->getVertex(2), intersect))
            || (glm::intersectLineTriangle(orig, dir, portals.at(i)->getVertex(0),
                                           portals.at(i)->getVertex(3),
                                           portals.at(i)->getVertex(1), intersect)))
            return portals.at(i)->getAdjoiningRoom();
    }

    return -1;
}

void Room::displayUI() {
    ImGui::PushID(roomIndex);
    ImGui::Text("%03d", roomIndex);
    ImGui::NextColumn();
    ImGui::Text("%03d", alternateRoom);
    ImGui::NextColumn();
    ImGui::Text("0x%04X", flags);
    ImGui::NextColumn();
    if (models.size() > 0) {
        if (ImGui::TreeNode("...##model")) {
            for (auto& m : models) {
                m->displayUI();
            }
            ImGui::TreePop();
        }
    } else {
        ImGui::Text("None");
    }
    ImGui::NextColumn();
    if (portals.size() > 0) {
        if (ImGui::TreeNode("...##portal")) {
            for (auto& p : portals) {
                p->displayUI();
            }
            ImGui::TreePop();
        }
    } else {
        ImGui::Text("None");
    }
    ImGui::NextColumn();
    if (sprites.size() > 0) {
        if (ImGui::TreeNode("...##sprite")) {
            for (auto& s : sprites) {
                s->displayUI();
            }
            ImGui::TreePop();
        }
    } else {
        ImGui::Text("None");
    }
    ImGui::NextColumn();
    if (ImGui::Button("Warp")) {
        Camera::setPosition(pos);
    }
    ImGui::NextColumn();
    ImGui::PopID();
}

