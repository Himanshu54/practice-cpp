#include <iostream>
#define K 25

/*
 * Create Sparse table for range minimum Queries.
 */
int main(){
	
	std::cout<<"No of elements in array :";	
	int n;
	std::cin>>n;
	std::cout<<"\n Array[space seperated Elements] :";
	int ar[n];
	for(int i =0;i<n;i++){
		std::cin>>ar[i];
	}
	int st[n][K];

	for(int i =0;i<n;i++){
		st[i][0] = ar[i];
	}

	for(int j = 1; j <= K; j++){
		for(int i = 0; i + (1<<j) <= n;i++){
			st[i][j] = std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	std::cout<<"\n===========Sparse Table==================\n";
	for(int i = 0;i<n;i++){
		for(int j = 0; j <= K;j++){
			if( i+ (1<<j) <= n)
			std::cout<<"st["<<i<<"]["<<j<<"] = "<<st[i][j]<<"\n";
		}
		std::cout<<"-------------------------------\n";
	}

}
