#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1
int main(){

    char write_message[BUFFER_SIZE] = "Hello World!";
    char read_message[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    if(pipe(fd) == -1){
        fprintf(stderr,"Pipe Failed\n");
        return -1;
    }

    pid = fork();

    if(pid < 0){
        fprintf(stderr,"Fork Failed\n");
        return 1;
    }

    if(pid > 0){
        close(fd[READ_END]);
        write(fd[WRITE_END],write_message,strlen(write_message)+1);
        close(fd[READ_END]);
    }
    else{
        close(fd[WRITE_END]);
        read(fd[READ_END],read_message,BUFFER_SIZE);
        printf("Read:%s",read_message);
        close(fd[READ_END]);
    }

    return 0;
}