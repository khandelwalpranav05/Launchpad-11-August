#include <iostream>
#include <string.h>

using namespace std;

class Car{
private:
	int speed;
	int model_no;
	int price;

public:

	char name[20];


	void startCar(){
		cout<<"Ignition"<<endl;
	}

	Car(){
		cout<<"Mera Constructor"<<endl;
	}

	Car(int speed,int model_no,char name[]){
		cout<<"Second"<<endl;
		this->speed = speed;
		this->model_no = model_no;
		strcpy(this->name,name);
	}

	Car(int speed,char name[]){
		cout<<"Third"<<endl;
		this->speed = speed;
		strcpy(this->name,name);
	}

	Car(int speed,int price){
		cout<<"Fourth"<<endl;
		this->price = price;
		this->speed = speed;
	}

	void setSpeed(int speed){
		if(speed<0){
			cout<<"Invalid!"<<endl;
			return;
		}
		this->speed = speed;
	}

	void setModel(int model_no){
		this->model_no = model_no;
	}

	int getSpeed(){
		return this->speed;
	}

	int getModel(){
		return this->model_no;
	}

	void printDetail(){
		cout<<name<<endl;
		cout<<speed<<endl;
		cout<<model_no<<endl;
	}

	Car(Car &X){
		this->speed = X.speed;
		model_no = X.model_no;
		strcpy(name,X.name);
	}
};

// void check(int *a,int n){
// 	for(int i=0;i<n;i++){
// 		cout<<a[i]<<" ";
// 	}
// 	cout<<endl;
// }

int main(){

	// Car A;

	// A.speed = 100;
	// cout<<A.speed<<endl;
	// A.model_no = 15;
	// cout<<A.model_no<<endl;

	// // A.Car();

	// cout<<"***************"<<endl;
	// Car B;
	// B.model_no = 123;
	// cout<<B.model_no<<endl;
	// cout<<B.speed<<endl;


	// Car C(10,123,"Creta");
	// // cout<<C.speed<<endl;
	// // cout<<C.model_no<<endl;
	// // cout<<C.price<<endl;
	// // C.name[0] = 'Q';
	// // cout<<C.name<<endl;

	// cout<<C.getSpeed()<<endl;
	// C.setSpeed(-456);

	// C.printDetail();


	// cout<<"***************"<<endl;
	// Car D(700,"First");

	// cout<<D.speed<<endl;
	// cout<<D.model_no<<endl;
	// cout<<D.price<<endl;
	// cout<<D.name<<endl;

	// cout<<"***************"<<endl;
	// Car E(300,120000);
	// cout<<E.speed<<endl;
	// cout<<E.model_no<<endl;
	// cout<<E.price<<endl;
	// cout<<E.name<<endl;



	// //Copy Constructor
	// Car A(300,12,"Suzuki");
	// cout<<"**************"<<endl;
	// Car B(A);
	// B.name[0] = 'Y';
	// B.printDetail();
	// A.printDetail();

	int *a = new int(10);
	int *arr = new int[3];

	for(int i=0;i<3;i++){
		arr[i] = i+1;
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	// int a = 10;
	// int arr[3]={1,2,3};

	// check(arr,3);

	// int a;
	// char b;
	// bool c;
	// float f;
	string s;

	delete a;
	delete [] arr;

	return 0;

}