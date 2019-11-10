#include <iostream>
#include <unordered_map>
#include <list>

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

void printUnion(int arr[],int n,int brr[],int m){

	unordered_map<int,bool> checkElement;

	for(int i=0;i<n;i++){
		int key = arr[i];
		if(checkElement.find(key)==checkElement.end()){
			cout<<key<<" ";
			checkElement[key] = true;
		}
	}

	for(int i=0;i<m;i++){
		int key = brr[i];
		if(checkElement.find(key)==checkElement.end()){
			cout<<key<<" ";
			checkElement[key] = true;
		} 
	}

	cout<<endl;
}

bool subarraySumZero(int arr[],int n){

	unordered_map<int,bool> arr_sum;

	int sum = 0;

	arr_sum[sum] = true; 

	for(int i=0;i<n;i++){

		sum+=arr[i];

		if(arr_sum.find(sum)!=arr_sum.end()){
			return true;
		}

		arr_sum[sum] = true;
	}

	return false;
}

int countSubarraySumK(int arr[],int n,int k){

	unordered_map<int,int> arr_sum;

	int sum = 0;
	int count = 0;

	for(int i=0;i<n;i++){

		sum+=arr[i];

		if(arr_sum.find(sum-k)!=arr_sum.end()){
			count+=arr_sum[sum-k];
		}

		arr_sum[sum]++;
	}

	return count;
}

int longestConsecutiveSubsequence(int arr[],int length){

	unordered_map<int,int> maxSubs;

	int maxLen = 0;

	for(int i=0;i<length;i++){

		int n = arr[i];

		if(maxSubs.find(n)==maxSubs.end()){


			int left = maxSubs.find(n-1)==maxSubs.end() ? 0: maxSubs[n-1];
			int right = maxSubs.find(n+1)==maxSubs.end() ? 0: maxSubs[n+1];

			int sum = left + right + 1;

			// cout<<left<<right<<sum<<endl;

			maxLen = max(maxLen,sum);

			maxSubs[n] = sum;

			maxSubs[n-left] = sum;
			maxSubs[n+right] = sum;
		}

	}

	return maxLen;
}

int main(){

	// int arr[] = {1,2,3,3,3,5};
	// int brr[] = {1,2,2,3,6};
	// insersection(arr,6,brr,4);
	// printUnion(arr,6,brr,5);

	// int arr[] = {2,3,0,0,0,0,0,0,1,2,2};
	// int k = 3;
	// cout<<countSubarraySumK(arr,11,k)<<endl;

	// int arr[] = {4,4,100,3,2,200,1,1};
	// cout<<longestConsecutiveSubsequence(arr,8)<<endl;

	unordered_map<int, list<int> > m;

	return 0;
}