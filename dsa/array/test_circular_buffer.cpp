#include<iostream>
#include<assert.h>
#include"circular_array.h"

int main(){
    CircularArray buffer = CircularArray(5);
    buffer.insert(1);
    assert(buffer.size() == 1);
    buffer.pop();
    assert(buffer.size() == 0);
    buffer.pop(); // prints UnderFlow
    assert(buffer.size() == 0);
    for(int i =0; i<10;i++){
        buffer.insert(i+1); // prints Overflow for 5-9
    }
    assert(buffer.size() == 5);
    assert(buffer.is_full() == 1);
    assert(buffer.pop()==1);
    assert(buffer.pop()==2);
    assert(buffer.is_full() == 0);
    assert(buffer.capacity() == 5);
    assert(buffer.size() == 3);
    assert(buffer.pop() == 3);
    assert(buffer.pop() == 4);
    assert(buffer.pop() == 5);
    assert(buffer.is_empty() == 1);
    assert(buffer.size() == 0);
    buffer.insert(10);
    assert(buffer.peek() == 10);
    assert(buffer.is_empty() == 0);

}