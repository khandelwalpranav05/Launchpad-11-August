#include <iostream>

using namespace std;

string ultraFast(string s1,string s2){
	for(int i=0;i<s1.length();i++){

		if(s1[i]==s2[i]){
			// cout<<'0';
			s1[i] = '0';
		}else{
			// cout<<'1';
			s1[i] = '1';
		}

	}

	return s1;
}

void display(int arr[4][4], int n){
	cout<<"************** \n";
	for(int i=0;i<n;i++){
		cout<<"[ ";
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"] "<<endl;
	}
}

void rotate(int arr[4][4],int n){
// Rotating the matrix by first transposing it and then mirroring it

	for(int row=0;row<n;row++){

		for(int col=row+1;col<n;col++){

			swap(arr[row][col],arr[col][row]);

		}

	}

	for(int col=0;col<n/2;col++){

		for(int row=0;row<n;row++){

			swap(arr[row][col],arr[row][n-1-col]);

		}

	}

}

int count = 0;

void subsetSum(int arr[],int i,int n,int sum){

	subsetSum(arr,i+1,n,sum);
	subsetSum(arr,i+1,n,sum+arr[i]);

	//TODO
}

void generateParathesis(int n,int openingB,int closingB,string ans){
	if(closingB==n){
		//string -> build
		cout<<ans<<endl;
		return;
	}

	if(openingB > closingB){
		generateParathesis(n,openingB,closingB+1,ans+')');
	}

	if(openingB < n){
		generateParathesis(n,openingB+1,closingB,ans+'(');
	}
}

int optimalGame(int arr[],int i,int j){
	if(i>j){
		return 0;
	}

	int result;

	int first = arr[i] + min(optimalGame(arr,i+2,j),optimalGame(arr,i+1,j-1));
	int last = arr[j] + min(optimalGame(arr,i+1,j-1),optimalGame(arr,i,j-2));

	result = max(first,last);

	return result;
}

int tillingProblem(int n){
	// if(n==1){
	// 	return 1;
	// }

	// if(n==2){
	// 	return 2;
	// }
	if(n==1 or n==2){
		return n;
	}

	int horizontal = tillingProblem(n-2);
	int vertical = tillingProblem(n-1);

	int total=horizontal+vertical;
	return total;
}

int main(){

	// string s1 = "10111";
	// string s2 = "10000";

	// cout<<ultraFast(s1,s2)<<endl;

	// int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	// display(arr,4);

	// rotate(arr,4);

	// display(arr,4);

}