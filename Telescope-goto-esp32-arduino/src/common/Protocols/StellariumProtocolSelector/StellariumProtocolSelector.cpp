#include "StellariumProtocolSelector.h"

StellariumProtocolSelector::StellariumProtocolSelector(){

}

std::string StellariumProtocolSelector::interpret(std::string msg){
    if (msg[0] == '#' || msg[0] == 0x06){
        return "P";
    }
    return "";
}