#include <iostream>
#include <stack>

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

bool hasDuplicate(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch!=')'){
			s.push(ch);
		}else{
			
			char check = s.top();

			if(check=='('){
				return true;
			}

			while(s.top()!='('){
				s.pop();
			}
			s.pop();
		}

	}

	return false;
}

void stockSpan(int arr[],int n){

	stack<int> s;
	s.push(0);

	for(int i=1;i<n;i++){

		if(arr[i]<arr[s.top()]){
			int steps = i - s.top();
			cout<<steps<<" ";
		}else{
			while(arr[i]>arr[s.top()]){
				s.pop();
			}

			int steps = i - s.top();
			cout<<steps<<" ";
		}

		s.push(i);
	}

	cout<<endl;
}


int main(){

	// cout<<balancedParathesis("(()))")<<endl;

	// cout<<hasDuplicate("((a+b))")<<endl;

	int arr[] = {100,80,60,70,60,75,85};
	int n = 7;
	stockSpan(arr,n);

	return 0;
}