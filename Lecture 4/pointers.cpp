#include <iostream>

using namespace std;

int main(){

	int x = 10;

	// cout<<(&x)<<endl; //8080

	int* xptr = &x;
	// cout<<((void*)xptr)<<endl;
	// cout<<xptr<<endl;

	cout<<(&x)<<endl;
	cout<<xptr<<endl;

	int** xxptr = &xptr;

	cout<<xxptr<<endl;
	cout<<(&xptr)<<endl;

	cout<<(xxptr + 1)<<endl;
	cout<<(*xxptr)<<endl;

	// void * new_xptr = (void*)xptr;

	// cout<<sizeof(new_xptr)<<endl;

	// cout<<"Value of x after typecasting "<<(*new_xptr)<<endl;

	// cout<<xptr<<endl; //8080

	// cout<<(*xptr)<<endl; //10

	// cout<<(xptr + 1)<<endl; //8081

	// int x = 10;

	// int &z = x;

	// z++;

	// cout<<x<<endl;
	// cout<<(&z)<<endl;
	// cout<<(&x)<<endl;

	// cout<<(*xptr)<<endl; //10

	// float f = 10.6;
	// cout<<(&f)<<endl;

	// float* fptr = f;
	// cout<<fptr<<endl;

	// bool b = true;

	// cout<<(&b)<<endl;

	// float f = (float)10*10;
	// cout<<f<<endl;

	// char c = 'A';

	// cout<<((void*)&c)<<endl;

	// char *cptr = &c;

	// cout<<sizeof(cptr)<<endl;

	// cout<<((int)c)<<endl;

	return 0;
}