#include "EquatorialCoordinates.h"
#include "../Logger.h"

EquatorialCoordinates::EquatorialCoordinates(Ra ra, Dec dec): ra(ra), dec(dec){

}

EquatorialCoordinates EquatorialCoordinates::polarStar(){
    return EquatorialCoordinates(Ra::fromString("02:33:33"), Dec::fromString("+89*15:48"));
}

Ra EquatorialCoordinates::getRa(){
    return this->ra;
}

Dec EquatorialCoordinates::getDec(){
    return this->dec;
}

void EquatorialCoordinates::updateRa(Ra ra){
    this->ra = ra;
}

void EquatorialCoordinates::updateDec(Dec dec){
    this->dec = dec;
}