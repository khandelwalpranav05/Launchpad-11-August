#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue<int> q;

	q.push(12);
	q.push(2);
	q.push(122);
	q.push(13);
	q.push(178);
	q.push(1);

	cout<<q.front()<<endl;

	q.pop();
	q.pop();
	q.pop();
	q.pop();

	cout<<q.front()<<endl;

	q.pop();
	q.pop();
	
	// q.pop();
	// q.pop();
	// q.pop();
	

	return 0;
}