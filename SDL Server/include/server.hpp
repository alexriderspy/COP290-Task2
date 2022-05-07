#ifndef _SERVER_H
#define _SERVER_H
#pragma once



#include <iostream>
#include <string>
#include <sstream>



#include <constants.hpp>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>




class Server{
public:

	int server_fd, new_socket;
	struct sockaddr_in address;
	int opt;
	int addrlen;
	char buffer[1024];



	Server();



	void connectCS();



	void sendCS(std::string data);



	std::string receiveCS();



};
#endif