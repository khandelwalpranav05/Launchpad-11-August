#include <iostream>
#include <stack>

using namespace std;

int main(){

	stack<char> s;

	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.push('R');
	s.push('I');

	cout<<s.top()<<endl;
	s.pop();

	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	s.pop();

	cout<<s.top()<<endl;

	return 0;
}