#ifndef __AppProtocol_h__
#define __AppProtocol_h__

#include "../IProtocol.h"
#include "./AppProtocolRequestHandler/AppProtocolRequestHandler.h"

class AppProtocol: public IProtocol{
private:
    AppProtocolRequestHandler &appProtocolRequestHandler;
public:
    AppProtocol(AppProtocolRequestHandler &appProtocolRequestHandler);
    std::string interpret(std::string msg);
};

#endif