#ifndef __LX200Request_h__
#define __LX200Request_h__

#include "Lx200Requests.h"

class Lx200Request{
    protected:
        Lx200Requests type;
    public:
        Lx200Requests getType();
};

#endif