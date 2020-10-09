#ifndef dev

#include <Arduino.h>
#include "./esp32/Bluetooth/BluetoothComunicationInterface.h"
#include "./common/Lx200/Lx200.h"
#include "./common/Lx200/Lx200Response/Lx200Response.h"
#include "./common/Lx200/Lx200Response/GD/Lx200ResponseGD.h"
#include "./common/Lx200/Lx200Response/GR/Lx200ResponseGR.h"

BluetoothComunicationInterface comunicationInterface("Teleskop GoTo");
Lx200 lx200(comunicationInterface);
bool isProtocolSelected = false;

Lx200Response interpreter(Lx200Request request);

void setup(){
    Serial.begin(115200);
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
            //Serial.println(buffer);
            if (buffer[0] == '#'){
                //Serial.println("Sending P");
                comunicationInterface.write("P");
                isProtocolSelected = true;
            }
        }
    }else{
        lx200.loop();
    }
}

#endif