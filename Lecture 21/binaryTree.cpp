#include <iostream>
#include <queue>

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

	return 0;
}

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1