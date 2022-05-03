#ifndef _CLIENT_H
#define _CLIENT_H
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

class Client{
    public:
        
    int sock;
	struct sockaddr_in serv_addr;
	Client();
	
	void connectCS();

	void sendCS(std::string data);

	std::string receiveCS();
};
#endif