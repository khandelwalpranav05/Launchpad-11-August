#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

	// priority_queue<int> pq;

	priority_queue<int,vector<int>,greater<int> > pq;

	pq.push(15);
	pq.push(5);
	pq.push(2);
	pq.push(156);
	pq.push(4);
	pq.push(6);
	pq.push(160);

	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}

	return 0;
}