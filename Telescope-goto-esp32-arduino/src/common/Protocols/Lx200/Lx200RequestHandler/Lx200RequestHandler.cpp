#include "Lx200RequestHandler.h"

Lx200RequestHandler::Lx200RequestHandler(AppDataTimeDateLocation& appDataTimeDateLocation): appDataTimeDateLocation(appDataTimeDateLocation){
}

Lx200Response Lx200RequestHandler::handle(Lx200Request request){ // todo cases in eigene methoden auslagern 
    switch (request.getType()){
    case Lx200Requests::GD:
        return Lx200Response::GD(true, 12, 15, 12);
    case Lx200Requests::GR:
        return Lx200Response::GR(12,12,34);
    case Lx200Requests::GVP:
        return Lx200Response::GVP("10micron GM4000HPS");
    case Lx200Requests::GVN:
        return Lx200Response::GVN("1234");
    case Lx200Requests::GVD:
        return Lx200Response::GVD("Oct 10 2020");
    case Lx200Requests::GVT:
        return Lx200Response::GVT("11:10:00");
    case Lx200Requests::Gg:
        if(appDataTimeDateLocation.getLongitude().empty() == false){
            return Lx200Response(appDataTimeDateLocation.getLongitude());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::Gt:
        if(appDataTimeDateLocation.getLatitude().empty() == false){
            return Lx200Response(appDataTimeDateLocation.getLatitude());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::GC:
        if(appDataTimeDateLocation.getDate().empty() == false){
            return Lx200Response(appDataTimeDateLocation.getDate());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::GL:
        if(appDataTimeDateLocation.getTime().empty() == false){
            return Lx200Response(appDataTimeDateLocation.getTime());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::GG:
        if(appDataTimeDateLocation.getUtcOffset().empty() == false){
            return Lx200Response(appDataTimeDateLocation.getUtcOffset());
        }else{
           return Lx200Response::null(); 
        }
    case Lx200Requests::D:
        return Lx200Response::D("#");
    case Lx200Requests::GW:
        return Lx200Response::GW("PT1");
    default:
        return Lx200Response::null();
        break;
    }
}