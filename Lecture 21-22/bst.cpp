#include <iostream>
#include <queue>
#include <cmath>	
#include <climits>

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

bool search(node*root,int item){
	if(root==NULL){
		return false;
	}
	
	if(root->data==item){
		return true;
	}	

	if(item>root->data){
		return search(root->right,item);
	}else{
		return search(root->left,item);
	}
}

bool isBST(node*root,int minRange=INT_MIN,int maxRange=INT_MAX){
	if(root==NULL){
		return true;
	}

	bool leftBST = isBST(root->left,minRange,root->data);
	bool rightBST = isBST(root->right,root->data,maxRange);

	if(leftBST and rightBST and root->data > minRange and root->data < maxRange){
		return true;
	}else{
		return false;
	}
}

int firstTimeVisitLevel = 0;

void leftView(node*root,int level){
	if(root==NULL){
		return;
	}

	if(firstTimeVisitLevel == level){
		cout<<root->data<<" ";
		firstTimeVisitLevel++;
	}

	leftView(root->left,level+1);
	leftView(root->right,level+1);
}

void leftBoundary(node*root){
	if(root==NULL){
		return;
	}

	if(root->left==NULL and root->right==NULL){
		return;
	}

	cout<<root->data<<" ";

	if(root->left!=NULL){
		leftBoundary(root->left);
	}else{
		leftBoundary(root->right);
	}
}

void printLeaf(node*root){
	if(root==NULL){
		return;
	}

	if(root->left==NULL and root->right==NULL){
		cout<<root->data<<" ";
		return;
	}

	printLeaf(root->left);
	printLeaf(root->right);
}

int main(){

	node* root = buildTree();

	// displayInorder(root);
	// cout<<endl;
	// displayPreorder(root);
	// cout<<endl;

	// cout<<isBST(root)<<endl;

	// leftView(root,0);
	// cout<<endl;

	// leftBoundary(root);
	// cout<<endl;

	// printLeaf(root);
	// cout<<endl;

	return 0;
}

// 8 5 1 6 7 2 3 10 12 13 14 -1