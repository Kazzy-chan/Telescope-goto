#ifndef __Ra_h__
#define __Ra_h__

#include <string>
#include <stdlib.h>
#include <stdio.h>

class Ra{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Ra(int hours, int minutes, int seconds);
    static Ra fromString(std::string);

    Ra operator+ (const Ra& other);
    Ra operator- (const Ra& other);

    float toDegree();
    void update(std::string);
    std::string toString();
};

#endif