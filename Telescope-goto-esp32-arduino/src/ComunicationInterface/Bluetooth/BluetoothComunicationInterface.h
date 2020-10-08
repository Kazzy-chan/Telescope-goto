#ifndef __BluetoothComunicationInterface_h__
#define __BluetoothComunicationInterface_h__

#include <BluetoothSerial.h>
#include <string>
#include "../ComunicationInterface.h"

class BluetoothComunicationInterface: public ComunicationInterface{
private:
    BluetoothSerial& btSerial;
public:
    BluetoothComunicationInterface(BluetoothSerial& btSerial);
    ~BluetoothComunicationInterface();
    virtual bool available();
    virtual void send(std::string send);
    virtual std::string recive();
};

#endif