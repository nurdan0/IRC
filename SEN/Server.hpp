#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/poll.h>


#define maxClient 100

class Server{

    private:
        int _port;
        std::string _password;
        int _socket;
        pollfd  _pollFd[maxClient];
        sockaddr_in _socketAddr;
    public:
        Server();
        Server(int port, std::string password);
        ~Server(void);
        void startServer();
        void initServer(int port, std::string password);

};
