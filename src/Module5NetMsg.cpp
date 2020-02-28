#include "NetMsgCreateWO.h"
#ifdef AFTR_CONFIG_USE_BOOST

#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "Module5NetMsg.h"
#include "GLViewNewModule.h"

using namespace Aftr;

NetMsgMacroDefinition(Module5NetMsg);

Module5NetMsg::Module5NetMsg()
{

}

Module5NetMsg::~Module5NetMsg()
{
}

//need to write
bool Module5NetMsg::toStream(NetMessengerStreamBuffer& os) const
{
	return true;
}

//need to write
bool Module5NetMsg::fromStream(NetMessengerStreamBuffer& is)
{
	return true;
}

//need to write
void Module5NetMsg::onMessageArrived()
{

	GLViewNewModule* glView = ((GLViewNewModule*)ManagerGLView::getGLView());
	
	glView->createSphere();

}

//need to write
std::string Module5NetMsg::toString() const
{
	std::stringstream ss;

	ss << NetMsg::toString();
	ss << "Sent payload" << std::endl;
	return ss.str();
}

#endif