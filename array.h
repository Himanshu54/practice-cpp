#include<iostream>
#include<stdlib.h>
/*
A Class implementing Dynamic Array.
*/

class IntegerArray{
    private:
        int *ptr;               // Pointer for array adress.
        int number_of_items;    // Number of elements Populated.
        int size_of;            // Capacity of array.
    public:
        /* Return number of elements in array.
         */
        int size(){
            return number_of_items;
        }
        /*Return Capacity of array.
         */
        int capacity(){
            return size_of;
        }
        /* Return item at index
         */
        int at(int index){
            if(checkBounds(index))
                return *(ptr+index);
        }
        /* Return True if array is empty
         */
        int is_empty(){
            if(number_of_items == 0){
                return 1;
            }
            return 0;
        }
        /*Removes element from last */
        int pop(){
            if(number_of_items == 0){
                std::cout<<"List Empty"<<std::endl;
                return -1;
            }
            int item = *(ptr+number_of_items-1);
            number_of_items--;
            resize(number_of_items);
            return item;
        }
        /* Delete item at index and shift elements to left.
         */
        int del(int index){
            if(checkBounds(index)){
                for(int i=index;i<number_of_items-1;i++){
                    *(ptr+i) = *(ptr+i+1);
                }
                number_of_items--;
                return 1;
            }           
            return -1; 
        }
        
        /* Push item at end of array 
        item(int) : value to be inserted.
        */
        int push(int item){
           number_of_items;
           resize(number_of_items+1);
           *(ptr+number_of_items) = item;
           number_of_items++;
           return 1;
        }
        /*Insert at index
         */
        int insert(int item, int index){
            if(index > number_of_items){
                std::cout<<"Index Out Of Bound"<<std::endl;
                return -1;
            }
            if(number_of_items == 0){
                return push(item);
            }
            int temp  = *(ptr+number_of_items-1);
            for(int i = number_of_items-1;i>index;i--){
                *(ptr+i) = *(ptr+i-1);
            }
            *(ptr+index) = item;
            return push(temp);
        }
        /*Prepend item to array
         */
        int prepend(int item){
            return insert(item,0);
        }
        /*Constructur
        size          (int) : size of array to Create.
        default_value (int) : initial value for elements.
         */
        IntegerArray(int size = 0, int default_value = 0){
            number_of_items = size;
            size            = get_next_power_of_two(size);
            size_of         = size;
            ptr             = (int *)malloc(sizeof(int)*size);
            for(int i = 0;i < number_of_items;i++){
                    *(ptr+i)= default_value;
            }
        }
        /* Remove all occurance of item
         */
         int remove(int item){
             int index = find(item);
             while(index != -1){
                 del(index);
                 index = find(item);
             }
             return 1;
         }
        /* Return first index of item , -1 if not found
         */
        int find(int item){
            for(int i =0; i< number_of_items;i++){
                if( *(ptr+i) == item){
                    return i;
                }
            }
            return -1;
        }
        /*Print function to print array
         */
        void print() const{
            std::cout<<"[";
            for(int i = 0; i < number_of_items; i++){
                if(i == number_of_items -1){
                    std::cout<<*(ptr+i);
                }
                else {
                    std::cout<<*(ptr+i)<<",";
                }
            }
            std::cout<<"]"<<std::endl;
        }
    private:
        int checkBounds(int index){
            if(index >= 0 && index < number_of_items){
                return true;
            }
            std::cout<<"Index Out Of Bounds"<<std::endl;
            return false;
        }
        int get_next_power_of_two(int k){
            int n = 0;
            while(k){
                n++;
                k = k/2;
            }
            return 1<<n;
        }
        int resize(int new_capacity){
            if(new_capacity == size_of){
                size_of = size_of*2;
                int *new_ptr = (int *)malloc(sizeof(int)*size_of);    
                for(int i =0;i<number_of_items;i++){
                   *(new_ptr+i) = *(ptr+i); 
               }
               free(ptr);
               ptr = new_ptr;  
            }
            else if(4*new_capacity < size_of){
                size_of = size_of/2;
                int *new_ptr = (int *)malloc(sizeof(int)*size_of);    
                for(int i =0;i<number_of_items;i++){
                   *(new_ptr+i) = *(ptr+i); 
               }
               free(ptr);
               ptr = new_ptr;
            }
            else {
                return 1;
            }
        }
};