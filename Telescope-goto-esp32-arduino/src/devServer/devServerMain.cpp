#include "TcpServer/TcpServer.h"
#include "../common/Protocols/ProtocolsManager.h"

#include "../common/Telescope/Telescope.h"

#include "../common/Protocols/Lx200/Lx200RequestHandler/Lx200RequestHandler.h"
#include "../common/Protocols/Lx200/Lx200.h"

#include "../common/Protocols/AppProtocol/AppProtocol.h"
#include "../common/Protocols/AppProtocol/AppProtocolRequestHandler/AppProtocolRequestHandler.h"

#include "../common/Protocols/StellariumProtocolSelector/StellariumProtocolSelector.h"


TcpServer comunicationInterface;

Telescope telescope;

Lx200RequestHandler lx200RequestHandler(telescope);
AppProtocolRequestHandler appProtocolRequestHandler(telescope);

Lx200 lx200(lx200RequestHandler);
AppProtocol appProtocol(appProtocolRequestHandler);
StellariumProtocolSelector stellariumProtocolSelector;

ProtocolsManager protocolsManager(comunicationInterface, appProtocol, stellariumProtocolSelector, lx200);
bool isProtocolSelected = false;

void setup(){
    comunicationInterface.init();
}

void loop(){
    protocolsManager.loop();
    
}
