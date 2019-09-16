#include <iostream>

using namespace std;

void uniqueNumberPair(int arr[],int n){

	int pairXor = arr[0];

	for(int i=1;i<n;i++){
		pairXor = pairXor^arr[i];
	}

	int var = pairXor;
	int position = 0;

	while(true){
		if(var&1){
			break;
		}else{
			var = var>>1;
			position++;
		}
	}


	int left_unique = 0;

	for(int i=0;i<n;i++){

		int element = arr[i];
		element = element>>position;

		if(element&1){
			left_unique = left_unique^arr[i];
		}
	}

	int right_unique = left_unique^pairXor;

	cout<<"First unique Value "<<left_unique<<endl;
	cout<<"Second unique Value "<<right_unique<<endl;
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

	// cout<<countSetBits(13)<<endl;

	// int arr[] = {1,1,3,3,4,5,4,8,8,7};
	// uniqueNumberPair(arr,10);

	int arr[] = {1,1,2,2,3,5,6,7,6,5,6,5,3,1,2,3}

	return 0;
}