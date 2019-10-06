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

int uniqueNumber(int arr[],int s,int e){
	if(s>e){
		return -1;
	}

	int mid = s + (e-s)/2;

	if(arr[mid-1]!=arr[mid] and arr[mid+1]!=arr[mid]){
		return mid;
	}

	if(mid&1){
		if(arr[mid]==arr[mid-1]){
			return uniqueNumber(arr,mid+1,e);
		}else{
			return uniqueNumber(arr,s,mid-1);
		}
	}else{
		if(arr[mid]==arr[mid+1]){
			return uniqueNumber(arr,mid+2,e);
		}else{
			return uniqueNumber(arr,s,mid-2);
		}
	}
}

void quickSort(int arr[],int low,int high){
	if(low>=high){
		return;
	}

	int mid = low + (high-low)/2;

	int pivot = arr[mid];

	int left = low;
	int right = high;

	while(left<=right){

		while(arr[left]<pivot){
			left++;
		}

		while(arr[right]>pivot){
			right--;
		}

		if(left<=right){
			swap(arr[left],arr[right]);
			left++;
			right--;
		}

	}

	quickSort(arr,low,right);
	quickSort(arr,left,high);

}

bool isValid(int arr[],int n,int k,int mid){

	int painters = 1;
	int painterTime = 0;

	for(int i=0;i<n;i++){

		painterTime+=arr[i];

		if(painterTime>mid){
			painters++;
			painterTime = arr[i];

			if(painters>k){
				return false;
			}

		}

	}

	return true;

}	

int painterProblem(int arr[],int n,int k,int time=1){

	int minTime = 40;

	int maxTime = 130;

	int ans = maxTime;

	while(minTime<=maxTime){

		int mid = minTime + (maxTime-minTime)/2;

		if(isValid(arr,n,k,mid)){

			ans = mid;
			maxTime = mid-1;

		}else{

			minTime = mid+1;

		}

	}

	return ans*time;

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


	// int arr[] = {5,6,7,1,2,3,4};
	// cout<<rotatedArray(arr,0,6,2)<<endl;


	// int arr[] = {1,3,3,5,5,6,6,7,7,8,8};
	// cout<<uniqueNumber(arr,0,10)<<endl;

	// int arr[] = {7,6,5,4,3,2,1};
	// quickSort(arr,0,6);

	// for(int i=0;i<7;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	int arr[] = {25,30,35,40};
	cout<<painterProblem(arr,4,2)<<endl;


	// int x = 2147483647;
	// cout<<x<<endl;

	// x++;

	// cout<<x<<endl;

	// x = x+2;

	// cout<<x<<endl;

	return 0;
}