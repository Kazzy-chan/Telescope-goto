#include "./Lx200.h"

Lx200::Lx200(Lx200RequestHandler &requestHandler): requestHandler(requestHandler){

}

std::string Lx200::interpret(std::string msg){
    Lx200Response response;
    if(msg == ":GR#"){
        response = this->requestHandler.handle(Lx200RequestGR());
    }else if(msg == ":GD#"){
        response = this->requestHandler.handle(Lx200RequestGD());
    }
    return response.getBody();
}