#include <iostream>

using namespace std;

// int dp[100][100] = {0};

// int lcs(string s1,string s2){
// 	if(s1.length()==0 or s2.length()==0){
// 		dp[s1.length()][s2.length()] = 0;
// 		return 0;
// 	}

// 	if(dp[s1.length()][s2.length()]!=0){
// 		return dp[s1.length()][s2.length()];
// 	}

// 	char ch1 = s1[0];
// 	char ch2 = s2[0];

// 	string ros1 = s1.substr(1);
// 	string ros2 = s2.substr(1);

// 	int result = 0;

// 	if(ch1==ch2){
// 		result = lcs(ros1,ros2) + 1;
// 	}else{

// 		int count1 = lcs(s1,ros2);
// 		int count2 = lcs(ros1,s2);

// 		result = max(count1,count2);
// 	}

// 	dp[s1.length()][s2.length()] = result;

// 	for(int i=0;i<=5;i++){
// 		for(int j=0;j<=6;j++){
// 			cout<<dp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<"**************"<<endl;

// 	return result;
// }

int lcs_DP(string s1,string s2){

	int n = s1.length() + 1;
	int m = s2.length() + 1;

	int lcsDP[n][m];

	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){

			if(i==0 or j==0){
				lcsDP[i][j] = 0;
				continue;
			}

			if(s1[i]==s2[j]){

				lcsDP[i][j] =  1 + lcsDP[i-1][j-1];

			}else{
				lcsDP[i][j] = max(lcsDP[i-1][j],lcsDP[i][j-1]);
			}

		}
	}

	return lcsDP[n-1][m-1];
}

int dp[100][100] = {0};

int editDistance(string s1,string s2){
	if(s1.length()==0){
		dp[s1.length()][s2.length()] = s2.length();
		return s2.length();
	}

	if(s2.length()==0){
		dp[s1.length()][s2.length()] = s1.length();
		return s1.length();
	}

	if(dp[s1.length()][s2.length()]!=0){
		return dp[s1.length()][s2.length()];
	}

	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1);
	string ros2 = s2.substr(1);

	int result = 0;

	if(ch1==ch2){
		result = editDistance(ros1,ros2);
	}else{
		int insertion = editDistance(s1,ros2);
		int deletetion = editDistance(ros1,s2);
		int replace = editDistance(ros1,ros2);

		result = min(insertion,min(deletetion,replace));
		result+=1;
	}

	dp[s1.length()][s2.length()] = result;

	for(int i=0;i<=8;i++){
		for(int j=0;j<=6;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"****************"<<endl;

	return result;
}

int main(){

	// cout<<lcs("aqbeh","qaeibh")<<endl;

	// cout<<lcs_DP("aqbeh","qaeibh")<<endl;

	cout<<editDistance("Saturday","Sunday")<<endl;
	return 0;
}