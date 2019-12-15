#include <iostream>
#include <string.h>

// sample template class
template<class T>
class myTemplate{
	T element;
	public:
	myTemplate(T arg){
		element = arg;
	}
	
	T divideBy2(){
		return element/2;
	}
};
// template specialization
template <>
class myTemplate <std::string> {
	std::string element;
	public:
	myTemplate(std::string s){
		element = s;
	}
	std::string divideBy2(){
		int l = element.length()/2;
		return element.substr(0,l);
	}
};

int main(){

	myTemplate<int> number(10);
	printf("%d\n",number.divideBy2());

	myTemplate<std::string> name(std::string("Himanshu Gusain"));
	std::cout<<name.divideBy2()<<"\n";
}

