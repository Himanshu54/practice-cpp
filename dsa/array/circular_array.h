#include <iostream>
#include <stdlib.h>
/*
A Class implement Circular Array
*/

class CircularArray{
    private:
        int *ptr;           // Pointer for array
        int head;           // Write element into array
        int tail;           // Read from tail
        int size_of;        // Max capacity of array
    public:
        /*
        Constructor
        size        (int): size of buffer
        */
        CircularArray(int size){
            size_of = size+1;
            ptr = (int* )malloc(sizeof(int)*size_of);
            head = 0;
            tail = 0;
        }
        /*
        Returns number of elements in array
        */
        int size(){
            return (head + size_of -tail)%size_of;
        }
        /*
        Returns max capacity of array
        */
        int capacity(){
            /*
            since array is considered full if only one empty space
            */
            return size_of-1;
        }
        /*
        Check if buffer empty
        */
        int is_empty(){
            if(head==tail) return 1;
            return 0;
        }
        /*
        Check if array is full
        */
        int is_full(){
            if((head+1)%size_of == tail) return 1;
            return 0;
        }
        /*
        Insert element in buffer
        */
        int insert(int item){
            if(is_full()){
                std::cout<<"Overflow\n";
                return -1;
            }
            *(ptr+head) = item;
            head = (head+1)%size_of;
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
            int temp = *(ptr+tail);
            tail = (tail+1)%size_of;
            return temp;
        }
        /*
        Read data at top of buffer without removing
        */
        int peek(){
            if(is_empty()){
                std::cout<<"Underflow\n";
                return -1;
            }
            return *(ptr+tail);
        }
};