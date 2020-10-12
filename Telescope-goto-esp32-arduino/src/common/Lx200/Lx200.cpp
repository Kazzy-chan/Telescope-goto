#include "./Lx200.h"

Lx200::Lx200(ComunicationInterface &comunicationInterface):comunicationInterface(comunicationInterface){

}

void Lx200::registerCallback(Lx200Response (&callback)(Lx200Request)){
    this->callback = callback;
}

void Lx200::loop(){
    if(this->comunicationInterface.available()){
        std::string buffer = this->comunicationInterface.recive();
        logger.LOG_I("=>", buffer);
        if(buffer[buffer.length() - 1] == '#'){
            Lx200Response response;
            if(buffer == ":GR#"){
                response = this->callback(Lx200RequestGR());
            }else if(buffer == ":GD#"){
                response = this->callback(Lx200RequestGD());
            }
            logger.LOG_I("<=", response.getBody());
            comunicationInterface.write(response.getBody());
        }
    }
}