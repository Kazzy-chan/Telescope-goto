#ifndef __Lx200RequestHandler_h__
#define __Lx200RequestHandler_h__

#include "../Lx200Response/Lx200Response.h"
#include "../Lx200Request/Lx200Request.h"

#include "../Lx200Response/GD/Lx200ResponseGD.h"
#include "../Lx200Response/GR/Lx200ResponseGR.h"

class Lx200RequestHandler{
public:
    Lx200RequestHandler();
    Lx200Response handle(Lx200Request);
};

#endif