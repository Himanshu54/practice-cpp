#include <sys/types.h>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

# define PORT "5000"

int main(){

	// get addr;
	int status;
	struct addrinfo hints, *servinfo;
	socklen_t addr_size;
	int fd, new_fd;
	struct sockaddr_storage their_addr;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if (( status = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		exit(1);
	}
	
	// create socket;
	if (( fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1){
		fprintf(stderr, "creating socket error: %d\n", fd);
		exit(1);
	}

	// bind
	bind(fd, servinfo->ai_addr, servinfo->ai_addrlen);

	// listen;
	listen(fd, 5);

	// recive;
	addr_size = sizeof their_addr;
	new_fd = accept(fd, (struct sockaddr *)&their_addr, &addr_size);
	char buf[10];
	int bytes_recv = recv(new_fd, (void *)buf, 10, 0);
	printf("%s : %d\n", buf, bytes_recv);

	// send;
	char *msg = "World!";
	int len = strlen(msg);
	int byte_sent = send(new_fd, msg, len, 0);

	// cleanup
	close(new_fd);
	close(fd);
	freeaddrinfo(servinfo);
}

