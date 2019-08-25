#include <iostream>

using namespace std;

// void increment(int a){
// 	a = a + 2;

// 	cout<<"Inside the function "<<a<<endl; 
// }

// int main(){

// 	int a = 10;
// 	increment(a);

// 	cout<<"Inside Main "<<a<<endl;

// 	return 0;
// }

void increment(int* aptr){
	*aptr = *aptr + 2;

	cout<<"Inside the function "<<(*aptr)<<endl; 
}

int main(){

	int a = 10;
	increment(&a);

	cout<<"Inside Main "<<a<<endl;

	return 0;
}