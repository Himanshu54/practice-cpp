#include <iostream>
#include <stdlib.h>
/*
A Class implement Queue
*/

class Queue{
    private:
        int *ptr;           // Pointer for array
        int head;           // front of array
        int tail;           // tail of array
        int size_of;        // Max capacity of array
    public:
        /*
        Constructor
        size        (int): size of buffer
        */
        Queue(int size){
            size_of = size+1;
            ptr = (int* )malloc(sizeof(int)*size_of);
            head = 0;
            tail = 0;
        }
        /*
        Returns number of elements in array
        */
        int size(){
            return tail - head;
        }
        /*
        Returns max capacity of array
        */
        int capacity(){
            /*
            since array is considered full if only one empty space
            */
            return size_of;
        }
        /*
        Check if buffer empty
        */
        int is_empty(){
            if(head==tail) return 1;
            return 0;
        }
        /*
        Insert element in buffer
        */
        int push(int item){
            if(tail == size_of){
                // todo : extend queue
                return 0;
            }
            tail ++;
            *(ptr+tail) = item;
            return 1;
        }
        /*
        Read data and remove from buffer
        */
        int pop(){
            if(is_empty()){
                std::cout<<"Underflow\n";
                return -1;
            }
            int temp = *(ptr+head);
            head ++;
            return temp;
        }
        /*
        Read data at top of buffer without removing
        */
        int front(){
            if(is_empty()){
                std::cout<<"Underflow\n";
                return -1;
            }
            return *(ptr+head);
        }
};