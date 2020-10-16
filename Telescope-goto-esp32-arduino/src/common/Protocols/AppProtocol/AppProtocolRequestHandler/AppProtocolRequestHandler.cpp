#include "AppProtocolRequestHandler.h"

AppProtocolRequestHandler::AppProtocolRequestHandler(AppDataTimeDateLocation& appDataTimeDateLocation): appDataTimeDateLocation(appDataTimeDateLocation){};

AppProtocolResponse AppProtocolRequestHandler::handle(AppProtocolRequest* request){
    switch (request->getType()){
    case AppProtocolRequests::Date:
        return this->onDateRequest(request);
    case AppProtocolRequests::Time:
        return this->onTimeRequest(request);
    case AppProtocolRequests::UtcOffset:
        return this->onUtcOffsetRequest(request);
    case AppProtocolRequests::Latitude: 
        return this->onLatitudeRequest(request);
    case AppProtocolRequests::Longitude:
        return this->onLongitudeRequest(request);
    }
}

AppProtocolResponse AppProtocolRequestHandler::onTimeRequest(AppProtocolRequest* request){
    AppRequests::Time* time = dynamic_cast<AppRequests::Time*>(request);
    this->appDataTimeDateLocation.setTime(time->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onDateRequest(AppProtocolRequest* request){
    AppRequests::Date* date = dynamic_cast<AppRequests::Date*>(request);
    this->appDataTimeDateLocation.setDate(date->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onUtcOffsetRequest(AppProtocolRequest* request){
    AppRequests::UtcOffset* utcOffset = dynamic_cast<AppRequests::UtcOffset*>(request);
    this->appDataTimeDateLocation.setUtcOffset(utcOffset->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onLatitudeRequest(AppProtocolRequest* request){
    AppRequests::Latitude* latitude = dynamic_cast<AppRequests::Latitude*>(request);
    this->appDataTimeDateLocation.setLatitude(latitude->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onLongitudeRequest(AppProtocolRequest* request){
    AppRequests::Longitude* longitude = dynamic_cast<AppRequests::Longitude*>(request);
    this->appDataTimeDateLocation.setLongitude(longitude->getRawData());
    return AppProtocolResponse::ok();
}