#ifdef dev

#ifndef __Server_h__
#define __Server_h__

#include "../config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#ifdef _WIN32
/* Headerfiles für Windows */
#include <winsock.h>
#include <io.h>

#else
/* Headerfiles für UNIX/Linux */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include "../../common/Lx200/ComunicationInterface/ComunicationInterface.h"

class TcpServer: public ComunicationInterface{
private:
    struct sockaddr_in server = {}, client = {};
    char buffer[RCVBUFSIZE];
    bool isBufferRead;

    #ifdef _WIN32
        SOCKET sock, fd;
        void initWinsock();
    #else
        int sock, fd;
    #endif

        void createSocket();
        void error_exit(char *error_message);
    #ifdef _WIN32
        int len;
    #else
        socklen_t len;
    #endif
public:
    TcpServer();
    ~TcpServer();
    void init();
    virtual bool available();
    virtual void write(std::string data);
    virtual std::string recive();
    
};


#endif
#endif