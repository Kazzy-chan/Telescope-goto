#ifndef __LX200Response_h__
#define __LX200Response_h__


class Lx200Response{
    protected:
        std::string body;
        void setBody(std::string body);
    public:
        std::string getBody();
};

#endif