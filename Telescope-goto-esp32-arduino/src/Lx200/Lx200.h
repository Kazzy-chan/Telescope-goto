#ifndef __LX200_h__
#define __LX200_h__

#include "../ComunicationInterface/ComunicationInterface.h"
#include "./Lx200Request/Lx200Requests.h"
#include "./Lx200Request/Lx200Request.h"
#include "./Lx200Request/GD/Lx200RequestGD.h"
#include "./Lx200Request/GR/Lx200RequestGR.h"
#include "./Lx200Response/Lx200Response.h"


class Lx200{
private:
    ComunicationInterface &comunicationInterface;
    Lx200Response (*callback)(Lx200Request);
    
public:
    Lx200(ComunicationInterface &comunicationInterface);
    void loop();
    void registerCallback(Lx200Response (&callback)(Lx200Request));
};



#endif
