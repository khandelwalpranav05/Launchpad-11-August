#include <iostream>

using namespace std;

class Queue{

	int *arr;
	int front;
	int back;
	int maxSize;
	int currSize;

public:
	Queue(int maxSize){
		this->maxSize = maxSize;
		arr = new int[maxSize];
		front = 0;
		back = -1;
		currSize = 0;
	}

	bool isFull(){
		return currSize==maxSize;
	}

	bool empty(){
		return currSize==0;
	}

	int size(){
		return currSize;
	}

	int getFront(){
		return arr[front];
	}

	void push(int data){
		if(isFull()){
			cout<<"Queue is full"<<endl;
			return;
		}

		back = (back+1)%maxSize;
		arr[back] = data;
		currSize++;
	}

	void pop(){
		if(empty()){
			cout<<"Queue is empty"<<endl;
			return;
		}

		front = (front+1)%maxSize;
		currSize--;
	}

};

int main(){

	Queue q(5);

	q.push(12);
	q.push(2);
	q.push(122);
	q.push(13);
	q.push(178);
	q.push(1);

	cout<<q.getFront()<<endl;

	q.pop();
	q.pop();
	q.pop();
	q.pop();

	cout<<q.getFront()<<endl;

	q.pop();
	q.pop();

	return 0;
}