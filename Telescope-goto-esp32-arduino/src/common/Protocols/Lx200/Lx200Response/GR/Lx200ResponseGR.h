#ifndef __LX200ResponseGR_h__
#define __LX200ResponseGR_h__

#include "../Lx200Response.h"

class Lx200ResponseGR: public Lx200Response 
{
public:
    Lx200ResponseGR(int hours, int minutes, int seconds);
};


#endif