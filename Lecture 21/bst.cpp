#include <iostream>
#include <queue>
#include <cmath>	

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right =NULL;
	}
};

node* construct(node* root,int data){
	if(root==NULL){
		node* root = new node(data);
		return root;
	}

	if(data>root->data){
		root->right = construct(root->right,data);
	}else{
		root->left = construct(root->left,data);
	}

	return root;
}

node* buildTree(){

	int data;
	cin>>data;

	node* root = NULL;

	while(data!=-1){
		root = construct(root,data);
		cin>>data;
	}

	return root;
}

void displayInorder(node*root){
	if(root==NULL){
		return;
	}

	displayInorder(root->left);
	cout<<root->data<<" ";
	displayInorder(root->right);
}

void displayPreorder(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	displayPreorder(root->left);
	displayPreorder(root->right);
}

int main(){

	node* root = buildTree();

	displayInorder(root);
	cout<<endl;
	displayPreorder(root);
	cout<<endl;

	return 0;
}