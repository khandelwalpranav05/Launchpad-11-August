#include <iostream>

using namespace std;

int main(){
	int n = 49;
	int i = 2;

	while(i < n){
		cout<<(i-1)<<" Number of times"<<endl;

		if(n%i==0){
			cout<<"Not Prime"<<endl;
			break;
		}
		// break;

		i = i + 1;
	}

	if(i==n){
		cout<<"Prime"<<endl;
	}

	// int x = 10;

	// cout<<"Value of x is";
	// cout<<x;
	// cout<<endl;

	// cout<<"Value of x is "<<x<<endl;

	return 0;
}