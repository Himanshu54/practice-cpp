#include<iostream>
#include<assert.h>
#include "minimum_queue.h"

int main(){
    MinQueue<int> qu;
    
    int ar[] = {5,3,4,2,4,5,1,9};
    int tar[] = {5,3,3,2,2,2,1,1};
	
    int ar_i = 0,tar_i = 0;
    for(;ar_i<3;ar_i++){
    	qu.push_back(ar[ar_i]);
	assert(qu.minimum() == tar[tar_i]);
	tar_i += 1;
	printf("[%d , %d]",ar[ar_i],qu.minimum());	
    }
	
    for(;ar_i<8;ar_i++){
	qu.push_back(ar[ar_i]);
	qu.pop_front();
	assert(qu.minimum() == tar[tar_i]);
	tar_i += 1;
	printf("[%d , %d]",ar[ar_i],qu.minimum());
    }

}
