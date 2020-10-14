#include "Lx200RequestHandler.h"

Lx200RequestHandler::Lx200RequestHandler(){
    
}

Lx200Response Lx200RequestHandler::handle(Lx200Request request){
    switch (request.getType()){
    case Lx200Requests::GD:
        return Lx200ResponseGD(true, 12, 15, 12);
    case Lx200Requests::GR:
        return Lx200ResponseGR(12,12,34);
    case Lx200Requests::GVP:
        return Lx200ResponseGVP("10micron GM4000HPS");
    default:
        break;
    }
}