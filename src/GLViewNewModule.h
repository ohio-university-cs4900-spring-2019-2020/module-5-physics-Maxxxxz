#pragma once

#include "GLView.h"
#include "PxPhysicsAPI.h"
#include "extensions/PxDefaultAllocator.h"
#include "extensions/PxDefaultErrorCallback.h"
#include "PxFoundation.h"
#include "NetMessengerClient.h"
using namespace physx;	//lazy
namespace Aftr
{
   class Camera;

/**
   \class GLViewNewModule
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewNewModule : public GLView
{
public:
   static GLViewNewModule* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewNewModule();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createNewModuleWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   void createSphere();
protected:
   GLViewNewModule( const std::vector< std::string >& args );
   virtual void onCreate();   
   void createFloor();
private:
	WO* floor;
   PxDefaultAllocator a;
   PxDefaultErrorCallback e;
   PxFoundation* f;// = PxCreateFoundation(PX_PHYSICS_VERSION, a, e);
   PxPhysics* p;// = PxCreatePhysics(PX_PHYSICS_VERSION, *f, PxTolerancesScale(), true, NULL);
   PxScene* scene;
   PxPvd* gPvd;
   PxDefaultCpuDispatcher* d;
   int r;
   NetMessengerClient* client;

};

/** \} */

} //namespace Aftr
