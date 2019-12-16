#include <iostream>

#include "minimum_stack.h"

template <class T>
class MinQueue{
	
	MinStack<T> s1,s2;

	public:
		void push_back(T element){
			s1.push(element);
		}	

		void pop_front(){
			if(s2.empty()){
				while(!s1.empty()){
					T ele = s1.top();
					s1.pop();
					s2.push(ele);
				}
			}
			s2.pop();
		}

		T minimum(){
			if(s1.empty() && s2.empty())
				printf("No element in Queue");
			else if(s1.empty() || s2.empty())
				return s1.empty()? s2.minimum():s1.minimum();
			else
				return std::min(s1.minimum(),s2.minimum());
		}
};
