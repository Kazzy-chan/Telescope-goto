#include "Lx200Response.h"

String Lx200Response::getBody(){
    return this->body;
}

void Lx200Response::setBody(String body){
    this->body = body;
}
