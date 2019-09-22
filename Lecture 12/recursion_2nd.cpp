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

int main()
{
	// cout<<powerBetter(2,8)<<endl;
	// cout<<fib(7)<<endl;	

	// cout<<addStar("aahelloo")<<endl;

	// cout<<(('a' + "kjbsdb") + 'l')<<endl;

	cout<<sizeof("abcd")<<endl;

	return 0;
}