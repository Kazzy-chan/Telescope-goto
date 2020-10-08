#include "BluetoothComunicationInterface.h"

BluetoothComunicationInterface::BluetoothComunicationInterface(BluetoothSerial& btSerial): btSerial(btSerial){}

BluetoothComunicationInterface::~BluetoothComunicationInterface(){}

bool BluetoothComunicationInterface::available(){
    return this->btSerial.available();
}

void BluetoothComunicationInterface::send(std::string send){
    this->btSerial.print(send.c_str());
}

std::string BluetoothComunicationInterface::recive(){
    return this->btSerial.readString().c_str();
}