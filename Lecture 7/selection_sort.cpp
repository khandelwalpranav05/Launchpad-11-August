#include <iostream>

using namespace std;


void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selectionSort(int arr[],int n){

	for(int i=0;i<n-1;i++){

		for(int j=i+1;j<n;j++){

			if(arr[i]>arr[j]){

				swap(arr,i,j);
			}
		}
		// cout<<"*******************"<<endl;
		// for(int i=0;i<5;i++){
		// cout<<arr[i]<<" ";
		// }
		// cout<<endl;
	}
}

int main(){

	int arr[] = {5,4,3,2,1};

	selectionSort(arr,5);

	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	for(int i=2;i<2;i++){
		cout<<"Hello"<<endl;
	}

	return 0;
}