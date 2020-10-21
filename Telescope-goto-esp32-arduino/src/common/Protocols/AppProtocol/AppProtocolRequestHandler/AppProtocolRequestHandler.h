#ifndef __AppProtocolRequestHandler_h__
#define __AppProtocolRequestHandler_h__


#include "../../../Telescope/Telescope.h"

#include "../AppProtocolRequest/AppProtocolRequest.h"

#include "../AppProtocolResponse/AppProtocolResponse.h"

#include "../AppProtocolRequest/Date/Date.h"
#include "../AppProtocolRequest/Time/Time.h"
#include "../AppProtocolRequest/UtcOffset/UtcOffset.h"
#include "../AppProtocolRequest/Latitude/Latitude.h"
#include "../AppProtocolRequest/Longitude/Longitude.h"
#include "../AppProtocolRequest/CalibrationDec/CalibrationDec.h"
#include "../AppProtocolRequest/CalibrationRa/CalibrationRa.h"
#include "../AppProtocolRequest/Move/Move.h"

class AppProtocolRequestHandler{
private:
    Telescope& telescope;

    AppProtocolResponse onTimeRequest(AppProtocolRequest*);
    AppProtocolResponse onDateRequest(AppProtocolRequest*);
    AppProtocolResponse onUtcOffsetRequest(AppProtocolRequest*);
    AppProtocolResponse onLatitudeRequest(AppProtocolRequest*);
    AppProtocolResponse onLongitudeRequest(AppProtocolRequest*);
    AppProtocolResponse onCalibrationDecRequest(AppProtocolRequest*);
    AppProtocolResponse onCalibrationRaRequest(AppProtocolRequest*);
    AppProtocolResponse onMoveRequest(AppProtocolRequest*);

public:
    AppProtocolRequestHandler(Telescope& telescope);
    AppProtocolResponse handle(AppProtocolRequest*);


};

#endif