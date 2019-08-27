#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    int fd;
    char *myfifo = "/tmp/myfifo";       // FIFO file path

    mkfifo(myfifo,0666);

    char read_msg[80], write_msg[80];

    while(1){

        fd = open(myfifo,O_RDONLY); // write only 
        read(fd,read_msg,80);
        printf("Message 1: %s\n",read_msg);
        close(fd);
        
        fd = open(myfifo,O_WRONLY);
        fgets(write_msg,80,stdin);
        write(fd,write_msg,strlen(write_msg)+1);
        close(fd);
    }
    return 0;
}