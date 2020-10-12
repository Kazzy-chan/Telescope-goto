#include "./esp32/Bluetooth/BluetoothComunicationInterface.h"
#include "../common/Protocols/ProtocolsManager.h"

#include "../common/Protocols/Lx200/Lx200RequestHandler/Lx200RequestHandler.h"
#include "../common/Protocols/Lx200/Lx200.h"

#include "../common/Protocols/AppProtocol/AppProtocol.h"
#include "../common/Protocols/AppProtocol/AppProtocolRequestHandler/AppProtocolRequestHandler.h"

#include "../common/Protocols/StellariumProtocolSelector/StellariumProtocolSelector.h"


BluetoothComunicationInterface comunicationInterface;

Lx200RequestHandler lx200RequestHandler;
AppProtocolRequestHandler appProtocolRequestHandler;

Lx200 lx200(lx200RequestHandler);
AppProtocol appProtocol(appProtocolRequestHandler);
StellariumProtocolSelector stellariumProtocolSelector;

ProtocolsManager protocolsManager(comunicationInterface, appProtocol, stellariumProtocolSelector, lx200);
bool isProtocolSelected = false;

void setup(){
    comunicationInterface.init("Teleskop GoTo");
}

void loop(){
    protocolsManager.loop();
}

