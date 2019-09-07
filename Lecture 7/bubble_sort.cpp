#include <iostream>

using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubbleSort(int arr[],int n){

	int endPoint = 1;

	while(endPoint<n){

		for(int i=0;i<=(n-endPoint);i++){
			if(arr[i]>arr[i+1]){
				swap(arr,i,i+1);
			}
		}
		// cout<<"*******************"<<endl;
		// for(int i=0;i<5;i++){
		// cout<<arr[i]<<" ";
		// }
		// cout<<endl;

		endPoint++;
	}

}

int main(){
	int arr[] = {5,4,3,2,1};

	bubbleSort(arr,5);

	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}