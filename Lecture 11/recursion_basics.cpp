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

int sumTillN(int n){
	if(n==0){
		return 0;
	}

	// if(n==1){
	// 	return 1;
	// }

	//Recursive case
	int sum_n1 = sumTillN(n-1);
	int sum = sum_n1 + n;
	return sum;
}

void printD(int n){
	// if(n==1){
	// 	cout<<1<<endl;
	// 	return;
	// }

	if(n==0){
		return;
	}

	cout<<n<<endl;
	printD(n-1);
	return;
}

int main(){

	// cout<<factorial(5)<<endl;

	// cout<<power(2,8)<<endl;

	// cout<<sumTillN(10)<<endl;

	printD(5);

	return 0;
}