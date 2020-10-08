#include "Lx200ResponseGD.h"

Lx200ResponseGD::Lx200ResponseGD(bool isPositive, int degree, int arcMinutes, int arcSeconds){
    char buffer[24] = {};
    sprintf(buffer, "%c%i*%i:%i#", isPositive? '+': '-', degree, arcMinutes, arcSeconds);
    this->setBody(buffer);
};
