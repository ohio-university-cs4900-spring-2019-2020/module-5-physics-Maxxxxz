#pragma once

#include "NetMsg.h"
#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr
{

	class Module5NetMsg : public NetMsg
	{
	public:
		NetMsgMacroDeclaration(Module5NetMsg);

		Module5NetMsg();
		virtual ~Module5NetMsg();
		virtual bool toStream(NetMessengerStreamBuffer& os) const;
		virtual bool fromStream(NetMessengerStreamBuffer& is);
		virtual void onMessageArrived();
		virtual std::string toString() const;
	};
}
#endif