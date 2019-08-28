#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMBER_OF_THREADS 10
int sum;                    // shared data between threads
void *runner(void *param);    // function thread excutes
int main(int argc, char *argv[]){
    
    pthread_t workers[NUMBER_OF_THREADS];          // thread identifier
    pthread_attr_t attr;    // set of thread attributes

    if(argc != 2){
        fprintf(stderr,"Usage: ./a.out <integer value>\n");
        return -1;
    }

    if(atoi(argv[1]) < 0){
        fprintf(stderr,"%d must be >= 0",atoi(argv[1]));
        return -1;
    }

    int number_of_thread = atoi(argv[1])/10;
    int i;
    int *start = (int*)malloc(sizeof(int)*2);
    *start = 1;
    *(start+1) = 10;
    for(i=0;i<number_of_thread;i++){
        if(*(start+1) > atoi(argv[1])){
            *(start+1) = atoi(argv[1]);
        }
        pthread_attr_init(&attr);
        pthread_create(&workers[i],&attr,runner,(void*)start);
        printf("Worker: %d start : %d\n",(int)workers[i],*start);
        *start = *(start+1) +1;
        *(start+1) += 10;
    }

    for(i =0;i<number_of_thread;i++){
        pthread_join(workers[i], NULL);
    }
    
    printf("Sum: %d\n",sum);
}

void *runner(void *param){
    int lower = *((int *)param), upper =  *((int *)param +1);
    int local_sum = 0;
    for(int i=lower;i<=upper;i++){
        local_sum+=i;
    }
    sum += local_sum;
    printf("Sum (%d,%d): %d - %d \n",lower,upper,local_sum,sum);
    pthread_exit(0);
}