#include <iostream>

using namespace std;

int powerBetter(int n,int p){
	if(p==0){
		return 1;
	}

	int powernby2 = powerBetter(n,p/2);

	if(p&1){
		int power = powernby2*powernby2*n;
		return power;
	}else{
		int power = powernby2*powernby2;
		return power;
	}
} 

int fib(int n){
	if(n==0 or n==1){
		return n;
	}

	int fibn1 = fib(n-1);
	int fibn2 = fib(n-2);

	int fibAtn = fibn1 + fibn2;
	return fibAtn;

	// if(n==0 or n==1){
	// 	return n;
	// }

	// return fib(n-1) + fib(n-2);
}

string addStar(string str){
	if(str.length()==0){
		return "";
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursion_result = addStar(ros);

	if(ch==recursion_result[0]){
		string star = "*";
		return ch + "*" + recursion_result;
	}else{
		return ch + recursion_result;
	}
}

string moveXtoEnd(string str){
	//Base Case
	if(str.length()==0){
		return str;
		// return "";
	}

	//Recursive Case
	char ch = str[0];
	string ros = str.substr(1);

	string recursion_result = moveXtoEnd(ros);

	if(ch=='x'){
		return recursion_result + ch;
	}else{
		return ch + recursion_result;
	}
}

string replacePi(string str){
	//Base Case
	if(str.length()==0){
		return str;
	}

	//Recursive Case

	char ch = str[0];
	string ros = str.substr(1);

	string recursion_result = replacePi(ros);

	if(ch=='p' and recursion_result[0]=='i'){
		return "3.14" + recursion_result.substr(1); 
	}else{
		return ch + recursion_result;
	}
}

string removeDuplicate(string str){
	//Base Case
	if(str.length()==0){
		return str;
	}

	//Recursive Case
	char ch = str[0];
	string ros = str.substr(1);

	string recursion_result = removeDuplicate(ros);

	if(ch==recursion_result[0]){
		return recursion_result;
	}else{
		return ch + recursion_result;
	}
}

// int check = 0;

void printSubsequence(string str,string ans){
	// check++;
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros,ans);
	printSubsequence(ros,ans+ch);

}

int main()
{
	// cout<<powerBetter(2,8)<<endl;
	// cout<<fib(7)<<endl;	

	// cout<<addStar("aahelloo")<<endl;

	// cout<<(('a' + "kjbsdb") + 'l')<<endl;
	// cout<<sizeof("abcd")<<endl; //Character array

	// cout<<moveXtoEnd("abaxxbjdnaxxpx")<<endl;
	// cout<<moveXtoEnd("xxxxxxxlsefn")<<endl;

	//Mat Karo
	// cout<<("abc" - "bc")<<endl;
	// int arr[] = {-12,2,789};
	// cout<<(&arr[10])<<endl<<(&arr[0])<<endl;
	// cout<<(&arr[10] - &arr[0])<<endl;

	// cout<<replacePi("xxxpixxpipixxipipxxxpixxxiipii");

	// cout<<removeDuplicate("aaabbbcccbss")<<endl;
	// cout<<removeDuplicate("ghjkl")<<endl;

	printSubsequence("abc","");
	cout<<check<<endl;

	return 0;
}