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

Constraints& Telescope::getMotor1Constraints(){
    return this->motor1Constraints;
}

Constraints& Telescope::getMotor2Constraints(){
    return this->motor2Constraints;
}