#ifndef __LX200ResponseGD_h__
#define __LX200ResponseGD_h__

#include "../Lx200Response.h"

class Lx200ResponseGD: public Lx200Response {
    private:
        
    public:
        Lx200ResponseGD(bool isPositive, int degree, int arcMinutes, int arcSeconds);
};


#endif