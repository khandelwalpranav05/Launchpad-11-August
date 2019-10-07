#include <iostream>
#include <string.h>
#include<string>

using namespace std;

class Car{
public:
	int speed;
	char *name;

	void startCar(){
		cout<<"Ignition"<<endl;
	}

	Car(){
		cout<<"Mera Constructor"<<endl;
	}

	Car(int speed,char *str){
		this->speed = speed;
		name = new char[strlen(str)];
		strcpy(name,str);
		// name = str;
	}

	void printDetails(){
		cout<<this->speed<<endl;
		cout<<name<<endl;
	}

	Car(Car &X){
		this->speed = X.speed;
		this->name = new char[strlen(X.name) + 1];
		strcpy(this->name,X.name);
	}

	void operator =(Car &X){
		this->speed = X.speed;
		this->name = new char[strlen(X.name) + 1];
		strcpy(this->name,X.name);
	}

	~Car(){
		// delete [] name;
		cout<<"Khatam"<<endl;
	}
};

int main(){

	// Car A(100,"First");
	// cout<<"**********A***********"<<endl;
	// A.printDetails();

	// cout<<"*********B*********"<<endl;
	// Car B(A);
	// // Car B = A;
	// B.name[0] = 'Q';
	// B.printDetails();
	// cout<<"***********A**********"<<endl;
	// A.printDetails();


	Car A(100,"First");
	// A.printDetails();

	// cout<<"******B*********"<<endl;
	// Car B;
	// B = A;
	// B.name[0] = 'Q';
	// B.printDetails();
	// cout<<"***********A**********"<<endl;
	// A.printDetails();

	cout<<A.name<<endl;
	char *a = A.name;
	cout<<(void*)a<<endl;
	delete [] a;

	cout<<A.name<<endl;
	cout<<((void*)A.name)<<endl;
	return 0;
}