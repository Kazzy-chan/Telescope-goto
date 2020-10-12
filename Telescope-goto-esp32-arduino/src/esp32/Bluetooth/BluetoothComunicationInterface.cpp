#include "BluetoothComunicationInterface.h"


BluetoothComunicationInterface::BluetoothComunicationInterface(){}

void BluetoothComunicationInterface::init(std::string deviceName){
    btSerial.begin(deviceName.c_str());
}

BluetoothComunicationInterface::~BluetoothComunicationInterface(){}

bool BluetoothComunicationInterface::available(){
    return btSerial.available();
}

void BluetoothComunicationInterface::write(std::string send){
    btSerial.print(send.c_str());
}

std::string BluetoothComunicationInterface::recive(){
    return btSerial.readString().c_str();
}