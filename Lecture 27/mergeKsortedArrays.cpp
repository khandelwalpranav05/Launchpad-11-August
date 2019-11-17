#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class ArrayPoint{
public:
	int value;
	int kth;
	int idx;

	ArrayPoint(int value,int kth,int idx){
		this->value = value;
		this->kth = kth;
		this->idx = idx;
	}

};

class PointCompare{
public:
	bool operator()(ArrayPoint a,ArrayPoint b){
		return a.value > b.value;
	}
};

int main(){

	int arr[3][5] = {
		{1,4,7,10,0},
		{2,5,8,0,0},
		{3,6,9,11,0}
	};

	vector<int> v;

	priority_queue<ArrayPoint,vector<ArrayPoint>,PointCompare > pq;

	for(int i=0;i<3;i++){
		ArrayPoint obj(arr[i][0],i,0);
		pq.push(obj);
	}

	while(pq.top().value!=INT_MAX){
			
		ArrayPoint temp = pq.top();
		pq.pop();

		v.push_back(temp.value);

		int pos = temp.idx + 1;
		int kth = temp.kth;

		int newValue = arr[kth][pos];

		if(newValue==0){
			newValue = INT_MAX;
		}

		ArrayPoint obj(newValue,kth,pos);
		pq.push(obj);
	}

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	return 0;
}