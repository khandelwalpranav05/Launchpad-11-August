#include <iostream>

using namespace std;

bool isPalindrome(string str){

	int left = 0;
	int right = str.length()-1;

	while(left<right){

		// if(str[left]==str[right]){
		// 	left++;
		// 	right--;
		// 	continue;
		// }else{
		// 	return false;
		// }

		if(str[left]!=str[right]){
			return false;
		}

		left++;
		right--;
	}

	return true;
}

string toggle(string str){

	for(int i=0;i<str.length();i++){

		if(str[i]>='A' and str[i]<='Z'){
			str[i] = str[i] + 'a' - 'A';

		}else if(str[i]>='a' and str[i]<='z'){
			str[i] = str[i] + 'A' - 'a';
		}

	}

	return str;
}

int max_frequency(string str){

	int count[128] = {0};

	for(int i=0;i<str.length();i++){

		// char ch = str[i];
		// int idx = ch;
		// count[idx]++;

		count[str[i]]++;
	}

	int max = count[0];
	int max_char = 0;

	for(int i=0;i<128;i++){
		if(count[i]>max){

			max_char = i;

			max = count[i];
		}
	}
	cout<<((char)max_char)<<endl;
	return max;

}

int main(){
	//******************************
	// string str = "Launchpad";

	// cout<<sizeof(str)<<endl;
	// cout<<str.length()<<endl;

	// cout<<str[2]<<endl; // "u"  'u'

	// int x = 10;
	// int *xptr = &x;
	// cout<<sizeof(xptr)<<endl;

	// string s1 = "Pranav";
	// string s2 = "Pranav";

	// cout<<(s1==s2)<<endl;

	// cout<<(&s1)<<endl;
	// cout<<(&s2)<<endl;


	// string a = "acwgfbsjbfjs";
	// string b = "bc";

	// cout<<(a>b)<<endl;

	//******************************

	// string str = "Samarth";
	// cout<<(&str)<<endl;
	// str[3] = 'O';

	// cout<<str<<endl;
	// cout<<(&str)<<endl;

	//****************************

	// cout<<((char)90)<<endl;

	// string toggle_str = "HelLo";
	// cout<<toggle(toggle_str)<<endl;

	string str_freq = "aaaabbbbccchhbbaaa";
	cout<<max_frequency(str_freq)<<endl;


	return 0;
}