#include "../common/Logger.h"

#include <Arduino.h>

Logger logger;

Logger::Logger(){
    Serial.begin(115200);
}

void Logger::LOG_I(std::string tag, std::string msg){
    Serial.printf("%s: %s\n", tag, msg);
}

void Logger::LOG_E(std::string tag, std::string msg){
    //todo error log
}