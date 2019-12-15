#include <iostream>
#include <stack>
#include <utility> // <pair>
/*
A Template for Minimum stack.
*/
template <class T>
class MinStack{
	
	std::stack<std::pair<T,T>> st;
	public:
	MinStack(){
	}
		
	void push(T element){
		T min_ele = st.empty() ? element : std::min(element,st.top().second);
		st.push({element, min_ele});
	}

	void pop(){
		st.pop();
	}

	T top(){
		return st.top().first;
	}

	T minimum(){
		return st.top().second;
	}
};
