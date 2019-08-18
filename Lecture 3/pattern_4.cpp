#include <iostream>

using namespace std;

int main(){

	// int n;
	// cin>>n;

	// for(int row=1 ;row <= n; row++){

		//Space
		for(int col=1; col<=n-row; col++){
			cout<<" ";
		}

		//Dec
		for(int col = row;col >= 1;col--){
			cout<<col;
		}

		//Inc
		for(int col = 2;col <= row; col++){
			cout<<col;
		}

	// 	cout<<endl;
	// }

	// int i= 0;

	// while(i<=10){
	// 	i++;
	// }

	// cout<<i<<endl;

	// for(int i=0;i<=10;i++){
	// cout<<i<<endl;
	// }

	// cout<<i<<endl;

	if(123){
		int val = 10;

	}

	cout<<val<<endl;

	return 0;
}