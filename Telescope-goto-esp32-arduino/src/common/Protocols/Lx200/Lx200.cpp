#include "./Lx200.h"

Lx200::Lx200(Lx200RequestHandler &requestHandler): requestHandler(requestHandler){

}

std::vector<std::string> Lx200::extractComand(std::string rawMsg){
    std::vector<std::string> comands;
    bool colect = false;
    int comandCounter = 0;
    std::string comand = "";

    for (int i = 0; i < rawMsg.length(); i++){
        if(rawMsg[i] == 0x06){
            comands.push_back("ACK");
            return comands;
        }
    }

    for (int i = 0; i < rawMsg.length(); i++){
        if(rawMsg[i] == ':'){
            colect = true;
            comand = "";
            continue;
        }else if(rawMsg[i] == '#'){
            if(colect == true){
                colect = false;
                comandCounter++;
                comands.push_back(comand);
            }
        }
        if(colect == true){
            comand += rawMsg[i];
        }
    }
    return comands;
}

std::string Lx200::interpret(std::string msg){
    std::vector<std::string> comands = this->extractComand(msg);
    for (std::string comand : comands){
        if(comand == "ACK"){ // Query alignment status
            return "P";
        }else if(comand == "GR"){
            return  this->requestHandler.handle(Lx200Request::GR()).getBody();
        }else if(comand == "GD"){
            return  this->requestHandler.handle(Lx200Request::GD()).getBody();
        }else if(comand == "GVP"){ // Product Name
            return  this->requestHandler.handle(Lx200Request::GVP()).getBody();
        }else if(comand == "GVN"){ // Firmware version
            // return "1234#";
            return  this->requestHandler.handle(Lx200Request::GVN()).getBody();
        }else if(comand == "GVD"){ // Firmware Date
            // return "Oct 10 2020#";
            return  this->requestHandler.handle(Lx200Request::GVD()).getBody();
        }else if(comand == "GVT"){ // Firmware Time
            // return "11:10:00#";
            return  this->requestHandler.handle(Lx200Request::GVT()).getBody();
        }else if(comand == "Gg"){ // Current Site Longitude
            // return "+100*01:20#";
            return  this->requestHandler.handle(Lx200Request::Gg()).getBody();
        }else if(comand == "Gt"){ // Current Site Latitude
            // return "+100*01:20#";
            return  this->requestHandler.handle(Lx200Request::Gt()).getBody();
        }else if(comand == "GC"){ // Get local date
            // return "10/13/20#";
            return  this->requestHandler.handle(Lx200Request::GC()).getBody();
        }else if(comand == "GL"){ // Local Time in 24 hour format
            // return "11:21:10#";
            return  this->requestHandler.handle(Lx200Request::GL()).getBody();
        }else if(comand == "GG"){ // UTC offset time
            // return "+02.0#";
            return  this->requestHandler.handle(Lx200Request::GG()).getBody();
        }else if(comand == "D"){ // If slewing
            // return "#";
            return  this->requestHandler.handle(Lx200Request::D()).getBody();
        }else if(comand == "GW"){ // Get track state / mount type
            // return "PT2#";
            return  this->requestHandler.handle(Lx200Request::GW()).getBody();
        }
    }
}