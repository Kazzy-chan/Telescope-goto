#include "AppDataTimeDateLocation.h"

AppDataTimeDateLocation::AppDataTimeDateLocation(){
    this->time = "";
    this->date = "";
    this->utcOffset = "";
    this->latitude = "";
    this->longitude = "";
}

void AppDataTimeDateLocation::setTime(std::string time){
    this->time = time;
    logger.LOG_I("TEst", time);
}
void AppDataTimeDateLocation::setDate(std::string date){
    this->date = date;
    logger.LOG_I("TEst", date);
}
void AppDataTimeDateLocation::setUtcOffset(std::string utcOffset){
    this->utcOffset = utcOffset;
    logger.LOG_I("TEst", utcOffset);
}
void AppDataTimeDateLocation::setLatitude(std::string latitude){
    this->latitude = latitude;
    logger.LOG_I("TEst", latitude);
}
void AppDataTimeDateLocation::setLongitude(std::string longitude){
    this->longitude = longitude;
    logger.LOG_I("TEst", longitude);
}

std::string AppDataTimeDateLocation::getTime(){
    return this->time;
}

std::string AppDataTimeDateLocation::getDate(){
    return this->date;
}

std::string AppDataTimeDateLocation::getUtcOffset(){
    return this->utcOffset;
}

std::string AppDataTimeDateLocation::getLatitude(){
    return this->latitude;
}

std::string AppDataTimeDateLocation::getLongitude(){
    return this->longitude;
}