#include "./Lx200.h"

Lx200::Lx200(ComunicationInterface &comunicationInterface):comunicationInterface(comunicationInterface){

}

void Lx200::registerCallback(Lx200Response (&callback)(Lx200Request)){
    this->callback = callback;
}

void Lx200::loop(){
    if(this->comunicationInterface.available()){
        std::string buffer = this->comunicationInterface.recive();
        if(buffer[buffer.length() - 1] == '#'){
            if(buffer == ":GR#"){
                comunicationInterface.write(this->callback(Lx200RequestGR()).getBody());
            }else if(buffer == ":GD#"){
                comunicationInterface.write(this->callback(Lx200RequestGD()).getBody());
            }
        }
    }
}