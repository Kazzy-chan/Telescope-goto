#ifndef __Dec_h__
#define __Dec_h__

#include <string>
#include <stdlib.h>
#include <stdio.h>

class Dec{
private:
    char sign;
    int degrees;
    int arcminutes;
    int arcseconds;
public:
    Dec(char sign, int degrees, int arcminutes, int arcseconds);
    static Dec fromString(std::string);

    Dec operator+ (const Dec& other);
    Dec operator- (const Dec& other);

    float toDegree();
    void update(std::string);
    std::string toString();
};

#endif