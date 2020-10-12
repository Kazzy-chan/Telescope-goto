#include "TcpServer/TcpServer.h"
#include "../common/Logger.h"
#include "../common/Protocols/ProtocolsManager.h"

#include "../common/Protocols/Lx200/Lx200Response/GD/Lx200ResponseGD.h"
#include "../common/Protocols/Lx200/Lx200Response/GR/Lx200ResponseGR.h"

TcpServer comunicationInterface;
ProtocolsManager protocolsManager(comunicationInterface);
bool isProtocolSelected = false;

Lx200Response interpreter(Lx200Request request);

void setup(){
    comunicationInterface.init();
    protocolsManager.registerCallbackLx200(interpreter);
}

Lx200Response interpreter(Lx200Request request){

    switch (request.getType()){
    case Lx200Requests::GD:
        return Lx200ResponseGD(true, 12, 15, 12);
    case Lx200Requests::GR:
        return Lx200ResponseGR(12,12,34);
    default:
        break;
    }
    
}

void loop(){
    protocolsManager.loop();
}
