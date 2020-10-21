#include "Telescope.h"

Telescope::Telescope(): looksAt(EquatorialCoordinates::polarStar()), currentPosition(Position::unknown()), currentDateTime(DateTime::unknown()){}

EquatorialCoordinates& Telescope::getLooksAt(){
    return this->looksAt;
}

Position& Telescope::getCurrentPosition(){
    return this->currentPosition;
}

DateTime& Telescope::getCurrentDateTime(){
    return this->currentDateTime;
}