#ifndef __LX200Response_h__
#define __LX200Response_h__

#include <string>
#include <stdio.h>

#include "../../../EquatorialCoordinates/Ra/Ra.h"
#include "../../../EquatorialCoordinates/Dec/Dec.h"

class Lx200Response{
    protected:
        std::string body;
        bool shouldGetSend;
        void setBody(std::string body);
    public:
        std::string getBody();
        Lx200Response(std::string body);
        Lx200Response();

        static Lx200Response null();

        static Lx200Response GD(Dec);
        static Lx200Response GR(Ra);
        static Lx200Response GVP(std::string firmwareName); // todo more abstract paramters
        static Lx200Response GVN(std::string firmwareVersion); // todo more abstract paramters
        static Lx200Response GVD(std::string firmwareDate); // todo more abstract paramters
        static Lx200Response GVT(std::string firmwareTime); // todo more abstract paramters
        static Lx200Response D(bool isSlewing);
        static Lx200Response GW(std::string info); // todo more abstract paramters
        // static Lx200Response GW(std::string firmwareTime);
};

#endif