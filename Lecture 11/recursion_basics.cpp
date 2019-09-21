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

void printI(int n){
	if(n==0){
		return;
	}

	printI(n-1);
	cout<<n<<endl;
	return;

}

void printDI(int n){
	if(n==0){
		return;
	}

	cout<<n<<endl;
	printDI(n-1);
	cout<<n<<endl;
	return;
}

bool isSorted(int arr[],int idx,int n){
	//Base Case
	if(idx==n-1){
		return true;
	}

	//Recursive Case
	bool rest_of_the_array = isSorted(arr,idx+1,n);

	if(rest_of_the_array==false){
		return false;
	}else{
		if(arr[idx]>arr[idx+1]){
			return false;
		}else{
			return true;
		}
	}
}

int main(){

	// cout<<factorial(5)<<endl;

	// cout<<power(2,8)<<endl;

	// cout<<sumTillN(10)<<endl;

	// printD(5);
	// printI(5);
	// cout<<"*********"<<endl;
	// printDI(5);

	int arr[] = {1,2,3,4,5};
	int brr[] = {132,2,3,5,6};

	cout<<isSorted(arr,0,5)<<endl;
	cout<<isSorted(brr,0,5)<<endl;

	// cout<<sizeof(printDI(5))<<endl;
	

	return 0;
}