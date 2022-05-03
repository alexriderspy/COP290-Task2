#include <client.hpp>

Client::Client(){
    sock=0;
}

void Client::connectCS(){
		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			printf("\n Socket creation error \n");
		    exit(EXIT_FAILURE);
		}

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(PORT);

		// Convert IPv4 and IPv6 addresses from text to binary
		// form
		if (inet_pton(AF_INET, "192.168.43.80", &serv_addr.sin_addr)
			<= 0) {
			printf(
				"\nInvalid address/ Address not supported \n");
		    exit(EXIT_FAILURE);
			}

		if (connect(sock, (struct sockaddr*)&serv_addr,	sizeof(serv_addr))< 0) {
			printf("\nConnection Failed \n");
		    exit(EXIT_FAILURE);
		}
}

void Client::sendCS(std::string data){
    const char* hello=data.c_str();
    send(sock, hello, strlen(hello), 0);

}

std::string Client::receiveCS(){
    int valread;
    char buffer[1024];

    for(int i=0;i<1024;i++){
        buffer[i]='\0';
    }
    valread = read(sock, buffer, 1024);

    std::string s(buffer);
    return s;

}
