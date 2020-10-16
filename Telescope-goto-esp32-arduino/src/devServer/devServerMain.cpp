#include "TcpServer/TcpServer.h"
#include "../common/Protocols/ProtocolsManager.h"

#include "../common/AppData/TimeDateLocation/AppDataTimeDateLocation.h"

#include "../common/Protocols/Lx200/Lx200RequestHandler/Lx200RequestHandler.h"
#include "../common/Protocols/Lx200/Lx200.h"

#include "../common/Protocols/AppProtocol/AppProtocol.h"
#include "../common/Protocols/AppProtocol/AppProtocolRequestHandler/AppProtocolRequestHandler.h"

#include "../common/Protocols/StellariumProtocolSelector/StellariumProtocolSelector.h"


TcpServer comunicationInterface;

AppDataTimeDateLocation appDataTimeDateLocation;

Lx200RequestHandler lx200RequestHandler(appDataTimeDateLocation);
AppProtocolRequestHandler appProtocolRequestHandler(appDataTimeDateLocation);

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

