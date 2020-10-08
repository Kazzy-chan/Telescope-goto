#include "Lx200Response.h"

std::string Lx200Response::getBody(){
    return this->body;
}

void Lx200Response::setBody(std::string body){
    this->body = body;
}
