#include <iostream>

using namespace std;

template <typename T>
class Stack{

	T *arr;
	int top;
	int capacity;

public:
	Stack(int capacity = 10){
		this->capacity = capacity;
		arr = new T[this->capacity];
		top = -1;
	}

	int size(){
		return top+1;
	}

	bool empty(){
		return size()==0;
	}

	T last(){
		if(empty()){
			cout<<"Stack is empty"<<endl;
			return 0;
		}

		return arr[top];
	}

	void push(T data){
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

	// Stack<int> s(5);

	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// s.push(5);
	// s.push(6);

	// cout<<s.last()<<endl;
	// s.pop();

	// cout<<s.last()<<endl;
	// s.pop();
	// s.pop();
	// s.pop();

	// cout<<s.last()<<endl;

	Stack<char> s(5);

	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.push('R');
	s.push('I');

	cout<<s.last()<<endl;
	s.pop();

	cout<<s.last()<<endl;
	s.pop();
	s.pop();
	s.pop();

	cout<<s.last()<<endl;


	return 0;
}