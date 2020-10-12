#include "AppProtocol.h"

AppProtocol::AppProtocol(AppProtocolRequestHandler &appProtocolRequestHandler): appProtocolRequestHandler(appProtocolRequestHandler){

}

std::string AppProtocol::interpret(std::string msg){
    return "";
}