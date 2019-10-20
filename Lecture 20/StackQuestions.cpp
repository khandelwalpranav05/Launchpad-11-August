#include <iostream>
#include <stack>
#include <deque>

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

	for(int day=0;day<n;day++){

		int currPrice = arr[day];

		while(!s.empty() and arr[s.top()]<currPrice){
			s.pop();
		}

		int betterDays = s.empty() ? 0:s.top();
		int span = day - betterDays;
		cout<<span<<" ";
		s.push(day);
	}

	cout<<endl;
}

int histogramArea(int arr[],int n){

	stack<int> s;

	int max_area = 0;
	int i = 1;

	s.push(0);

	while(i<n){

		if(s.empty() or arr[i]>=arr[s.top()]){
			s.push(i);
			i++;
		}else{

			int extractTop = s.top();
			s.pop();

			int currentArea = 0;

			if(s.empty()){
				currentArea = arr[extractTop]*i;
			}else{
				currentArea = arr[extractTop]*(i - s.top() - 1);
			}

			if(currentArea>max_area){
				max_area = currentArea;
			}

		}
	}

	while(!s.empty()){

		int extractTop = s.top();
		s.pop();

		int currentArea = 0;

		if(s.empty()){
			currentArea = arr[extractTop]*i;
		}else{
			currentArea = arr[extractTop]*(i - s.top() - 1);
		}

		if(currentArea>max_area){
			max_area = currentArea;
		}
	}	

	return max_area;
}

int largestBinarySubrrayArea(int arr[][4]){

	//TODO

}

int gasStationProblem(int arr[],int n,int brr[]){

	//TODO

}

void slidingWindow(int arr[],int n,int k){

	deque<int> q(k);
	int i;

	for(i=0;i<k;i++){
		while(!q.empty() and arr[i]>=arr[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}

	for(i;i<n;i++){
		// cout<<arr[q.front()]<<" ";

		int count = 0;

		while(!q.empty() and q.front()<=i-k){
			count++;
			q.pop_front();
		}

		cout<<count<<endl;

		while(!q.empty() and arr[i]>=arr[q.back()]){
			q.pop_back();
		}

		q.push_back(i);
	}

	// cout<<arr[q.front()]<<endl;
}

int main(){

	// cout<<balancedParathesis("(()))")<<endl;

	// cout<<hasDuplicate("((a+b))")<<endl;

	// int arr[] = {100,80,60,70,60,75,85};
	// int n = 7;
	// stockSpan(arr,n);

	// int arr[] = {2,1,2,3,1};
	// int n = 5;

	// cout<<histogramArea(arr,n)<<endl;

	// int arr[] = {12,1,78,90,56,89,57};
	// int n = 7;
	// slidingWindow(arr,n,3);

	return 0;
}