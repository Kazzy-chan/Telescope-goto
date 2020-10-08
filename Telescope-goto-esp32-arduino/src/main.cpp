#include <Arduino.h>
#include "./Lx200/Lx200.h"
#include "./Lx200/Lx200Response/Lx200Response.h"
#include "./Lx200/Lx200Response/GD/Lx200ResponseGD.h"
#include "./Lx200/Lx200Response/GR/Lx200ResponseGR.h"
#include "BluetoothSerial.h"

BluetoothSerial btSerial;
Lx200 lx200(btSerial);
bool isProtocolSelected = false;

Lx200Response interpreter(Lx200Request request);

void setup(){
    Serial.begin(115200);
    btSerial.begin("Teleskop GoTo");
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
        if (btSerial.available()){
            String buffer = btSerial.readString();
            Serial.println(buffer);
            if (buffer[0] == '#'){
                Serial.println("Sending P");
                btSerial.printf("P");
                isProtocolSelected = true;
            }
        }
    }else{
        lx200.loop();
    }
    // put your main code here, to run repeatedly:
}