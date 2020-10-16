#include "AppProtocolRequestHandler.h"

AppProtocolRequestHandler::AppProtocolRequestHandler(AppDataTimeDateLocation& appDataTimeDateLocation): appDataTimeDateLocation(appDataTimeDateLocation){
};

AppProtocolResponse AppProtocolRequestHandler::handle(AppProtocolRequest* request){
    switch (request->getType()){
    case AppProtocolRequests::Date:{
        AppRequests::Date* date = dynamic_cast<AppRequests::Date*>(request);
        this->appDataTimeDateLocation.setDate(date->getRawData());
        return AppProtocolResponse::ok();
       } break;
    case AppProtocolRequests::Time:{
        AppRequests::Time* time = dynamic_cast<AppRequests::Time*>(request);
        this->appDataTimeDateLocation.setTime(time->getRawData());
        return AppProtocolResponse::ok();
        }break;
    case AppProtocolRequests::UtcOffset:{
        AppRequests::UtcOffset* utcOffset = dynamic_cast<AppRequests::UtcOffset*>(request);
        this->appDataTimeDateLocation.setUtcOffset(utcOffset->getRawData());
        return AppProtocolResponse::ok();
       } break;
    case AppProtocolRequests::Latitude:{
        AppRequests::Latitude* latitude = dynamic_cast<AppRequests::Latitude*>(request);
        this->appDataTimeDateLocation.setLatitude(latitude->getRawData());
        return AppProtocolResponse::ok();
        }break;
    case AppProtocolRequests::Longitude:{
        AppRequests::Longitude* longitude = dynamic_cast<AppRequests::Longitude*>(request);
        this->appDataTimeDateLocation.setLongitude(longitude->getRawData());
        return AppProtocolResponse::ok();
        }break;
    }
}