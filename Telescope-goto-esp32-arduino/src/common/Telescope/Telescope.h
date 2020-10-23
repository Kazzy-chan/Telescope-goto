#ifndef __Telescope_h__
#define __Telescope_h__

#include <memory>
#include "../EquatorialCoordinates/EquatorialCoordinates.h"
#include "Position/Position.h"
#include "DateTime/DateTime.h"
#include "Constraints/Constraints.h"

class Telescope{
private:
    EquatorialCoordinates looksAt;
    Position currentPosition;
    DateTime currentDateTime;
    Constraints motor1Constraints;
    Constraints motor2Constraints;
public:
    Telescope();
    EquatorialCoordinates& getLooksAt();
    Position& getCurrentPosition();
    DateTime& getCurrentDateTime();
    Constraints& getMotor1Constraints();
    Constraints& getMotor2Constraints();
};



#endif