#include<iostream>
#include"array.h"
#include<assert.h>

int main(){
    IntegerArray ar = IntegerArray(5,4);
    int arr[6] = {4,4,4,4,4,10};
    ar.push(10);
    for(int i= 0;i<6;i++){
        assert(arr[i] == ar.at(i));
    }
    assert(ar.size() == 6);
    assert(ar.capacity() == 8);
    for(int i=0;i<6;i++){
        ar.pop();
    }
    assert(ar.size() == 0);
    ar.insert(11,0);
    assert(ar.at(0)==11);
    ar.push(12);
    ar.push(13);
    ar.push(15);
    ar.insert(14,3);
    assert(ar.at(3) == 14);
    ar.prepend(10);
    assert(ar.at(0) == 10);
    ar.del(0);
    assert(ar.at(0)==11);
    ar.prepend(10);
    ar.del(3);;
    assert(ar.at(3)==14);
    ar.push(10);
    ar.remove(10);
    assert(ar.find(10) == -1);
    assert(ar.capacity() == 8);
    ar.push(16);
    ar.push(17);
    ar.push(18);
    ar.push(19);
    assert(ar.capacity() == 16);
    for(int i = 0;i<5;i++){
        ar.pop();
    }
    assert(ar.capacity() == 8);
}