#include <iostream>
#include <math.h>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	node(){
		this->left = NULL;
		this->right = NULL;
	}
};

void addNumber(node* root,int data){

	for(int i=31;i>=0;i--){

		int bit = (data>>i)&1;

		if(bit){
			if(!root->right){
				node* one = new node();
				root->right = one;
			}

			root = root->right;
		}else{

			if(!root->left){
				node* zero = new node();
				root->left = zero;
			}

			root = root->left;
		}
	}
}

int maxXor(int arr[],int n,node* root){

	int maxXorValue = 0;

	for(int i=0;i<n;i++){
			
		int val = arr[i];

		int currMax = 0;

		node* temp = root;

		for(int j=31;j>=0;j--){

			// cout<<val<<endl;
			int bit = (val>>j)&1;

			if(bit){
				if(temp->left){
					currMax += pow(2,j);
					temp = temp->left;
				}else{
					temp = temp->right;
				}

			}else{
				if(temp->right){
					temp = temp->right;
					currMax += pow(2,j);
				}else{
					temp = temp->left;
				}
			}
		}

		maxXorValue = max(currMax,maxXorValue);
	}

	return maxXorValue;
}

int main(){

	int arr[] = {1,2,3,4};
	node* root = new node();

	for(int i=0;i<4;i++){
		addNumber(root,arr[i]);
	}

	int val = maxXor(arr,4,root);
	cout<<val<<endl;

	return 0;
}