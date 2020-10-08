#include "./Lx200.h"

Lx200::Lx200(BluetoothSerial &btSerial):btSerial(btSerial){

}

void Lx200::registerCallback(Lx200Response (&callback)(Lx200Request)){
    this->callback = callback;
}

void Lx200::loop(){
    if(this->btSerial.available()){
        String buffer = btSerial.readString();
        Serial.println(buffer);
        if(buffer[buffer.length() - 1] == '#'){
            if(buffer == ":GR#"){
                Serial.print(this->callback(Lx200RequestGR()).getBody());
                btSerial.print(this->callback(Lx200RequestGR()).getBody());
            }else if(buffer == ":GD#"){
                Serial.print(this->callback(Lx200RequestGD()).getBody());
                btSerial.print(this->callback(Lx200RequestGD()).getBody());
            }
        }
    }
}