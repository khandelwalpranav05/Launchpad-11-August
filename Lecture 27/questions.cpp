#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minCost(){
	int arr[] = {4,2,3,6};

	priority_queue<int,vector<int>,greater<int> > pq;
	// priority_queue<int> pq;

	for(int i=0;i<4;i++){
		pq.push(arr[i]);
	}

	int sum = 0;
	int first = pq.top();
	pq.pop();

	while(!pq.empty()){
		int second = pq.top();
		pq.pop();

		first+=second;

		sum+=first;
	}

	return sum;
}

int kthLargestElement(){
	
}

int main(){

	cout<<minCost()<<endl;

	return 0;
}