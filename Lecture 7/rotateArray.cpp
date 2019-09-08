#include <iostream>

using namespace std;

void rotate(int arr[],int n,int k){

	while(k!=0){

		int temp = arr[n-1];

		for(int i=n-2;i>=0;i--){
			arr[i+1] = arr[i];
		}

		arr[0] = temp;

		k--;
	}
}

int main(){

	int arr[] = {1,2,3,4,5,6};

	rotate(arr,6);

	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}