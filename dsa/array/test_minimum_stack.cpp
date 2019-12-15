#include<iostream>
#include<assert.h>
#include "minimum_stack.h"

int main(){
    MinStack<int> st;
    
    int ar[] = {5,3,4,2,4,5,1,9};
    int tar[] = {5,3,3,2,2,2,1,1};

    for(int i =0;i<8;i++){
	    st.push(ar[i]);
	    assert( tar[i] == st.minimum());
	    //printf("[%d : %d],",ar[i],st.minimum());
    }
}
