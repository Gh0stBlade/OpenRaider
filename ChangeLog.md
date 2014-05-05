# OpenRaider Developer Branch ChangeLog 

## OpenRaider (0.1.3) xythobuz <xythobuz@xythobuz.de>

    [ 20140505 ]
    * Moved setup of Room, Portal, Box, Sector, ... into their
      Constructors.
    * Fixed menu play button
    * Removed Render flags fSprite, fRoomModel, fPortals
    * Room BoundingBox now using Box object

    [ 20140504 ]
    * Forcing use of new Room and Sprite classes in World.
    * Rewrote Sprite loading code in Game
    * Rewrote Room loading code in Game
    * Rewrote Render handling of Sprites, Rooms, Static Models, ...
    * No longer using second list of RenderRooms
    * Sprites and Static Models draw themselves

    [ 20140503 ]
    * Started big World-Data refactoring.
      - Created Sprite class with drawing code from Render
      - Created Room, Portal, Box, Sector, StaticModel classes

	[ 20140501 ]
	* Fix compiling with gcc on Arch Linux
	- carstene1ns <dev@f4ke.de>

	[ 20140418 ]
	* Moved command code into own file

	[ 20140416 ]
	* Map list now stored in Menu

	[ 20140405 ]
	* "Ported" all commands from old source
	* Slimmed down Camera considerably
	* Removed Emitter & Particle

	[ 20140403 ]
	* Now using "service locator" pattern for global singleton objects:
	  http://gameprogrammingpatterns.com/service-locator.html
	* Made abstract sound interface to provide different implementations
	  in the future (eg. for Windows)
	* "Backported" more commands from old source

	[ 20140330 ]
	* Fixed some segfaults relating to missing upper-bound-checks
	  while accessing std::vectors in World/Render
	* Added animation test command, FPS display

	[ 20140329 ]
	* Proper fix for texture offset bug
	* Added more asserts

	[ 20140327 ]
	* Started reimplementing game/render commands
	* Using only colors defined for renderer

	[ 20140326 ]
	* Fixed Sound segfault
	* Added basic camera and entity movement

	[ 20140324 ]
	* Hacked Texture Offset fix

	[ 20140323 ]
	* Try to load external sound effect files
	* Added Renderer
	* Moved gWorld, LARA into Game
	* Moved Camera sensitivity into OpenRaider
	* Re-Added LoadScreen render mode
	* Added level data processing code

	[ 20140322 ]
	* Added Game class, TombRaider level loader, Camera, Emitter,
	  Mesh, Particle, ViewVolume, Texture
	* Added SkeletalModel, now using std::vector
	* Added World, now using std::vector and std::list

	[ 20140321 ]
	* Added help command
	* Added proper command history for console
	* Added mouse scrolling support
	* Can bind mouse actions

	[ 20140316 ]
	* Added mouse support, also for menu
	* Added Console
	* Fixed system timer for BSDs (like Mac OS X)

	[ 20140315 ]
	* Added Window interface and WindowSDL implementation
	* Prepared cmake to make SDL optional in the future
	* Added event handling and font support
	* Started implementing command system
	* Config file now has .ini extension
	* Added transparent menu overlay
	* Implemented key bindings

	[ 20140314 ]
	* Started more or less complete re-write...
	* Sound now uses std::vector, volume setting, clear()
	* Moved math, Matrix, Quaternion and Vector3d into new math lib
	* Added main.h/cpp with OpenRaider global
	* Rewrote time lib using ctime

## OpenRaider (0.1.2) xythobuz <xythobuz@xythobuz.de>

	[ 20140313 ]
	* Removed unit tests. No unit tests are better then some half-assed
	  non working ones...

	[ 20140312 ]
	* Resizing the window works properly (except for fixed string positions)
	* Removed FullScreen config command and flag that had no effect
	* Set cursor visible when disabling mousegrab

	[ 20140311 ]
	* Removed empty Camera, Matrix, Particle, Quaternion,
	  Vector3d and ViewVolume destructors
	* Removed unneeded Quaternion assignment operator
	* Added Vector3d copy constructor

	[ 20140307 ]
	* Removed duplicated GL initialization code
	* Removed duplicated TGA writing code from Texture
	* Moved system_timer into time utilities, changed its API
	* Fixed a bug that prevented input of console commands using
	  the shift key for eg. uppercase letters or symbols
	* Removed (totally unfinished) networking support

	[ 20140306 ]
	* Created utility library
	* Rewrote bufferString()
	* Rewrote and fixed fullPath(), it worked more or less by accident

	[ 20140305 ]
	* Now using cmake build system
	* Pak file extensions are checked to see if they could be valid
	* Bugfix: String was used after being deleted in OpenRaider.cpp

	[ 20140304 ]
	* Removed memory test

	[ 20140303 ]
	* Removed Map.h & Tree.h, using std::map instead...

	[ 20140221 ]
	* Removed the `Map` command. Now the PakDir command causes
	  a recursive search of the specified directory. Every file found
	  is added to the map list if it validates.
	* The menu map list can now be stepped per folder with the
	  right and left arrows.
	* Methods wrapping printf-style functions now get compiler warnings
	* Reenabled some warnings and fixed them

	[ 20140216 ]
	* Removed the FastCard option. Not necessary on todays hardware?!
	* Removed UNICODE_SUPPORT, not working this way with SDL2

	[ 20140215 ]
	* Enabled previously disabled polygon smoothing & color material
	  when setting fastcard to true
	* Fixed bug in system timer millisecond conversion
	* Extended rc_get_bool to also accept 0 or 1 besides true and false

	[ 20140210 ]
	* Finished the Tomb Raider 1 Item/State definitions
	* Ported to SDL2 and SDL2-TTF using the Migration Guide:
	  https://wiki.libsdl.org/MigrationGuide

	[ 20140209 ]
	* Renamed OpenGLMesh to Mesh
	* Removed unused flags, enums, ...

	[ 20140202 ]
	* Fixed more cppcheck warnings
	* Removed unnecessary defines (USING_xxx)

	[ 20140201 ]
	* Rewrote Memory Unit Test using greatest
	* Used C++ static analysis tool cppcheck and tried to fix
	  its warnings

	[ 20140131 ]
	* All unit tests buildable again and no more warnings

	[ 20140129 ]
	* Removed unused libferit stuff
	* Changed code to generate much less warnings
	* Using relative epsilon for float comparison

	[ 20140124 ]
	* Fixed some TombRaider.cpp warnings

	[ 20140120 ]
	* Removed HAVE_SDL & HAVE_SDL_TTF flags. SDL & TTF always required!
	* Converted all tabs to spaces (4 spaces per tab)
	* Auto indented all cpp files

	[ 20140119 ]
	* Enabled linear texture filtering for fonts, resulting in nicer
	  looking down scaling
	* Removed unused TGA font parts of GLString with slight API changes
	* Modified GLString Unit Test to work with new GLString
	* Removed unused glDrawGrid, glDrawAxis, glPrintf2d, glPrintf3d
	  from SDLSystem
	* Silenced many more warnings

	[ 20140118 ]
	* Removed unused (and pretty empty) Entity class

	[ 20140117 ]
	* Reenabled room hopping on launch
	* Now using C++11 standard.
	* Turned on many more warnings and silenced some of them.
	* Removed empty Quaternion Unit Test

	[ 20140111 ]
	* Rewrote GLString Unit Test, now using TTF Font
	* Removed included TGA font and loading code
	* Rewrote Matrix Unit Test now using greatest
	* Documented MatMath, fixed bug in helRandomNum(),
	  added better Unit Test
	* Only one way of conversion between Deg and Rad in MatMath
	* Use the same style of include guards in all headers
	* Added memory test to SkeletalModel. Adding to OpenGLMesh causes
	  a segfault on launch

	[ 20140110 ]
	* Removed endian.(h/cpp) as it shouldn't be needed. See:
	  http://commandcenter.blogspot.de/2012/04/byte-order-fallacy.html
	* Removed empty Light.cpp
	* All Unit Tests build without warning
	* Converted many FIXME comments to be in the doxygen documentation
	* Removed hel & mstl folders, moved into parent directory
	* mtk_tga Unit Test uses greatest
	* Moved remaining Unit Tests (Network & TombRaider)
	* memory_test Unit Test no longer produces warnings
	* Building a memory test build no longer produces warnings

	[ 20140109 ]
	* Added greatest Test Framework, rewrote Sound Test
	* Renamed all memeory references to memory
	* Moved headers into include/
	* Put Unit Tests into test/

	[ 20140107 ]
	* Removed hel/Mass. There was an object of this class in World,
	  but it was never used!
	* Removed even more unused files (mstl/Vector.cpp,
	  hel/BoundingVolume.cpp, hel/Entity.cpp, hel/ParticleMass.h,
	  mstl/Stack.h)
	* Completely removed hel/Simulation, as it depends on missing
	  files (hel/CollisionObject)
	* Improved Makefile portability

	[ 20140106 ]
	* Hel Simulation Test builds, but doesn't work!

	[ 20140105 ]
	* Fixed the TR2 & TR3 SFX file loading to read the original MAIN.SFX
	* Fixed strange Mouse Y-Axis Overflow bug
	* Cleanup of Makefile

	[ 20140104 ]
	* Hel Unit Test build & passes
	* Spring & Simulation Tests unbuildable, missing files?
	* GLString Unit Test builds, works not every time?
	* TombRaider Unit & Regression Test working

	[ 20140103 ]
	* Removed more (unused?) code, PSKModel & UTPackage
	* Removed unused MD3, mtk3d, MtkImage stuff!

	[ 20140102 ]
	* Improved the Mac build steps...
	  Freealut now in /usr/local so we don't need to call
	  install_name_tool on the built binary
	* Removed the old & unused GLUTSystem
	* Replaced the (unknown) included sample sound file
	* Removed some redundant build config defines

	[ 20140101 ]
	* Fixed Wavebuffer loading of Sound subsystem, as well as
	  making the Sound Unit Test buildable on Mac.
	  Added new argument to loadWav, length of buffer.
	* Changed (unknown) included Font to Droid Sans Mono
	* Fixed Render bug, now console is visible again
	* Implemented CMD + Q shortcut on Mac to quit
	* Added bool mFirstMouseEvent to SDLSystem used to ignore
	  the first received mouse event, because its faulty, thanks
	  to an SDL bug:
	  http://gamedev.stackexchange.com/questions/33519/trap-mouse-in-sdl#comment56642_33554
	* Fixed incredibly slow mouse/camera movements
	* Fixed mouse grabbing in fullscreen mode. Also make mouse
	  invisible and grab it in windowed mode

	[ 20131231 ]
	* Added bool mFullscreen to SDLSystem, tried to fix Fullscreen
	  mode on Mac, still not working correctly, but better :)

	[ 20131227 ]
	* Moved included documents into GitHub Repo wiki
	  (https://github.com/xythobuz/OpenRaider/wiki)
	* Reduced start up time by increasing animation speed

	[ 20131221 ]
	* Reimplemented deprecated gluLookAt()
	* Reimplemented deprecated gluPerspective()
	* Reimplemented deprecated gluBuild2DMipmaps()
	* Reimplemented alutLoadWAVFile(), seems not to be working
	* Moved mac distribution logic from makefile into scripts

	[ 20131219 ]
	* Bundle now contains dynamic libraries not included with Mac OS X
	* Bundle now runs setup if needed
	* Fixed memory test builds not running on OS X

	[ 20131218 ]
	* Enabled ALUT on Mac OS X
	* Silenced many warnings regarding non-writable string constants
	* Fixed issues with linked libraries on Mac OS X
	* Implemented support for bundling OpenRaider as Mac App
	* Removed Microsoft Visual Studio Project files
	* Removed Screenshot Script

	[ 20131217 ]
	* No longer segfaults on launch in Mac OS X

	[ 20131215 ]
	* Wrote new README file
	* Added stub for missing hel/CollisionObject

## OpenRaider (0.1.1) Mongoose <mongoose@users.sourceforge.net>

	[ 20030713 ]
	* UTPackage class forked from PSKModel class
	* System class gets download, dir backports
	* libferit usage in public CVS
	* mtk_tga gets filename parm save and drops color swaping
	
	[ 20030704 ]
	* Tested PSKModel with models from:
	  http://udn.epicgames.com/pub/Content/UnrealDemoModels/
	* On the fly resolution change like in unit tests
	* GLString obsoleted, undefining HAVE_SDL_TTF
	  will cause OR to use font.tga texture fallback
	* Merged GLString and SDL_TTF utils Texture usage
	* TTF renderer replaces texture font system
	* Font system using new ortho projection 
	* Requirements file now in cvs
	* Fixed all known level loading issues from new codebase
	* Loadlevel command using mapname string
	* Maps are validated on rc load
	* Experimental TTF support in OpenRaider, Look in RC file 
	* Removed Console, MtkImage classes from private tree
	
	[ 20030701 ]
	* Removing OpenRaider Map use for level/music string storage
	  ( This means if you set a map to a certain number in rc, then
		you can no longer call it by 'load #' )
	* Fixed PSKModel unit test build
	* Fixed Hel Simulation, Spring unit test builds
	
	[ 20030630 ]
	* EXPERIMENTAL on the fly colored -> textured polygon code
	  ( It's not even funny how bad the colors match currently )
	* API changes in Texture class to make it easier to upgrade	
	* Screeshots stored in ~/.OpenRaider/sshots/
	* Fixed broke new multitexture support in Texture class
	* Texture class gets color texture generator
	* Texture class gets SDL_TTF support from SDLSystem
	* Update to OR Texture class ( backports from UnRaider )
	* Fixed matrix multiplcation issues with fixed code generator
	* Reworking broken Matrix changes into rollback fix
	* Fixes for Matrix based math breakage ( just rolled it rollback )
	
	[ 20030618 ]
	* Redone a lot of hel and it's use, broke a lot of things
	* UTF-8 and TTF font texture generation support
	* Camera broken, Matrix broken, Quaternion broken?
	* About finished mtk3d and hel converging
	* Phyiscs system base work done
	
	[ 20030604 ]
	* Console/command rollover not finished, but working
	* BUG portals/walk block too often with current collision
	* BUG room sprites have wrong texture ID?
	* Unicode key support?
	* Some more user definable keys using 'bind' command
	* System gets old resource system, new resource system
	  based on it with dynamic modes and command parsing
	
	[ 20030602 ]
	* Mouse grab command
	* New key input design, currently using ASCII to
	  be compatible with old code
	* SDL mouse grab toggle back in SDLSystem
	* SDL_TTF support starts in SDLSystem
	* Made printf string buffering part of System
	* Simulation fixes, GL unit test
	* Removed main.* from CVS
	* Removed Raider.*, gl_util.* from local tree	
	* Added Mass, ParticleMass, Simulation to CVS
	* More stat commands for debugging
	* Fix for console command marker strip
	* Updates to Hel, mass simulator, more vector operators 
	
	[ 20030528 ]
	* RC file now allows imports of another RC file
	  ( If you want to be a jackass you *can make it loop )
	* RC file now interprets spaces ( User request ) 
	* RC file allows trailing comments now
	* Room hopping disabled by default now 
	  ( command hop to enable )
	* Swimming movement added to stop-gap movement system
	
	[ 20030526 ]
	* Removed some test code from TombRaider
	* Fix for TR4 loading using TRC loader
	* Fix for solid mode rendering debug ( solid, r_light 1 )
	* Fix for wall crash segfault ( Vector.h [] out of bounds )
	* Finished up element API, some TRC support for faces 
	* Stopping work on array renderer until the element
	  system is back up ( possible backport for 0.1.0? )
	* Cleaning up OpenGLMesh prototype API
	
	[ 20030524 ]
	* New OpenGLMesh array renderer
	* Fix for Vector collection empty handling
	* Fix for the 20030519 segfault/lock on exit bug
	* More API unification coding, and OpenRaider usage
	  for room loading
	* Watch for a lot of new bugs, this is a lot of
	  coding changing around
	
	[ 20030522 ]
	* More unification, including TRC room translation
	  support starts ( convert from TRC to OR )
	* Handle TRC loading in OpenRaider CVS builds
	* TR5 loading tweaking to work for demo paks as well
	* Room sprite processing factored out
	
	[ 20030521 ]
	* TR5/TRC Sound ripping/in game loading finished
	* More TombRaider format unification
	* Testing of 0.1.0 and 0.1.1 builds on a GeForce4ti
	* TR5/TRC loader finished - loads only nondemo map I have
	
	[ 20030519 ]
	* More work on TR5/TRC support now using doc std
	* Refactored skeletal class structure
	* BUG seems to be leak fix related world clear lock
	* Fix: Skeletal animation memory leak
	* New rendering routine for new temp mesh type
	  ( Buggy and expensive, but it's a stop gap )
	  ( Colored polygons aren't really rendered as such )
	* Fix: OpenRaider new mesh API stop-gap handling
	* Fix: TombRaider new mesh loader API
	
	[ 20030517 ]	  
	* BUG found in new mesh loader API
	  ( Quad tess is broken in TombRaider for meshes )
	  ( Vertex array translation from TombRaider broken )
	* Event system partially in place, needs glue as well
	* Console commands from RC hack/fix
	
	[ 20030516 ]
	* Mesh rendering temp disabled until mesh renderer
	  is fully redone
	* Finally getting a lot of the more complex mesh
	  building routines pushed behind clean API from
	  the OpenRaider to the TombRaider class 
	  ( Could cause a lot of new bugs? )
	* Event system test structures introduced to World
	* Some major work on model_mesh rendering, also
	  abstracting interface for their construction
	* Some minor work on OpenGLMesh renderer, with code
	  in place to increase performance
	
	[ 20030513 ]
	* TombRaider engine abstraction for room
	  vertex and color loading and parsing
	
	[ 20030512 ]
	* New external SFX use for TR2/TR3 paks -- now
	  all versions load sound files into the game engine
	  See README for help using external paks.
	* New external SFX pak loading support for TR2 and TR3 
	* Documentation updates and user usability package tests
	  ( thanks Josh )
	* Apt source in place ( see README )
	* Automated debian packaging in Makefile ( make debian )
	* Animation half ass restored in non lara models agian
	* BUG found in SkeletalModel::setFrame - quick disable to
	  remove crash bug CLOSES 20030101 tmp filing
	
	[ 20030510 ]
	* Old TR4 sound support moved behind new interface
	* Sound support for TR1 using new interface - have to wait 
	  for external sound pak support for TR2 and TR3
	* New sound sample management/interface in TombRaider class
	
	[ 20030509 ]
	* Manually patched with JML's UNICODE support
	  add -DUNICODE_SUPPORT to BASE_DEFS flags in Makefile
	
	[ 20030101 ]
	* Seriously broken animation!  =)
	* I wonder how much this breaks - hacks shoved in to
	  keep it runnable until the new event system is started
	* Skeletal model refactoring
	* Seperating entity and animation states and it's ugly
	* Finer animation control starts	
	
## OpenRaider (0.1.0) Mongoose <mongoose@users.sourceforge.net>
	
	[ 20021228 ]
	* Md3 refactoring
	* Many Md3 fixes and features out of unit test work
	* Huge Md3 unit, testing ground for future TR unit test
	
	[ 20021227 ]
	* Md3 easter egg in cvs
	* State system work and testing
	
	[ 20021224 ]
	* Wireframe color code doc in README
	* Minor compile fixes for gcc 3.x
	* Default portal display in wireframe mode now
	* New hop command to disable room hopping movement
	* New r_animate command to enable entity animation test
	* Fixed showfps fault on load screen
	* Review of System timer
	* Replaced FPS estimation with pure frame rate counter
	* SDLSystem uses SDL timer now
	* Removed some dupilcate console commands out documented
	* Depth sorted particles
	* Lots of minor depth sorting and vising work
	
	
## OpenRaider (0.1.0pre11) Mongoose <mongoose@users.sourceforge.net>

	* Entity vis no longer considers rooms agian
	* New Vector replaces List as renderable container
	  for a great deal of memory savings
	* Room mesh/sprites rendering in nontexture modes agian
	* Documentation updates
	* Fix entity out of room fix
	* New OGL mesh can render with multitexture
	* New all bumpmaps are now loaded into texture memory
	* New [Network.Server] RC support
	* Run console commands from RC file
	* Neat new multitexture logo effect
	* Hel only build from now on
	* "Shooting" test in cvs
	* Fixes for depth rendering
	* New wireframe mode color codes for renderable type
	* Entity sprites back
	* Time to move to beta versioning
	
## OpenRaider (0.1.0pre10) Mongoose <mongoose@users.sourceforge.net>

	* New sshot upload script for my conv ;)
	* New entity rendering vising starts, primative depth sort
	* Static ( room models ) using sphere bounding volumes now
	* New enumeration coding style project wide starts
	* New room depth sorting code starts
	* Fix for version stamp in corner
	* New update room render list per frame command
	* Misc minor sound/animation updates
	* Hel vising fix in ViewVolume, hel enabled by default
	* Look for bugs caused by huge refactoring of codebase
	* Hel objects in all builds
	* World class temp keeps Light and OpenGLMesh deps for now
	* Refactoring: OpenRaider, Render, TombRaider classes
	* World class emerges in cvs ( Big refactoring job )
	* Texture use moved into Render class
	* Emitter use moved into Render class
	* Seperation of physical and rendered world starts
	* Hel clean up, unit testing fixes

	
## OpenRaider (0.1.0pre9-20021215) Mongoose <mongoose@users.sourceforge.net>

	* New Camera API, clean up starting
	* Quaternion ( class ) in cvs
	* Toggle for hel use
	* Fix port reporting is expected host order agian
	* libHel starts creeping into cvs build starting with some vising
	* Netcode fix

	
## OpenRaider (0.1.0pre7-20021109) Mongoose <mongoose@users.sourceforge.net>

	* Inactive text no longer rendered
	* More libhel work

	
## OpenRaider (0.1.0pre7-20021109) Mongoose <mongoose@users.sourceforge.net>

	* Little manual route chaining test for the fun of it
	* Trace tests
	* Merged (all?) GCC 3.2.x minor patches from my knoppix tests
	
	
## OpenRaider (0.1.0pre6-20020913) Mongoose <mongoose@users.sourceforge.net>

	* Fix for console use before level load crash
	* TR4 hack to play footsteps when running
	* TR4 pak sounds loaded and playable - just not sourced yet
	* New play command
	* Improved sound support
	
	
## OpenRaider (0.1.0pre6-20020907) Mongoose <mongoose@users.sourceforge.net>

	* TR4 pak sound reading and dumping 
	  ( I couldn't find any paks using compression - however
		my algorithm can handle those that may )
	* Sound read from TR1 paks agian ( TombRaider.test can dump them )
	* TR4 ponytail type guessing algorithm works with TR4 paks
	  ( May not apply to all custom lara models )
	* TR4 pigtails rendering algorithm now too
	* In TR4 ponytail works great with default settings
	* Up key now gets last command entered
	* r_ponytail console command
	* All builds use same texture binds as former EXPERMENTAL builds
	* Fixed crash related to invalid rooms?  Just allowing NULL rooms
	  in list and handling
	* TR4 GL light support ( pretty )

	
## OpenRaider (0.1.0pre6-20020906) Mongoose <mongoose@users.sourceforge.net>

	* One room render command and changes for other old commands
	* Fix for crash using new room ->adJRoom vector
	* Fixed room vertex lighting
	* Documentation updates
	* New scripts for installing
	* New client/server kills
	* Thanks dan for tesing multiplayer - lots of bugs found
	* Started moving room struct into more of a class type of
	  collections and what not

	
## OpenRaider (0.1.0pre6-20020905) Mongoose <mongoose@users.sourceforge.net>

	* Hack to handle camera out of world - moves to like a FPS
	  viewpoint -- needs quats and 'dragging' to make it smoother
	* Entities drawn in different order to handle large alpha 
	  polygon in rooms ( Hack until sorting algorithm is in place )
	* Little hack to force exit of threads w/o calling back
	* Lowered network traffic rate and disabled debugging to stdout

	
## OpenRaider (0.1.0pre5-20020904) Mongoose <mongoose@users.sourceforge.net>

	* Code to handle bad texture ids, like in Nasa.tr2
	* Network multiplayer test Client/Server can now connect
	  and pass data and generate clients on each end of game
	
	
## OpenRaider (0.1.0pre5-20020903) Mongoose <mongoose@users.sourceforge.net>

	* Network code starts
	
	
## OpenRaider (0.1.0pre5-20020902) Mongoose <mongoose@users.sourceforge.net>

	* Speed boost for entity room clipping
	* Fixed color lighting - still some polygons can go all white
	* Console commands for clipping and new fly mode
	* Getting ready to seperate world clipping and storage from Render
	* Cheap wall clipping hack ( works great however )
	  Doesn't take into account adjoint rooms ( there is a reason )
	* EXPERIMENTAL Better GL light support for font/world interaction
	* EXPERIMENTAL new level texture loading
	* Switching maps in game should never cause crashs anymore
	* Found then fixed several memory leaks
	* Makefile rule just for memory profiling build ( make memory )
	* Vectors replacing Lists for most collection implementations in Render

	
## OpenRaider (0.1.0pre5-20020830) Mongoose <mongoose@users.sourceforge.net>

	* Turn animation for fun
	* Room vertex lighting back in
	* Vertex color/normal support changes for model meshes
	* Skeletal model/mesh model collision _support_
	
	
## OpenRaider (0.1.0pre5-20020824) Mongoose <mongoose@users.sourceforge.net>

	* Hop up/down to rooms when in void
	* Primative 3rd person camera
	* GL light support for TR1-TR3
	* New OpenGLMesh fixes black texture bug ( tris texture index was off )
	* Removed room mesh rendering from Render
	
	
## OpenRaider (0.1.0pre5-20020823) Mongoose <mongoose@users.sourceforge.net>

	* OpenGLMesh and Light classes start
	* OpenRaider becomes singleton ( Trying to reduce Gobal deps )
	* Ah, a little free time -- cleaning up Render class a little

	
## OpenRaider (0.1.0pre5-20020818) Mongoose <mongoose@users.sourceforge.net>

	* Auto depends generation for certian people  =p
	
	
## OpenRaider (0.1.0pre5-20020817) Mongoose <mongoose@users.sourceforge.net>

	* Time based animation tracer
	* Rounded out mtk3d a little more with common func from
	  other projects
	* New pathing subsystem
	* Relocatable data dir ( thanks joshua for idea )
	  Set by using init var 'HomeDir'

	
## OpenRaider (0.1.0pre4-20020816) Mongoose <mongoose@users.sourceforge.net>

	* Fixed room mesh cache tris texcoors
	* Changed room tracking code
	* Replaced old room cache mesh texcoor system for tris
	* Adjusted TR3, TR4 vertex colors ( So it's not dark )
	* New menu state for keys
	* Major OpenRaider class clean up, reducing, reformatting for
	  use with picky compilers, etc
	* BUGS update, all maps retested -- should load all TR1-TR4 maps

	
## OpenRaider (0.1.0pre3-20020815) Mongoose <mongoose@users.sourceforge.net>

	* Debugging bad texture coor/vertex layout in some TR1/TR3/TR4 quads
	* Removed strict dummy quad insertion in OpenRaider::ProcessMoveables
	* Wall detection ( no clipping yet )
	* Fix for bad cache room mesh crash ( Alpha quads were using bad
	  values b/c assigned to wrong structure )
	* More debugging for bad cache room mesh crash
	* New animation fix by making getNumAnimsForMoveable use signed
	  values ( seems to make TR4 and other levels loadable agian )
	* Stopped flickering idle lara by only drawing 1 frame of idle
	* Better bad cache quad handling?
	
	
## OpenRaider (0.1.0pre2-20020814) Mongoose <mongoose@users.sourceforge.net>

	* Fix for room quad's texture bug
	* Console print system prototype
	* Misc clean ups
	* Level load menu prototype active by default
	* New debug info in game room/sector/pos
	* Floor player clipping by sector ( yay )
	
	
## OpenRaider (0.1.0pre1-20020813) Mongoose <mongoose@users.sourceforge.net>

	* Floor player clipping by box ( hhmmm... )
	* Backport of Camera
	* Backport of SDLSystem prototype to replace SDL wrapper
	* Backport of mtk3d with GL style matrices and etc
	* Hacky fix for texture ids for room polygons
	  ( Caused by new fast cache room polygon builder )
	* Backport of UnRaider Texture handler

	
## OpenRaider (0.0.5-20020615) Mongoose <mongoose@users.sourceforge.net>

	* Todo new texcoors for alpha quads, tris, and alpha tris not done
	* Bug found Texture ids broken on new room mesh translation
	* Texcoord fix for quads
	* Removed damned vertex arrays
	
	
## OpenRaider (0.0.5-20020609) Mongoose <mongoose@users.sourceforge.net>

	* Partially fixed new renderer/translator

	
## OpenRaider (0.0.5-20020608) Mongoose <mongoose@users.sourceforge.net>

	* New Makefile optional memeory_test.cpp OBJ injection
	* "Commit of Doom" to break cvs source, yay!
	
	
## OpenRaider (0.0.5-20020607) Mongoose <mongoose@users.sourceforge.net>

	* Render cleaned up a little more
	* New room mesh system using arrays
	
	
## OpenRaider (0.0.4-20020405) Mongoose <mongoose@users.sourceforge.net>

	* Fixed TR4 bone layering
	* Worked on finiding/rendering ponytail some more
	* Moved angle clac for tags back into TombRaider class
	* Screenshot TGA file fix

	
## OpenRaider (0.0.4-20020405) Mongoose <mongoose@users.sourceforge.net>

	* Ponytail hack
	* Better UV generation
	* Broke TR2 with the new animation framing 
	* Animation frame 'safety valve' to prevent overflows
	  until it can be fixed correctly
	* Animation translation fixes

	
## OpenRaider (0.0.4-20020404) Mongoose <mongoose@users.sourceforge.net>

	* More TR format notes
	* TR4 object header
	* Minor changes to OpenRaider for speed/calarity
	* Idle aframe test code in
	
	
## OpenRaider (0.0.4-20020403) Mongoose <mongoose@users.sourceforge.net>

	* Fix for Lara model picking in TR4
	* Fix for TR4 loading ( tr4_light )
	* Fix for TR4 loading ( tr4_ai_data )
	* Fog support
	* Fix for world geo ( room bbox adjust )
	* Fix for bad mem usage reporting for overhead
	* Fix for HUGE memory leaks in TombRaider class
	
	
## OpenRaider (0.0.4-20020401) Mongoose <mongoose@users.sourceforge.net>

	* Fix for memfile size reporting
	* Fix for GLString truncation
	* New audio dir support back in
	* Fix for insert of tree_insert for memeory
	* Iterative version of tree_insert for memeory togglable
	  at compile time
	* Fix for m-string max accounting
	* RBTree fix for memeory ( must stop coding after 0200 )
	
	
## OpenRaider (0.0.4-20020330) Mongoose <mongoose@users.sourceforge.net>

	* Stability has degraded with aggressive feature prototyping
	* More information for zero allocs
	* Fix for some 0 byte allocatations found in project
	* Check for 0 byte allocatations
	* Old List back in for now - slower, smaller
	* Removed many unnessacary sleeps from older builds
	* New feature tracks memory usage by file
	* Print to screen while loading back
	* New GLString now has helper functions for speedy string 
	  updates to replace hacks
	* Fixed damn 'memeory' rbtree
	* More verbose fatal error reporting
	* Reworked memeory prototype into better code
	* Removed working list tracker from memeory
	
	
## OpenRaider (0.0.4-20020329) Mongoose <mongoose@users.sourceforge.net>

	* Memeory memory overhead reduction for filename storage
	
	
## OpenRaider (0.0.4-20020328) Mongoose <mongoose@users.sourceforge.net>

	* You may want to disable USE_TREE_MEMINFO until RB is fixed
	* Back to dynamic C-strings to save 'memeory memory'
	* Wrote a RBTree implementation directly into Memeory util
	* TGA debug fix
	* Looking at writing RBTree directly into Memeory util
	* Fixed driver string memory leak in main found with Memeory
	* Fixed GLString memory leak just found with Memeory
	* Fixes for release build to avoid memeory debugger
	* Memeory changes to avoid new/delete calls internally
	  affecting MEMEORY_ERROR reports ( much much slower list based )
	* New iostreams and memeory header guards
	* Doh, corerction on pointer 0 padding
	* New delete accounting hack
	* New Memeory unit test features/fixes
	* Printing addr with hexadecimal for obvious reasons

	
## OpenRaider (0.0.4-20020327) Mongoose <mongoose@users.sourceforge.net>

	* Fixed overlapped vars/data members
	* Dumps memeory report filename fix
	* Dumps memeory report for unfreed on exit now?
	* Console commands to debug 'memeory'
	* New c func printing option in Tree
	* Memeory profiling system starting
	* Font data fixes
	* Fixed sourceforge cvs tree

	
## OpenRaider (0.0.4-20020325) Mongoose <mongoose@users.sourceforge.net>

	* Fixed bug where ent draw didn't account for viewmodel
	  in same room
	* New texture binding method for strict checking and
	  to avoid prechecks on unsorted polygons
	* More rendering toggles for more testing
	* Draw room bbox with r_portal
	* Moved more commands to console only ( See README )
	
	
## OpenRaider (0.0.4-20020323) Mongoose <mongoose@users.sourceforge.net>

	* Fix rendering bug with r_portal
	* RC uses pakdir for strict path enforcement now
	* New RC commands for Map/Music that represent backend correctly
	  ( It's a FIFO, not a sorter )
	* RC parser now uses console command parser helper too
	* Improvements to console command parser 
	  ( less memory, faster normal case, easier to add new commands )
	* Hack to try to unload level shows it's time to start a
	  rewrite  =)
	
	
## OpenRaider (0.0.4-20020322) Mongoose <mongoose@users.sourceforge.net>

	* Screenshot console command
	* View model render toggle console command
	* View model index fix for entity use
	* Console command naming clean up starting
	* Console fix for backspacing over prompt
	* Load command to load levels by index
	* Many more console commands, replacing some key commands
	* Sprites render after players now for more accurate scene
	* Collapsed some rendering gobals into temp LARA entity gobal
	* Portal visual debugging
	* Console fix for prompt display after command given
	* Fix for bad cvs sync
	
	
## OpenRaider (0.0.4-20020321) Mongoose <mongoose@users.sourceforge.net>

	* Portal (precompiled) use starts
	* Very basic console prototype in place
	* Render control flags ( Not same as mode flags )
	

## OpenRaider (0.0.3-20020119) Mongoose <mongoose@users.sourceforge.net>
	
	* Compile w/ -DEXPERIMENTAL_EMITTER_TEST to run snow test in game
	* Fix for RC loader

	
## OpenRaider (0.0.3-20020111) Mongoose <mongoose@users.sourceforge.net>

	* Temp resource redundency pruning solution
	* More string safety auditing and fixes

	
## OpenRaider (0.0.3-20020109) Mongoose <mongoose@users.sourceforge.net>

	* Hack to fix texture dumping
	* More string clean up

	
## OpenRaider (0.0.3-20020108) Mongoose <mongoose@users.sourceforge.net>

	* Minor TR support work
	* Texture dumping fix for new mtk_tga
	* New tristrip rendering sprites
	* Changed to snprint in all objects now
	* Clean up in texture use
	* Clean up in screenshot code

	
## OpenRaider (0.0.3-20020107) Mongoose <mongoose@users.sourceforge.net>

	* Animation frame testing hack back  keys '[' and ']' 
	* Reduction of room rendering top levels ( consistent speed? )
	* Improvments to texture handling and loading

	
## OpenRaider (0.0.3-20020106) Mongoose <mongoose@users.sourceforge.net>

	* Updated mtk_tga from my current mtk_image source
	  fixes tga save bug and more stuff
	* New more correct FPS counter for alpha testers amusement
	  DisplayFPS=true in init and key command 'f'
	* Refactoring and clean up in OpenRaider
	* TombRaider getting ready for testing new class based system
	* Got new specs for TR4 and TR5
	* Readying class based system for new physics and rendering

	
## OpenRaider (0.0.3-20020104) Mongoose <mongoose@users.sourceforge.net>

	* Fixes for fast texture cache for older tombraider data
	* Fixes for TombRaider unit test
	* Makefile changes for gcc 3.0
	* GLString use fix, forgot to disable culling - thanks dan
	* Keyboard turning ( On keys 1 and 4 for now ) by request  =)


## OpenRaider (0.0.3-20020103) Mongoose <mongoose@users.sourceforge.net>

	* Tune up of Sound
	* Disable cusor show on switch to fullscreen also
	* GLString scaling
	* Seperated InitGame and LoadLevel ( <Alt> l to load level )
	* New Sound flags ( allows for easier expansion )
	* Start loadscreen before caching sound now
	* NOTE audio support is fine - just low memory condition kill

	
## OpenRaider (0.0.3-20020102) Mongoose <mongoose@users.sourceforge.net>

	* Broke audio support by switching around 
	  OpenRaider, LoadLevel/SetupAudio
	* README update
	* Texture caching while reading from diskfile in callback
	* New load screen percentage feedback via callback
	* Fix for Tombraider multiple Clear() bug
	* New load ordering, might break some things
	* More work on GLString use in OR
	
	
## OpenRaider (0.0.3-20020101) Mongoose <mongoose@users.sourceforge.net>

	* Speed set on Camera
	* Played with some refactoring in OpenRaider class
	  and thread hacks for external texture use
	* New texture loading to make external textures
	  id independent of TR texture id at load time
	* Changed 'load screen' layout and particle setup
	* Removed dependence of Emitter on Texture agent - calls
	  GL texture bind directly now
	* Particle partial resync with freyja_particle tree
	* Emitter partial resync with freyja_particle tree
	* Render minor reduction/refactoring, breaking up some code
	* New GL font system for OpenRaider ( GLString )

	
## OpenRaider (0.0.3-20011231-2) Mongoose <mongoose@users.sourceforge.net>

	* GlGetString use 'correct' fix
	* Music list reimplemented for CVS
	* Emitter commited to CVS ( oopsie )
	* Changlog reformated


## OpenRaider (0.0.3-20011231) Mongoose <mongoose@users.sourceforge.net>

	* New Changlog format
	* Minor GL string use 'temp fix' in Render
	* ModelDebug option to RC to disable model load debugging
	* TODO update

	
## OpenRaider (0.0.3-20010813) Mongoose <mongoose@users.sourceforge.net>

	* Minor rendering changes
	* Particle test fix


## OpenRaider (0.0.3-20010813) Mongoose <mongoose@users.sourceforge.net>

	* Particle testing ( Using one of my freyja prototypes )
	* Fullscreen toggle - '9' key


## OpenRaider (0.0.3-20010810) Mongoose <mongoose@users.sourceforge.net>

	* Timer prototype starts, just using a time delay for now


## OpenRaider (0.0.3-20010624) Mongoose <mongoose@users.sourceforge.net>

	* New reference specs, moved to G400 MGA DRI on X 4.1.0


## OpenRaider (0.0.3-20010621) Mongoose <mongoose@users.sourceforge.net>

	* Set up new box just for windows TR compatibility tests
	  ( got old ppro out, bought a hdd for it - weee )
	* Testing exported meshes with Freyja
	* Freyja plug-in for TRMESH ( TombRaider mesh export )
	* Mesh export test for TombRaider
	* Texel adjustment method rolled back into TombRaider


## OpenRaider (0.0.3-20010620) Mongoose <mongoose@users.sourceforge.net>

	* TR4 sky mesh?
	* Texture changes
	* Freyja work with ponytail graphing
	* New FPS counter uses larger frame samples and reset 
	  ( readings still off by a little )
	* Splash screen for threaded loads (shakes for fullscreen feedback)
	* Particle engine research ( no code )
	* Threading testing


## OpenRaider (0.0.3-20010619) Mongoose <mongoose@users.sourceforge.net>

	* Might wait to install X 4.0.1 to work on bump map rendering
	* Render check for multitexture
	* Fixed OpenRaider to use new TombRaider::Texture API
	* Bump map use with new TombRaider backend API
	* "TR3 objtexture alpha clip" back in for 32bit textiles
	* More testing features like texture dumping for all versions
	* Special texture loading default use in TR4/TR5
	* Zero padding on dumped textures - yes, it is about time
	* Fixed special texture loading/dumping


## OpenRaider (0.0.3-20010618) Mongoose <mongoose@users.sourceforge.net>

	* 32bit texture default use in TR4/TR5
	* 32bit texture testing in TR5
	* Make rule regression testing in cvs tree
	  `make tombraider.test`
	* Better make rules for tombraider.test
	* TombRaider fixes for compression use and dellocation
	* New TombRaider::LoadTR5
	* Worked on TombRaider agent


## OpenRaider (0.0.3-20010617) Mongoose <mongoose@users.sourceforge.net>

	* Added *some of the TR5 spec to regression test build


## OpenRaider (0.0.3-20010616) Mongoose <mongoose@users.sourceforge.net>

	* Some minor checks for bad allocation of meshes?
	* Changed moveable code to assume nonanimated entity
	* Entity drawing tied to room drawing 
	  (For vising, later use an entity cache per room to avoid full cycle)
	* Screenshot name now based on VERSION string (better bugs reports)


## OpenRaider (0.0.3-20010615) Mongoose <mongoose@users.sourceforge.net>

	* Fixed Freyja tree's colored polygons
	* More debug output on animation building
	* Fixed Freyja's tree too
	* Fixed TR4 decompress bug 
	  ( silly me, it only worked because of opt, didn't clear a var )
	* Animation grouping prototype


## OpenRaider (0.0.3-20010614) Mongoose <mongoose@users.sourceforge.net>

	* Fixes for mesh rendering ambient light level
	* Fixes for animtion rendering
	* Fixes for animation loading 
	  (TR2+ lara has some animation problems still, with junk frames)
	  (TR1 lara works because all the right indices = 0)


## OpenRaider (0.0.3-20010613) Mongoose <mongoose@users.sourceforge.net>

	* Fixed animations using steping fix I wrote for libfreyja_egg
	  this breaks the old TR aniamtion hacks though  =)


## OpenRaider (0.0.3-20010612) Mongoose <mongoose@users.sourceforge.net>

	* Back porting to Freyja to help figure out TR animation problems
	* Worked on TR5 and TR4 texture alpha flags


## OpenRaider (0.0.3-20010611) Mongoose <mongoose@users.sourceforge.net>

	* Fixed skeletal/moveable loading and animation 
	* Starting entity mapping tracer


## OpenRaider (0.0.3-20010610) Mongoose <mongoose@users.sourceforge.net>

	* NOTE make enities list so dup models won't draw to same position
	* Caching caused segfault - so now emulate dumb smart pointers
	* Removed Free TR data, it caused to many segfaults,
	  for some reason it frees twice even with Clear()
	* Caching for duplicate models ( saves tons of memory )
	* Fixed loading and animation for all models in level
	* Broke animation with new loader?!  (caused by new moveable loading)
	* Free TR data after load ( May cause segfault on exit )
	* Simple vising for items back in
	* Oops, removed mesh draw from viewmodel renderer 
	  ( was debuging item meshes )
	* Fixed tr4 (2 layer tags) flag set on non lara models
	* Fixed moveable loading
	* Looking for moveable object drawing problems ( werid )
	* Fixed item positioning set on load
	* Fixed sprite/room amb lighting back to white ( heh, oops )


## OpenRaider (0.0.3-20010609) Mongoose <mongoose@users.sourceforge.net>

	* Void color only when outside world
	* Various minor renderer changes
	* Static mesh rendering fix (pad bad meshes with NULL meshes)
	* Fixed lara's colored polygons index bug for TR1
	* Autoload lara as view model
	* Tr4 two mesh system use
	* Basic skeletal model animation (frame rate based)
	* Skeletal model rendering
	* Skeletal model loader finished
	* No quaterions generated in current skeletal loader
	  It'll be easy to add bone lerping later, but first I want
	  correct behavior ( ie animation and placement )


## OpenRaider (0.0.3-20010608) Mongoose <mongoose@users.sourceforge.net>

	* Planning rendering engine #3 
	* Once skeletal models are in rendering engine #2 
	  physics code can start
	* EXPERIMENTAL moveable code starts


## OpenRaider (0.0.3-20010607) Mongoose <mongoose@users.sourceforge.net>

	* Moveable code finaling coming back in ( now with quats )
	* Bug fix to ignore bad meshes in some TR4 levels?
	* TombRaider class test
	* Some TR5 specs fell in my lap today  =)


## OpenRaider (0.0.3-20010606) Mongoose <mongoose@users.sourceforge.net>

	* Mouse motion control fixes
	* Item sprite rendering ( TR1, TR2, and should work for others )
	* Item sprite loading ( TR1, TR2, and should work for others )
	* Fixed room sprite loading
	* Hack temp fixes for camera ( broke it bad last night )


## OpenRaider (0.0.3-20010605) Mongoose <mongoose@users.sourceforge.net>

	* Baisc strafing and better forward/backward movement on camera 
	* More user documentation and bug tracking
	* Portal toggle
	* Fixed TR4 crash on -1 mesh light flag; can't alloc -1 objects  =)


## OpenRaider (0.0.3-20010604) Mongoose <mongoose@users.sourceforge.net>

	* Mouse look code
	* The portal code is hindered by the old XZ vis check  =(
	  once it's replaced it should be 100% correct
	* Added portal code, and is almost fully working now
	* Worked on portal code (testing)
	* Since adding quaternion camera, segfault on exit... hhmmm...
	* Finished quaternion based camera and rendering
	* Planning to break mtk3d into base type classes and expand it as
	  a library with learping functions for use in animation also  =)
	* Started on quaternion camera and quaternion support in mtk3d
	* TR4 sound fx postioning loader starts
	* GL driver string from resource


## OpenRaider (0.0.3-20010603) Mongoose <mongoose@users.sourceforge.net>

	* OpenGL fixes ( hopefully fixes radeon 'lineloop' bug )
	* SDL key code fixes
	* More SDL fixes for rendering
	* More SDL work, fixes
	* FPS counter prints to console every 100 frames


## OpenRaider (0.0.3-20010602) Mongoose <mongoose@users.sourceforge.net>

	* SDL is very slow atm ( drag ass )
	  You can edit Makefile to set it to use it if you want
	* Finished basic test SDL interface
	* Started on item sprite loading (likes a little more, but not priority)
	* Aren't you all gald I ditched render engine #1 now?  ;)
	* New sprite rendering code
	* Fixed bug that drew static room meshes twice
	* Fixed bug that drew alpha sorted tris 3 times
	  (Fixes all known alpha rendering bugs)
	* Room sprite loading code
	* Cleaned code, fixed some documentation
	* Started work on Resource agent, not ready to replace old code yet
	* No longer dump textures, unless explictly set in rc file


## OpenRaider (0.0.3-20010531) Mongoose <mongoose@users.sourceforge.net>

	* Fixed XEmacs modes should have been 'Mode: C++'
	* Looked at portal design guide, was useless
	* Added texel adjust fix to meshes ( fixes 1 pixel off alignment )


## OpenRaider (0.0.3-20010530) Mongoose <mongoose@users.sourceforge.net>

	* SDL support starts back
	* Added my old linux joystick code
	* Basic sorted alpha poly render second pass with very small penalty
	  ( An all new rendering feature never in engine before )
	* Figured out best way to sort alpha polys exp with rooms only for now
	* SkyMesh support ( rendering/identifing ) for TR2 and TR3
	* Static mesh rendering back ( doesn't use room lighting 
	  intensity for now )
	* Texel alignment


## OpenRaider (0.0.3-20010529) Mongoose <mongoose@users.sourceforge.net>

	* Static meshes
	* Model meshes
	* Mipmaps in Texture as option
	* Code clean up
	* Item sprite and room sprite loader code about finished
	* Finished adding my screenshot code from Freyja, and
	  made it produce TGAs instead of PPMs ( cmd 'S' )


## OpenRaider (0.0.3-20010528) Mongoose <mongoose@users.sourceforge.net>

	* POublic CVS Release 
	* Vertex lighting now functional and stable in new engine
	* Fix for TR4 water alpha via textile generator, but
	  some light shards are still black - might be other
	  alpha flags that are unknown
	* New level loader using _map_list
	* New Map list RC rule
	* Start of item sprite code in new engine
	* Leaving old Texture calls for compaiblity with obsolete
	* New textile loading by moving new code into Freyja's
	  TombRaider module to handle *all pixmap generation
	* User documentation


## OpenRaider (0.0.3-20010527) Mongoose <mongoose@users.sourceforge.net>

	* Testing
	* Resource system back in
	* AL init threaded off
	* Switched order of AL and GL inits 
	  ( so you can have in game progess loader for loading )


## OpenRaider (0.0.3-20010526) Mongoose <mongoose@users.sourceforge.net>

	* Should have all the best of the engines merged by Monday!
	* Started model rendering code for engine #2
	* New mode control for WIREFRAME, SOLID, TEXTURE
	* Fixed texel index bug for rooms
	* New Camera methods for visibility and more accessors
	* Render engine #2 feature upgrade by merging with engine #1


## OpenRaider (0.0.3-20010525) Mongoose <mongoose@users.sourceforge.net>

	* Rendering engine #2 fixes
	* New Camera method for positioning
	* Rendering engine #2 update
	* Added documentation to Sound agent


## OpenRaider (0.0.3-20010524) Mongoose <mongoose@users.sourceforge.net>

	* Texture manager fixes
	* Tesselated quads
	* Removed dependence on libmtk_gl ( my GL tool kit for my 3d modeler ) 
	* Moved 16bit ARGB -> 32bit RGBA texture util to TombRaider loader


## OpenRaider (0.0.2-20010523) Mongoose <mongoose@users.sourceforge.net>

	* Render fixes
	* OpenAL fixes for /dev/dsp in use and _init guard
	* Added Sound manager, OpenAL support for groovy 3d audio  =)
	* Dropped all OSS code
	* Fixed segfault by freeing _texture and _tombraider twice
	* TR4 texture fixes ported from gegg
	* Fixed segfault on texture handling
	* Removed splash screen code completely
	  ( Will later use loader screens just like TR )


## OpenRaider (0.0.2-20010522) Mongoose <mongoose@users.sourceforge.net>

	* Splash screen as compile time support
	* PThread support as compile time option
	* TR4 texel loading fixes


## OpenRaider (0.0.2-20010521) Mongoose <mongoose@users.sourceforge.net>

	* OpenRaider request for sourceforge hosting
	* New Render class is now the new renderer
	* GLUT use abstracted and placed into openraider.cpp
	* Mtk Image manager
	* Mtk texture manager
	* Thread for Freyja loader 
	* Freyja camera
	* OpenRaider RC system design
	* Freyja loader replaces yuri loader in test build
	* Splash screen
	* New engine starts


## OpenRaider (0.0.2-20010520) Mongoose <mongoose@users.sourceforge.net>

	* Removed drawing another lara as an error marker for movables
	* Removed level dumping and saving
	* Split up mesh rendering
	* New 3rd person lara camera rendering
	* New animation control
	* This project is based on trueview by yuri and some patches 
	  and porting to linux by Mongoose along with code from 
	  GooseEgg by Mongoose
	* Log started