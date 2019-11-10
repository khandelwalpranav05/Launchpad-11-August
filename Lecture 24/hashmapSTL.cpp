#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

	unordered_map<string,int> m;

	m.insert(make_pair("US",12));
	m.insert(make_pair("UK",123));
	m.insert(make_pair("India",140));
	m.insert(make_pair("Pak",120));

	m["Mango"] = 70;

	pair<string,int> p("New Country",156);
	m.insert(p);

	for(auto node:m){
		cout<<node.first<<" "<<node.second<<endl;
	}

	// int arr[] = {1,1,2,3,6,9};
	// for(int i=0;i<len;i++){
	// 	cout<<arr[i];
	// }

	// for(int var:arr){
	// 	cout<<var;
	// }


	if(m.find("Mango")!=m.end()){
		cout<<"Found"<<endl;
	}

	if(m.find("skjbf")==m.end()){
		cout<<"Not Found"<<endl;
	}

	// int arr[] = {1,2,3,4,5,6};
	// int brr[] = {8,9,7,2,3,7};

	return 0;
}