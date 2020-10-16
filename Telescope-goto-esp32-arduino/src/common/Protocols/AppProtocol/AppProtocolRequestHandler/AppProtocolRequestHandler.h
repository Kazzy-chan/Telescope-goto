#ifndef __AppProtocolRequestHandler_h__
#define __AppProtocolRequestHandler_h__


#include "../../../AppData/TimeDateLocation/AppDataTimeDateLocation.h"

#include "../AppProtocolRequest/AppProtocolRequest.h"

#include "../AppProtocolResponse/AppProtocolResponse.h"

#include "../AppProtocolRequest/Date/Date.h"
#include "../AppProtocolRequest/Time/Time.h"
#include "../AppProtocolRequest/UtcOffset/UtcOffset.h"
#include "../AppProtocolRequest/Latitude/Latitude.h"
#include "../AppProtocolRequest/Longitude/Longitude.h"

class AppProtocolRequestHandler{
private:
    AppDataTimeDateLocation& appDataTimeDateLocation;
public:
    AppProtocolRequestHandler(AppDataTimeDateLocation& appDataTimeDateLocation);
    AppProtocolResponse handle(AppProtocolRequest*);
};

#endif