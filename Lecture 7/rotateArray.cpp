#include <iostream>

using namespace std;

int main(){

	int arr[] = {1,2,3,4,5,6};

	rotate(arr,6);

	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}