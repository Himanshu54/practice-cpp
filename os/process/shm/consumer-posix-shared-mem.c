#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
int main(){

	const int SIZE = 4096; // size in bytes of shm obj
	const char *name = "OS"; // name of dhm obj
	
	int shm_fd; //fd 

	void *ptr; //pointer to shm obj

		shm_fd = shm_open(name, O_RDONLY,0666); //create shm obj
		ftruncate(shm_fd,SIZE); // configure size
		ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
		printf("%s",(char*)ptr);

		shm_unlink(name);
	return 0;
}

