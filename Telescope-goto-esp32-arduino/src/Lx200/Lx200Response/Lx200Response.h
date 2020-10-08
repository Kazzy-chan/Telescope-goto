#ifndef __LX200Response_h__
#define __LX200Response_h__

#include <Arduino.h>

class Lx200Response{
    protected:
        String body;
        void setBody(String body);
    public:
        String getBody();
};

#endif