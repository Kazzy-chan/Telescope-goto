#ifndef __Lx200RequestHandler_h__
#define __Lx200RequestHandler_h__

#include "../../../AppData/TimeDateLocation/AppDataTimeDateLocation.h"

#include "../Lx200Response/Lx200Response.h"
#include "../Lx200Request/Lx200Request.h"

#include "../Lx200Response/GD/Lx200ResponseGD.h"
#include "../Lx200Response/GR/Lx200ResponseGR.h"
#include "../Lx200Response/GVP/Lx200ResponseGVP.h"

class Lx200RequestHandler{
private:
    AppDataTimeDateLocation& appDataTimeDateLocation;
public:
    Lx200RequestHandler(AppDataTimeDateLocation& appDataTimeDateLocation);
    Lx200Response handle(Lx200Request);
};

#endif