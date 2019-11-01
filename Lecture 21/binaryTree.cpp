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

node* buildTree(node*root){
	int data;
	cin>>data;

	if(data==-1){
		return NULL;
	}

	if(root==NULL){
		node* n = new node(data);
		root = n;
	}

	root->left = buildTree(root->left);
	root->right = buildTree(root->right);

	return root;
}

void displayPreorder(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	displayPreorder(root->left);
	displayPreorder(root->right);
}

void displayInorder(node*root){
	if(root==NULL){
		return;
	}

	displayInorder(root->left);
	cout<<root->data<<" ";
	displayInorder(root->right);
}

void displayPostorder(node*root){
	if(root==NULL){
		return;
	}

	displayPostorder(root->left);
	displayPostorder(root->right);
	cout<<root->data<<" ";
}

int countNodes(node*root){
	if(root==NULL){
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int totalCount = leftCount + rightCount + 1;
	return totalCount;
}

bool search(node*root,int item){
	if(root==NULL){
		return false;
	}

	if(root->data ==item){
		return true;
	}

	bool leftSearch = search(root->left,item);
	bool rightSearch = search(root->right,item);

	return leftSearch + rightSearch;
}

int height(node*root){
	if(root==NULL){
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalHeight = max(leftHeight,rightHeight) + 1;
	return totalHeight;
}

void levelOrder(node*root){
	queue<node*> q;

	q.push(root);

	while(!q.empty()){

		node* temp = q.front();
		q.pop();

		cout<<temp->data<<" ";

		if(temp->left!=NULL){
			q.push(temp->left);
		}

		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}

	cout<<endl;
}

void printAllRootToLeaf(node*root,string path){
	if(root==NULL){
		return;
	}

	char ch = root->data + '0';

	if(root->left==NULL and root->right==NULL){
		path = path + ch;
		cout<<path<<endl;
		return;
	}

	printAllRootToLeaf(root->left,path+ch);
	printAllRootToLeaf(root->right,path+ch);
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}

	int leftDiameter = diameter(root->left);
	int rightDiameter = diameter(root->right);

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalDiameter = max(leftHeight + rightHeight + 2,max(leftDiameter,rightDiameter));

	return totalDiameter;
}

class DiaHeight{
public:
	int diameter;
	int height;

	DiaHeight(){
		diameter = 0;
		height = -1;
	}
};

DiaHeight diameterOptimized(node*root){
	DiaHeight val;

	if(root==NULL){
		return val;
	}


	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	val.diameter = max(max(leftPair.diameter,rightPair.diameter),leftPair.height + rightPair.height + 2);

	val.height = max(leftPair.height,rightPair.height) + 1;

	return val;
}

bool isBalanced(node*root){
	if(root==NULL){
		return true;
	}

	bool leftBalanced = isBalanced(root->left);
	bool rightBalanced = isBalanced(root->right);

	if(!leftBalanced or !rightBalanced){
		return false;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int diff = abs(leftHeight - rightHeight);

	if(diff>1){
		return false;
	}else{
		return true;
	}
}

node* LCA(node*root,int data1,int data2){
	if(root==NULL){
		return NULL;
	}

	if(root->data==data1 or root->data==data2){
		return root;
	}

	node* leftLCA = LCA(root->left,data1,data2);
	node* rightLCA = LCA(root->right,data1,data2);

	if(leftLCA==NULL and rightLCA==NULL){
		return NULL;
	}

	if(leftLCA!=NULL and rightLCA!=NULL){
		return root;
	}

	return leftLCA!=NULL ? leftLCA : rightLCA;
}

int replaceWithSum(node*root){
	if(root==NULL){
		return 0;
	}

	int leftSum = replaceWithSum(root->left);
	int rightSum = replaceWithSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;

	return root->data + temp;
}

int main(){

	node* root = NULL;

	root = buildTree(root);
	// displayPreorder(root);
	// cout<<endl;
	// displayPostorder(root);
	// cout<<endl;
	// displayInorder(root);
	// cout<<endl;

	// cout<<countNodes(root)<<endl;

	// cout<<search(root,6)<<endl;
	// cout<<search(root,78)<<endl;

	// cout<<height(root)<<endl;

	// levelOrder(root);

	// printAllRootToLeaf(root,"");

	// cout<<diameter(root)<<endl;

	// DiaHeight val = diameterOptimized(root);
	// cout<<val.diameter<<endl;
	// cout<<val.height<<endl;

	// cout<<isBalanced(root)<<endl;

	node* common = LCA(root,1,7);
	cout<<common->data<<endl;

	common = LCA(root,5,7);
	cout<<common->data<<endl;

	return 0;
}

// 	