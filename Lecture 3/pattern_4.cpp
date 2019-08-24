#include <iostream>

using namespace std;

int main(){

	// int n;
	// cin>>n;

	// for(int row=1 ;row <= n; row++){

	// 	//Space
	// 	for(int col=1; col<=n-row; col++){
	// 		cout<<" ";
	// 	}

	// 	//Dec
	// 	for(int numDec = row;numDec >= 1;numDec--){
	// 		cout<<numDec;
	// 	}

	// 	//Inc
	// 	for(int numInc = 2;numInc <= row; numInc++){
	// 		cout<<numInc;
	// 	}

	// 	cout<<endl;
	// }

	int n;
	cin>>n;

	for(int row=1 ;row <= n; row++){

		//Space
		for(int col=1; col<=n-row; col++){
			cout<<" ";
		}
		
		for(int incDec = -row;incDec <= row;incDec++){
			if(incDec < 0){
				// incDec = incDec*(-1); //Wrong
				// cout<<incDec;
				cout<<(incDec*(-1));
			}else if(incDec==0 or incDec==1){
				continue;
			}else{
				cout<<incDec;
			}
		}

		cout<<endl;
	}

	// int i= 0;

	// while(i<=10){
	// 	i++;
	// }

	// cout<<i<<endl;

	// for(int i=0;i<=10;i++){
	// cout<<i<<endl;
	// }

	// cout<<i<<endl;

	// if(123){
	// 	int val = 10;

	// }

	// cout<<val<<endl;

	return 0;
}