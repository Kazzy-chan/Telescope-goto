#ifndef __Telescope_h__
#define __Telescope_h__

#include <memory>
#include "../EquatorialCoordinates/EquatorialCoordinates.h"
#include "Position/Position.h"
#include "DateTime/DateTime.h"

class Telescope{
private:
    EquatorialCoordinates looksAt;
    Position currentPosition;
    DateTime currentDateTime;
public:
    Telescope();
    EquatorialCoordinates& getLooksAt();
    Position& getCurrentPosition();
    DateTime& getCurrentDateTime();
};



#endif