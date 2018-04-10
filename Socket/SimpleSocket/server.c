#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(){
	int 	server_fd, new_socket, valread;
	struct  sockaddr_in address;
	int 	otp = 1;
	int 	addrlen = sizeof(address);
	char	buffer[1024] = {0};
	char* 	hello = "Hello from server..\n";
	
	// create socket file descriptor
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
		perror("Socket failure\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("Create socket success.\n");
	}

	// forcefully attaching socket to the port 8080
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &otp, sizeof(otp))){
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	else {
		printf("set socket option success.\n");
	}

	address.sin_family  	= AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port  		= htons(PORT);

	// forcefully attching socket to the port 8080
	if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
		perror("bind failure");
		exit(EXIT_FAILURE);
	}
	else {
		printf("attching socket to port 8080.\n");
	}

	// listen from client
	if(listen(server_fd, 3) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	else {
		printf("listening..\n");
	}
	
	// create new socket
	if((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	valread = read(new_socket, buffer, 1024);
	printf("%s\n", buffer);
	send(new_socket, hello, strlen(hello), 0);
	printf("Hello message sent..\n");

	return 0;
}
