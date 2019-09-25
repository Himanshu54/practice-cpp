#include<iostream>
#include<assert.h>
#include"queue.h"

int main(){
    Queue buffer = Queue(5);
    buffer.push(1);
    assert(buffer.size() == 1);
    buffer.pop();
    assert(buffer.size() == 0);
    buffer.pop(); // prints UnderFlow
    assert(buffer.size() == 0);
    for(int i =0; i<10;i++){
        buffer.push(i+1); // prints Overflow for 5-9
    }
    assert(buffer.front() == 1);
    buffer.pop();
    assert(buffer.size() == 4);
}