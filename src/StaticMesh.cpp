/*!
 * \file src/StaticMesh.cpp
 * \brief Static Model Meshes
 *
 * \author xythobuz
 */

#include "global.h"
#include "Game.h"
#include "Render.h"
#include "StaticMesh.h"

#ifdef EXPERIMENTAL
std::vector<unsigned int> gColorTextureHACK;
#endif

TexturedTriangle::TexturedTriangle(int i[3], vec_t s[6], int tex, unsigned short trans) {
    index[0] = i[0];
    index[1] = i[1];
    index[2] = i[2];
    st[0] = s[0];
    st[1] = s[1];
    st[2] = s[2];
    st[3] = s[3];
    st[4] = s[4];
    st[5] = s[5];
    texture = tex;
    transparency = trans;
}

bool TexturedTriangle::operator< (TexturedTriangle &t) {
    return texture < t.texture;
}

void TexturedTriangle::display(vec_t *vertices, vec_t *colors, vec_t *normals) {
    assert(vertices != NULL);

    if ((getRender().getMode() != Render::modeWireframe)
            && (getRender().getMode() != Render::modeSolid)) {
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, texture + 1);
    }

    glBegin(GL_TRIANGLES);

    switch (getRender().getMode()) {
        case Render::modeSolid:
        case Render::modeVertexLight:
            if (colors != NULL) {
                glColor3fv(colors + index[0]);
                glTexCoord2fv(st);
                glVertex3fv(vertices + (index[0] * 3));

                glColor3fv(colors + index[1]);
                glTexCoord2fv(st + 2);
                glVertex3fv(vertices + (index[1] * 3));

                glColor3fv(colors + index[2]);
                glTexCoord2fv(st + 4);
                glVertex3fv(vertices + (index[2] * 3));
            } else if (normals != NULL) {
                glNormal3fv(normals + (index[0] * 3));
                glTexCoord2fv(st);
                glVertex3fv(vertices + (index[0] * 3));

                glNormal3fv(normals + (index[1] * 3));
                glTexCoord2fv(st + 2);
                glVertex3fv(vertices + (index[1] * 3));

                glNormal3fv(normals + (index[2] * 3));
                glTexCoord2fv(st + 4);
                glVertex3fv(vertices + (index[2] * 3));
            } else {
                glTexCoord2fv(st);
                glVertex3fv(vertices + (index[0] * 3));
                glTexCoord2fv(st + 2);
                glVertex3fv(vertices + (index[1] * 3));
                glTexCoord2fv(st + 4);
                glVertex3fv(vertices + (index[2] * 3));
            }
            break;

        case Render::modeWireframe:
            glVertex3fv(vertices + (index[0] * 3));
            glVertex3fv(vertices + (index[1] * 3));
            glVertex3fv(vertices + (index[2] * 3));
            break;

        default:
            glTexCoord2fv(st);
            glVertex3fv(vertices + (index[0] * 3));
            glTexCoord2fv(st + 2);
            glVertex3fv(vertices + (index[1] * 3));
            glTexCoord2fv(st + 4);
            glVertex3fv(vertices + (index[2] * 3));
    }

    glEnd();
}

#ifdef EXPERIMENTAL
int setupTextureColor(float *colorf) {
    unsigned char color[4];
    unsigned int colorI;
    int texture;

    color[0] = (unsigned char)(colorf[0]*255.0f);
    color[1] = (unsigned char)(colorf[1]*255.0f);
    color[2] = (unsigned char)(colorf[2]*255.0f);
    color[3] = (unsigned char)(colorf[3]*255.0f);

    ((unsigned char *)(&colorI))[3] = color[0];
    ((unsigned char *)(&colorI))[2] = color[1];
    ((unsigned char *)(&colorI))[1] = color[2];
    ((unsigned char *)(&colorI))[0] = color[3];

    bool found = false;
    unsigned int foundIndex = 0;
    for (foundIndex = 0; foundIndex < gColorTextureHACK.size(); foundIndex++) {
        if (gColorTextureHACK[foundIndex] == colorI) {
            found = true;
            break;
        }
    }

    if (!found) {
        gColorTextureHACK.push_back(colorI);
        texture = getGame().getTextureOffset() + gColorTextureHACK.size();

        getRender().loadTexture(Texture::generateColorTexture(color, 32, 32),
                32, 32, texture);
    } else {
        texture = getGame().getTextureOffset() + foundIndex;
    }

    return texture;
}
#endif

StaticMesh::StaticMesh(TombRaider &tr, unsigned int index) {
    int count, texture;
    int vertexIndices[6];
    float st[12];
    float color[4];
    unsigned short transparency;

    if (!tr.isMeshValid(index)) {
        dontshow = true;
        return;
    } else {
        dontshow = false;
    }

    // Mongoose 2002.08.30, Testing support for 'shootable' models ( traceable )
    tr.getMeshCollisionInfo(index, center, &radius);

    //! \fixme Arrays don't work either  =)
    // Mesh geometery, colors, etc
    tr.getMeshVertexArrays(index,
            &vertexCount, &vertices,
            &normalCount, &normals,
            &colorCount,  &colors);

    // Textured Triangles
    count = tr.getMeshTexturedTriangleCount(index);
    for (int i = 0; i < count; i++) {
        tr.getMeshTexturedTriangle(index, i,
                vertexIndices, st,
                &texture, &transparency);
        texturedTriangles.push_back(
                new TexturedTriangle(vertexIndices, st, texture + getGame().getTextureStart(), transparency));
    }

    // Coloured Triangles
    count = tr.getMeshColoredTriangleCount(index);
    for (int i = 0; i < count; i++) {
        tr.getMeshColoredTriangle(index, i,
                vertexIndices, color);
        st[0] = color[0];
        st[1] = color[1];
        st[2] = color[2];
        st[3] = color[3];
        st[4] = 1.0;
        st[5] = 1.0;

#ifdef EXPERIMENTAL
        texture = setupTextureColor(color);
#else
        texture = 0; // White texture
#endif
        transparency = 0;

        coloredTriangles.push_back(
                new TexturedTriangle(vertexIndices, st, texture + getGame().getTextureStart(), transparency));
    }

    // Textured Rectangles
    count = tr.getMeshTexturedRectangleCount(index);
    for (int i = 0; i < count; i++) {
        tr.getMeshTexturedRectangle(index, i,
                vertexIndices, st,
                &texture, &transparency);
        texturedRectangles.push_back(
                new TexturedTriangle(vertexIndices, st, texture + getGame().getTextureStart(), transparency));
        texturedRectangles.push_back(
                new TexturedTriangle(vertexIndices + 3, st + 6, texture + getGame().getTextureStart(), transparency));
    }

    // Coloured Rectangles
    count = tr.getMeshColoredRectangleCount(index);
    for (int i = 0; i < count; i++) {
        tr.getMeshColoredRectangle(index, i,
                vertexIndices, color);

        st[0] = color[0];
        st[1] = color[1];
        st[2] = color[2];
        st[3] = color[3];
        st[4] = 1.0;
        st[5] = 1.0;

#ifdef EXPERIMENTAL
        texture = setupTextureColor(color);
#else
        texture = 0; // White texture
#endif
        transparency = 0;

        coloredRectangles.push_back(
                new TexturedTriangle(vertexIndices, st, texture + getGame().getTextureStart(), transparency));
        coloredRectangles.push_back(
                new TexturedTriangle(vertexIndices + 3, st, texture + getGame().getTextureStart(), transparency));
    }

    // Sort faces by texture
    std::sort(texturedTriangles.begin(), texturedTriangles.end());
    std::sort(coloredTriangles.begin(), coloredTriangles.end());
    std::sort(texturedRectangles.begin(), texturedRectangles.end());
    std::sort(coloredRectangles.begin(), coloredRectangles.end());
}

StaticMesh::~StaticMesh() {
    while (!texturedTriangles.empty()) {
        delete texturedTriangles.back();
        texturedTriangles.pop_back();
    }

    while (!coloredTriangles.empty()) {
        delete coloredTriangles.back();
        coloredTriangles.pop_back();
    }

    while (!texturedRectangles.empty()) {
        delete texturedRectangles.back();
        texturedRectangles.pop_back();
    }

    while (!coloredRectangles.empty()) {
        delete coloredRectangles.back();
        coloredRectangles.pop_back();
    }

    delete [] vertices;
    delete [] normals;
    delete [] colors;
}

void StaticMesh::display() {
    if (!dontshow) {
        //! \fixme Duh, vis tests need to be put back
        //if (!isVisible(center, radius, bbox))
        //   return;

        //! \fixme 'AMBIENT' -- Mongoose 2002.01.08
        glColor3fv(WHITE);

        if (getRender().getMode() == Render::modeWireframe)
            glColor3fv(WHITE);

        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, 1);  // White texture for colors

        for (unsigned int i = 0; i < coloredTriangles.size(); i++)
            coloredTriangles.at(i)->display(vertices, colors, normals);

        for (unsigned int i = 0; i < coloredRectangles.size(); i++)
            coloredRectangles.at(i)->display(vertices, colors, normals);

        for (unsigned int i = 0; i < texturedTriangles.size(); i++)
            texturedTriangles.at(i)->display(vertices, colors, normals);

        for (unsigned int i = 0; i < texturedRectangles.size(); i++)
            texturedRectangles.at(i)->display(vertices, colors, normals);
    }
}

vec_t StaticMesh::getRadius() {
    return radius;
}
