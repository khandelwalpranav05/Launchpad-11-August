#include <iostream>

using namespace std;

bool balancedParathesis(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch=='('){
			s.push(ch);
		}else{

			if(!s.empty() and s.top()=='('){
				s.pop();
			}else{
				return false;
			}

		}

	}
	
	return s.empty();
}


int main(){

	cout<<balancedParathesis("(()))")<<endl;

	return 0;
}