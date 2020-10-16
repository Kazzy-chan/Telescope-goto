#ifndef __Lx200RequestHandler_h__
#define __Lx200RequestHandler_h__

#include "../../../AppData/TimeDateLocation/AppDataTimeDateLocation.h"

#include "../Lx200Response/Lx200Response.h"
#include "../Lx200Request/Lx200Request.h"

class Lx200RequestHandler{
private:
    AppDataTimeDateLocation& appDataTimeDateLocation;
public:
    Lx200RequestHandler(AppDataTimeDateLocation& appDataTimeDateLocation);
    Lx200Response handle(Lx200Request);
};

#endif