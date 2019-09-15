#include <iostream>

using namespace std;

int uniqueNumberPair(int arr[],int n){

	int pairXor = arr[0];

	for(int i=1;i<n;i++){

	}

	int var = pairXor;
	int position = 0

	while(){
		int temp = var&1;

		if(temp==1){
			//
		}else{
			var = var>>1;
			position++;
		}
	}

	for(int i;i<;i++){

		int element = arr[i];
		element = element>>position;

		if(element&1){

		}

	}
}

int uniqueNumber(int arr[],int n){

	int Xor = arr[0];

	for(int i=1;i<n;i++){
		Xor = Xor^arr[i];
	}
	return Xor;
}

int countSetBits(int n){

	int count = 0;

	while(n!=0){

		count = count + (n&1);
		n = n>>1;
	}

	return count;

}

int main(){

	// int arr[] = {1,2,3,4,5,6,7,6,5,4,3,2,1};
	// cout<<uniqueNumber(arr,13)<<endl;

	cout<<countSetBits(13)<<endl;

	// int arr[] = {1,1,3,3,4,5,4,8,8,7};
	// cout<<uniqueNumberPair(arr,12)<<endl;

	return 0;
}