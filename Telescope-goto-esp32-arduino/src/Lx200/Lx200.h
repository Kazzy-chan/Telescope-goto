#ifndef __LX200_h__
#define __LX200_h__

#include "./Lx200Request/Lx200Requests.h"
#include "./Lx200Request/Lx200Request.h"
#include "./Lx200Request/GD/Lx200RequestGD.h"
#include "./Lx200Request/GR/Lx200RequestGR.h"
#include "./Lx200Response/Lx200Response.h"
#include "BluetoothSerial.h"


class Lx200{
private:
    BluetoothSerial &btSerial;
    Lx200Response (*callback)(Lx200Request);
    
public:
    Lx200(BluetoothSerial &btSerial);
    void loop();
    void registerCallback(Lx200Response (&callback)(Lx200Request));
};



#endif __LX200_h__
