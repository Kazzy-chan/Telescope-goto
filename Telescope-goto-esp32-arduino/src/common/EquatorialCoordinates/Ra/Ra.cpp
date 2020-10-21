#include "Ra.h"

Ra::Ra(int hours, int minutes, int seconds): hours(hours), minutes(minutes), seconds(seconds){

}

//12:12:12
void Ra::update(std::string str){
    hours = atoi(str.substr(0,2).c_str());
    minutes = atoi(str.substr(3,2).c_str());
    seconds = atoi(str.substr(6,2).c_str());
}


std::string Ra::toString(){
    char buffer[24] = {};
    sprintf(buffer, "%i:%i:%i", hours, minutes, seconds); // todo if < 10 add 0
    return buffer;
};

//12:12:12
Ra Ra::fromString(std::string str){
    int hours = atoi(str.substr(0,2).c_str());
    int minutes = atoi(str.substr(3,2).c_str());
    int seconds = atoi(str.substr(6,2).c_str());

    return Ra(hours, minutes, seconds);
}