#include <iostream>

using namespace std;

void merge(int arr[],int s,int e){

	int temp[e-s+1];

	int mid = (s+e)/2;

	int i = s;
	int j = mid+1;
	int k = 0;

	while(i<=mid and j<=e){

		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			i++;
		}else{
			temp[k] = arr[j];
			j++;
		}

		k++;
	}

	while(j<=e){
		temp[k] = arr[j];
		k++;
		j++;
	}

	while(i<=mid){
		temp[k] = arr[i];
		k++;
		i++;
	}

	int p=0;
	for(int x = s; x<= e; x++){
		arr[x] = temp[p++];
	}
}

void mergeSort(int arr[],int s,int e){
	if(s==e){
		return;
	}

	int mid = (s+e)/2;

	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	merge(arr,s,e);

}

int binarySearch(int arr[],int n,int data){

	int s = 0;
	int e = n-1;

	while(s<=e){

		// int mid = (s+e)/2;
		int mid = s + (e-s)/2;

		if(arr[mid]==data){
			return mid;
		}else if(arr[mid]>data){
			e = mid-1;
		}else{
			s = mid+1;
		}

	}

	return -1;
}

int lowerBound(int arr[],int n,int data){
	int s = 0;
	int e = n-1;

	int ans = -1;

	while(s<=e){

		int mid = (s+e)/2;

		if(arr[mid]==data){
			ans = mid;
			e = mid-1;
		}else if(arr[mid]>data){
			e = mid-1;
		}else{
			s = mid+1;
		}

	}

	return ans;

}

int upperBound(int arr[],int n,int data){
	// TODO
}

int rotatedArray(int arr[],int s,int e,int data){
	if(s>e){
		return -1;
	}

	int mid = s + (e-s)/2;

	if(arr[mid]==data){
		return mid;
	}

	if(arr[s]<=arr[mid]){
		if(data>=arr[s] and data<=arr[mid]){
			return rotatedArray(arr,s,mid-1,data);
		}else{
			return rotatedArray(arr,mid+1,e,data);
		}

	}else{

		if(data>=arr[mid] and data<=arr[e]){
			return rotatedArray(arr,mid+1,e,data);
		}else{
			return rotatedArray(arr,s,mid-1,data);
		}

	}

}

int main(){

	// int arr[] = {5,4,3,2,1};
	// mergeSort(arr,0,4);

	// for(int i=0;i<5;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;


	// int arr[] = {2,2,2,2,2,4,5,6};
	// cout<<lowerBound(arr,8,2)<<endl;


	int arr[] = {5,6,7,1,2,3,4};
	cout<<rotatedArray(arr,0,6,2)<<endl;

	// int x = 2147483647;
	// cout<<x<<endl;

	// x++;

	// cout<<x<<endl;

	// x = x+2;

	// cout<<x<<endl;

	return 0;
}