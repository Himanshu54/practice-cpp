#include <sys/types.h>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <netdb.h>

int main(){

	// get addr;
	int status;
	struct addrinfo hints;
	struct addrinfo *servinfo;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if (( status = getaddrinfo(NULL, "1400", &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		exit(1);
	}
	
	// create socket;

	// listen;

	// recive;

	// send;

	// cleanup
	freeaddrinfo(servinfo);
}

