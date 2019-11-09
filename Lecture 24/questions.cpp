#include <iostream>
#include <unordered_map>

using namespace std;

void insersection(int arr[],int n,int brr[],int m){

	unordered_map<int,int> countMap;

	for(int i=0;i<n;i++){
		countMap[arr[i]]++;
	}

	for(int i=0;i<m;i++){
		if(countMap.find(brr[i])!=countMap.end()){
			int key = brr[i];
			if(countMap[key]>0){
				cout<<key<<" ";
				countMap[key]--;
			}
		}
	}

}

int main(){

	int arr[] = {1,2,3,3,3,5};
	int brr[] = {1,2,2,3};

	return 0;
}