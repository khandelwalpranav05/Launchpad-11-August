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

int kthLargestElement(int arr[],int n,int k){

	priority_queue<int,vector<int>,greater<int> > pq;

	for(int i=0;i<n;i++){
		if(k!=0){
			pq.push(arr[i]);
			k--;
			continue;
		}

		if(arr[i]>pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}

	return pq.top();
}

void heapify(int arr[],int n,int i){

	int left = 2*i + 1;
	int right = 2*i + 2;

	int largestIndex = i;

	if(right<n and arr[right]>arr[largestIndex]){
		largestIndex = right;
	}

	if(left<n and arr[left]>arr[largestIndex]){
		largestIndex = left;
	}

	if(largestIndex!=i){
		swap(arr[i],arr[largestIndex]);
		heapify(arr,n,largestIndex);
	}
}

void arrayToHeap(int arr[],int n){

	for(int i=n-1;i>=0;i--){
		heapify(arr,n,i);
	}

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void heapSort(int arr[],int n){

	for(int i=n-1;i>=0;i--){
		heapify(arr,n,i);
	}

	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){

	// cout<<minCost()<<endl;

	// int arr[] = {3,2,1,6,7,0,5};
	// int n = 7;
	// cout<<kthLargestElement(arr,7,2)<<endl;

	int arr[] = {5,2,1,4,3,6};
	int n = 6;
	// arrayToHeap(arr,n);
	heapSort(arr,n);

	return 0;
}