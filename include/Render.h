/*!
 * \file include/Render.h
 * \brief OpenRaider Renderer class
 *
 * \author Mongoose
 * \author xythobuz
 */

#ifndef _RENDER_H_
#define _RENDER_H_

#include <vector>

#include "Room.h"
#include "ViewVolume.h"

/*!
 * \brief OpenRaider Renderer class
 */
class Render {
public:

    typedef enum {
        modeDisabled,
        modeLoadScreen,
        modeVertexLight,
        modeSolid,
        modeWireframe,
        modeTexture
    } RenderMode;

    typedef enum {
        fRoomAlpha              = (1 << 0),
        fEntityModels           = (1 << 1),
        fFog                    = (1 << 2),
        fGL_Lights              = (1 << 3),
        fRenderPonytail         = (1 << 4),
        fAnimateAllModels       = (1 << 5),
        // fMultiTexture           = (1 << 6), //! \todo Whats up with Multitexture stuff? Where is it needed?
    } RenderFlags;

    /*!
     * \brief Constructs an object of Render
     */
    Render();

    /*!
     * \brief Deconstructs an object of Render
     */
    ~Render();

    /*!
     * \brief Makes a screenshot, writes to disk
     * \param filenameBase basename of file to be written
     */
    void screenShot(char *filenameBase);

    /*!
     * \brief Gets current rendering mode
     * \returns current RenderMode
     * \fixme Don't return enum as int?!
     */
    int getMode();

    /*!
     * Removes current world/entity/etc geometry
     */
    void ClearWorld();

    /*!
     * \brief Clears bitflags, changes state of renderer in some way
     * \param flags RenderFlags to clear (ORed)
     * \fixme use enum not integer as parameter?!
     */
    void clearFlags(unsigned int flags);

    /*!
     * \brief Sets bitflags, changes state of renderer in some way
     * \param flags RenderFlags to set (ORed)
     * \fixme use enum not integer as parameter?!
     */
    void setFlags(unsigned int flags);

    void setMode(int n);

    /*!
     * \brief Renders a single game frame
     */
    void display();

    void setSkyMesh(int index, bool rot);

    unsigned int getFlags();

    /*!
     * \brief Check if a point is in the View Volume
     * \param x X coordinate
     * \param y Y coordinate
     * \param z Z coordinate
     * \returns true if point is visible
     */
    bool isVisible(float x, float y, float z);

    /*!
     * \brief Check if a sphere is in the View Volume
     * \param x X coordinate of center of sphere
     * \param y Y coordinate of center of sphere
     * \param z Z coordinate of center of sphere
     * \param radius radius of sphere
     * \returns true if sphere is visible
     */
    bool isVisible(float x, float y, float z, float radius);

    bool isVisible(BoundingBox &box);

    //! \fixme should be private
    ViewVolume mViewVolume; //!< View Volume for frustum culling

private:

    void drawLoadScreen();

    /*!
     * \brief Build a visible room list starting at index
     * \param index valid room index where to start the list
     */
    void newRoomRenderList(int index);

    /*!
     * \brief Build a visible room list starting from room and
     * only considers its linked rooms and their linked rooms.
     * \param room First room in list
     */
    void buildRoomRenderList(Room &room);

    /*!
     * \brief Renders Sky domes/boxes/etc by scaling factor.
     *
     * Texture must be initialized.
     * \param scale correct scale for map size
     */
    void drawSkyMesh(float scale);

    /*!
     * \brief Updates View Volume. Call once per render frame.
     */
    void updateViewVolume();

    std::vector<Room *> mRoomRenderList;

    unsigned int mFlags;                  //!< Rendering flags
    unsigned int mMode;                   //!< Rendering mode
    int mLock;
    int mSkyMesh;                         //!< Skymesh model id
    bool mSkyMeshRotation;                //!< Should Skymesh be rotated?
};

Render &getRender();

#endif
