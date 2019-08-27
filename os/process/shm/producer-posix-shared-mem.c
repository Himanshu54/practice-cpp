#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
int main(){

	const int SIZE =  4096; // size in bytes of shm obj
	const char *name = "OS"; // name of dhm obj
	
	const char *message_0 = "Hello";
	const char *message_1 = "World!"; // messages to be written

	int shm_fd; //fd 

	void *ptr; //pointer to shm obj

		shm_fd = shm_open(name,O_CREAT | O_RDWR, 0666); //create shm obj
		ftruncate(shm_fd,SIZE); // configure size
		ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
		sprintf(ptr,"%s",message_0);
		ptr += strlen(message_0);
		sprintf(ptr,"%s",message_1);
		ptr += strlen(message_1);

	return 0;
}

