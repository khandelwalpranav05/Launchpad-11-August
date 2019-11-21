#include <iostream>
#include <unordered_map>

using namespace std;

class node{
public:
	char data;
	unordered_map<char,node*> h;
	bool isTerminal;

	node(char data){
		this->data = data;
		this->isTerminal = false;
	}
};

class Trie{
	node* root;

public:
	Trie(){
		root = new node('\0');
	}

	void addWord(string str){
		node* temp = root;

		for(int i = 0;i<str.length();i++){

			char ch = str[i];

			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				node* child = new node(ch);
				temp->h[ch] = child;
				temp = temp->h[ch];
			}
		}

		temp->isTerminal = true;
	}

	bool search(string str){

		node* temp = root;
		for(int i=0;i<str.length();i++){

			char ch = str[i];

			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				return false;
			}
		}

		return temp->isTerminal;
	}
};

int main(){

	Trie t;

	string arr[] = {"application","apple","ape","app","mango","news","noted","note"};

	for(int i=0;i<8;i++){
		t.addWord(arr[i]);
	}

	cout<<t.search("app")<<endl;
	cout<<t.search("new")<<endl;

	return 0;
}