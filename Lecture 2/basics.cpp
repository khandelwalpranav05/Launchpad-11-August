#include <iostream>

using namespace std;

int main(){

	int a = 10;
	int b = 20;
	int c = 30;

	if (a >= b and a >= c){
		// print(a);
		cout<<a<<endl;

	}else if(b >= a and b >= c){
		// print(b);
		cout<<b<<endl;

	}else{
		// print(c);
		cout<<c<<endl;
	}

	return 0;
}