#include <iostream>
#include<climits>

using namespace std;

int storage[100] = {0,1};

int fibMemo(int n){
	if(n==0 or n==1){
		return n;
	}

	if(storage[n]!=0){
		return storage[n];
	}

	int fibn1 = fibMemo(n-1);
	int fibn2 = fibMemo(n-2);

	int fibn = fibn1 + fibn2;

	storage[n] = fibn;

	for(int i=0;i<=5;i++){
		cout<<storage[i]<<" ";
	}
	cout<<endl;

	return fibn;
}

int fib(int n){
	if(n==0 or n==1){
		return n;
	}

	int fibn1 = fib(n-1);
	int fibn2 = fib(n-2);

	int fibn = fibn1 + fibn2;

	return fibn;
}

int fib_DP(int n){

	int dp[n+1] = {0,1};

	for(int i= 2;i<= n;i++){

		dp[i] = dp[i-1] + dp[i-2];

		for(int i=0;i<=5;i++){
			cout<<dp[i]<<" ";
		}
		cout<<endl;

	}

	return dp[n];
}

int countBoardPath(int start,int end){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int dice=1;dice<=6;dice++){
		count+=countBoardPath(start+dice,end);
	}

	return count;
}

int countBoardPathMemo(int start,int end,int BoardDP[]){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	if(BoardDP[start]!=0){
		return BoardDP[start];
	}

	int count = 0;

	for(int dice=1;dice<=6;dice++){
		count+=countBoardPathMemo(start+dice,end,BoardDP);
	}

	BoardDP[start] = count;

	for(int i=0;i<10;i++){
		cout<<BoardDP[i]<<"	 ";
	}
	cout<<endl;

	return count;
}

int countBoardPath_DP(int start,int end){

	int BoardDP[end+1] = {0};
	BoardDP[end] = 1;

	for(int i = end-1;i>=0;i--){
		for(int dice = 1;dice<=6;dice++){

			if(dice + i>end){
				break;
			}

			BoardDP[i]+=BoardDP[i+dice];

		}
	}

	return BoardDP[start];
}

int reduceToOne(int n){
	if(n==1){
		return 0;
	}


	int count1 = INT_MAX;
	int count2 = INT_MAX;
	int count3 = INT_MAX;

	if(n%3==0){
		count3 = reduceToOne(n/3) + 1;
	}

	if(n%2==0){
		count2 = reduceToOne(n/2) + 1;
	}

	count1 = reduceToOne(n-1) + 1;

	return min(count1,min(count2,count3));

}

int reduceToOneMemo(int n,int reduceDP[]){
	if(n==1){
		return 0;
	}

	if(reduceDP[n]!=0){
		return reduceDP[n];
	}

	int count1 = INT_MAX;
	int count2 = INT_MAX;
	int count3 = INT_MAX;

	if(n%3==0){
		count1 = 1 + reduceToOneMemo(n/3,reduceDP);
	}

	if(n%2==0){
		count2 = 1 + reduceToOneMemo(n/2,reduceDP);
	}

	count3 = 1 + reduceToOneMemo(n-1,reduceDP);

	reduceDP[n] =  min(count1,min(count2,count3));

	for(int i=0;i<=10;i++){
		cout<<reduceDP[i]<<" "; 
	}
	cout<<endl;

	return reduceDP[n];
}

int main(){

	// clock_t start = clock();
	// fib(60);
	// clock_t end_1 = clock();
	// fibMemo(60);
	// clock_t end_2 = clock();
	
	// cout<<(end_1 - start)<<endl;
	// cout<<(end_2 - end_1)<<endl;

	// fibMemo(5);

	// cout<<fib_DP(5)<<endl;

	// int BoardDP[11] = {0};
	// BoardDP[10] = 1;
	// cout<<countBoardPathMemo(0,10,BoardDP)<<endl;

	// cout<<countBoardPath_DP(0,10)<<endl;

	// cout<<reduceToOne(10)<<endl;

	int reduceDP[11] = {0,0}; 
	cout<<reduceToOneMemo(10,reduceDP)<<endl;
	return 0;
}