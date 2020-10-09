#include "BluetoothComunicationInterface.h"

BluetoothComunicationInterface::BluetoothComunicationInterface(std::string deviceName){
    this->btSerial.begin(deviceName.c_str());
}

BluetoothComunicationInterface::~BluetoothComunicationInterface(){}

bool BluetoothComunicationInterface::available(){
    return this->btSerial.available();
}

void BluetoothComunicationInterface::write(std::string send){
    this->btSerial.print(send.c_str());
}

std::string BluetoothComunicationInterface::recive(){
    return this->btSerial.readString().c_str();
}