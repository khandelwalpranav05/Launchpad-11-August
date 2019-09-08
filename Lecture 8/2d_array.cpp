#include <iostream>

using namespace std;

int main(){

	int arr[2][4] = {1,2,3,4,789,6};

					// {{1,2,3,4},
					// {5,6}}

	int brr[10] = {0};

	// for(int i=0;i<12;i++){
	// 	cout<<brr[i]<<" ";
	// }
	// cout<<endl;

	for(int i=0;i<2;i++){
		for(int j=0;j<4;j++){
			cout<<"("<<i<<","<<j<<")";
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}