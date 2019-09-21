#include <iostream>

using namespace std;

int factorial(int n){
	if(n==1){
		return 1;
	}

	int fact_n1 = factorial(n-1);
	int fact_n = fact_n1*n;
	return fact_n;
}

int power(int n,int p){
	if(p==0){
		return 1;
	}

	int power_n1 = power(n,p-1);
	int power_n = power_n1*n;
	return power_n;
}

int main(){

	// cout<<factorial(5)<<endl;

	// cout<<power(2,8)<<endl;

	

	return 0;
}