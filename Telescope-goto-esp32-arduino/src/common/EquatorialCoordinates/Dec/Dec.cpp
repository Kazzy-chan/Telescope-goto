#include "Dec.h"
    
    
Dec::Dec(char sign, int degrees, int arcminutes, int arcseconds): sign(sign), degrees(degrees), arcminutes(arcminutes), arcseconds(arcseconds){}

//-22*27:57
void Dec::update(std::string str){
    sign = str[0];
    degrees = atoi(str.substr(1, 2).c_str());
    arcminutes = atoi(str.substr(4, 2).c_str());
    arcseconds = atoi(str.substr(7, 2).c_str());
}


std::string Dec::toString(){
    char buffer[24] = {};
    sprintf(buffer, "%c%i*%i:%i", sign, degrees, arcminutes, arcseconds); // todo if < 10 add 0
    return buffer;
}

//-22*27:57
Dec Dec::fromString(std::string str){
    char sign = str[0];
    int degrees = atoi(str.substr(1, 2).c_str());
    int arcminutes = atoi(str.substr(4, 2).c_str());
    int arcseconds = atoi(str.substr(7, 2).c_str());

    return Dec(sign, degrees, arcminutes, arcseconds);
}