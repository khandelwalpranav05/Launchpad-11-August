#include <iostream>

using namespace std;

class Stack{

	int *arr;
	int top;
	int capacity;

public:
	Stack(int capacity = 10){
		this->capacity = capacity;
		arr = new int[this->capacity];
		top = -1;
	}

	int size(){
		return top+1;
	}

	bool empty(){
		return size()==0;
	}

	int last(){
		if(empty()){
			cout<<"Stack is empty"<<endl;
			return -1;
		}

		return arr[top];
	}

	void push(int data){
		if(size()==capacity){
			cout<<"Stack is full"<<endl;
			return;
		}

		arr[++top] = data;
	}

	void pop(){
		if(empty()){
			cout<<"Stack is empty"<<endl;
			return;
		}

		top--;
	}
};

int main(){

	Stack s(5);

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);

	cout<<s.last()<<endl;
	s.pop();

	cout<<s.last()<<endl;
	s.pop();
	s.pop();
	s.pop();

	cout<<s.last()<<endl;

	return 0;
}