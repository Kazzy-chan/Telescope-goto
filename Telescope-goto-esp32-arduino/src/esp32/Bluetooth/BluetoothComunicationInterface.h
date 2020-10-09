#ifndef __BluetoothComunicationInterface_h__
#define __BluetoothComunicationInterface_h__

#include <BluetoothSerial.h>
#include <string>
#include "../../common/Lx200/ComunicationInterface/ComunicationInterface.h"

class BluetoothComunicationInterface: public ComunicationInterface{
private:
    BluetoothSerial btSerial;
public:
    BluetoothComunicationInterface(std::string deviceName);
    ~BluetoothComunicationInterface();
    virtual bool available();
    virtual void write(std::string send);
    virtual std::string recive();
};

#endif