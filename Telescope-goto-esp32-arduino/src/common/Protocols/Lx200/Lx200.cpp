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
    Lx200Response response;
    std::vector<std::string> comands = this->extractComand(msg);
    for (std::string comand : comands){
        if(comand == "ACK"){ // Query alignment status
            return "P";
        }else if(comand == "GR"){
            response = this->requestHandler.handle(Lx200RequestGR());
        }else if(comand == "GD"){
            response = this->requestHandler.handle(Lx200RequestGD());
        }else if(comand == "GVP"){ // Product Name
            response = this->requestHandler.handle(Lx200RequestGVP());
        }else if(comand == "GVN"){ // Firmware version
            return "1234#";
        }else if(comand == "GVD"){ // Firmware Date
            return "Oct 10 2020#";
        }else if(comand == "GVT"){ // Firmware Time
            return "11:10:00#";
        }else if(comand == "Gg"){ // Current Site Longitude
            return "+100*01:20#";
        }else if(comand == "Gt"){ // Current Site Latitude
            return "+100*01:20#";
        }else if(comand == "GC"){ // Get local date
            return "10/13/20#";
        }else if(comand == "GL"){ // Local Time in 24 hour format
            return "11:21:10#";
        }else if(comand == "GG"){ // UTC offset time
            return "+02.0#";
        }else if(comand == "D"){ // If slewing
            return "#";
        }else if(comand == "GW"){ // Get track state / mount type
            return "PT2#";
        }
    }
    

    return response.getBody();
}