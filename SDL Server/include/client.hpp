#ifndef _SERVER_H
#define _SERVER_H
#pragma once

#include<constants.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

class Server{
    public:
        
    int sock;
	struct sockaddr_in serv_addr;
	Server();
	
	void connectCS();

	void sendCS(std::string data);

	std::string receiveCS();
};
#endif