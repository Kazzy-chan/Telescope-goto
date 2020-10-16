#ifndef __TimeDateLocation_h__
#define __TimeDateLocation_h__

#include "../../Logger.h"
#include <string>

class AppDataTimeDateLocation{
    std::string time;
    std::string date;
    std::string utcOffset;
    std::string latitude;
    std::string longitude;
public:
    AppDataTimeDateLocation();
    void setTime(std::string);
    void setDate(std::string);
    void setUtcOffset(std::string);
    void setLatitude(std::string);
    void setLongitude(std::string);

    std::string getTime();
    std::string getDate();
    std::string getUtcOffset();
    std::string getLatitude();
    std::string getLongitude();
};

#endif