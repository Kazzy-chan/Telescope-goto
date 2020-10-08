#include "Lx200ResponseGR.h"

Lx200ResponseGR::Lx200ResponseGR(int hours, int minutes, int seconds){
    char buffer[24] = {};
    sprintf(buffer, "%i:%i:%i#", hours, minutes, seconds);
    this->setBody(buffer);
};


