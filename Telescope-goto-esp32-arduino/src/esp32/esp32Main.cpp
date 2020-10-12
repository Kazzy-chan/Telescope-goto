#include <Arduino.h>
#include "./esp32/Bluetooth/BluetoothComunicationInterface.h"
#include "../common/Logger.h"
#include "../common/Lx200/Lx200.h"
#include "../common/Lx200/Lx200Response/Lx200Response.h"
#include "../common/Lx200/Lx200Response/GD/Lx200ResponseGD.h"
#include "../common/Lx200/Lx200Response/GR/Lx200ResponseGR.h"
#include "BluetoothSerial.h"

BluetoothComunicationInterface comunicationInterface;
Lx200 lx200(comunicationInterface);
bool isProtocolSelected = false;

Lx200Response interpreter(Lx200Request request);

void setup(){
    comunicationInterface.init("Teleskop GoTo");
    lx200.registerCallback(interpreter);
}

Lx200Response interpreter(Lx200Request request){

    switch (request.getType()){
    case Lx200Requests::GD:
        return Lx200ResponseGD(true, 12, 15, 12);
    case Lx200Requests::GR:
        return Lx200ResponseGR(12,12,34);
    default:
        break;
    }
    
}

void loop(){
    if (!isProtocolSelected){
        if (comunicationInterface.available()){
            std::string buffer = comunicationInterface.recive();
            logger.LOG_I("=>", buffer.c_str());
            if (buffer[0] == '#'){
                comunicationInterface.write("P");
                logger.LOG_I("<=", "P");
                isProtocolSelected = true;
            }
        }
    }else{  
        lx200.loop();
    }
}

