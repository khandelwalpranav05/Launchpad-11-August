#include <iostream>

using namespace std;

bool isPalindrome(string str){

	int left = 0;
	int right = str.length()-1;

	while(left<right){

		if(str[left]!=str[right]){
			return false;
		}

		left++;
		right--;
	}

	return true;
}

int countPalindromicSubstring(string str){

	int result = 0;

	for(int i=0;i<str.length();i++){

		//ODD
		for(int j= 0; i-j>=0 and i+j<str.length(); j++){

			if(str[i-j]==str[i+j]){
				result++;
			}else{
				break;
			}
		}

		//EVEN
		for(int j = 0; i+j+1<str.length() and i-j>=0 ; j++){

			if(str[i-j]==str[i+j+1]){
				result++;
			}else{
				break;
			}
		}
	}

	return result;

}

int countPalindromicSubstring_BAD(string str){

	int result = 0;
	for(int i=0;i<str.length();i++){

		for(int j=1;j<=str.length()-i;j++){
			result = result + isPalindrome(str.substr(i,j));
		}
	}

	return result;
}

void printSubstrings(string str){

	for(int i=0;i<str.length();i++){

		for(int j=1;j<=str.length()-i;j++){
			cout<<str.substr(i,j)<<endl;
		}

	}
}

int main(){

	// string str = "abcd";
	// cout<<str.substr(0,2)<<endl;

	// cout<<str.substr(1,3)<<endl;
	// cout<<str.substr(1,123)<<endl;
	// cout<<str.substr(1)<<endl;  //cout<<str.substr(0,-2)<<endl; (SAME)

	// cout<<str.substr(-1,2)<<endl; //Wrong

	// printSubstrings(str);

	string str = "naman";
	string s1 = "abcd";
	string s2 = "baabaa";
	cout<<countPalindromicSubstring(s2)<<endl;
	cout<<countPalindromicSubstring_BAD(s2)<<endl;

	return 0;
}