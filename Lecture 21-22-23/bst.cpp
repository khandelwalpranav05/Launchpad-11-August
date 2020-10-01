#include <iostream>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* construct(node* root, int data) {
	if (root == NULL) {
		node* root = new node(data);
		return root;
	}

	if (data > root->data) {
		root->right = construct(root->right, data);
	} else {
		root->left = construct(root->left, data);
	}

	return root;
}

node* constructIteratively(struct node* root, int data) {

	struct node *p == root, *q = new node(data);

	if (root == NULL)
		return q;

	while (true) {
		if (data < p->val) {
			if (p->left == NULL) {
				p->left = q;
				break;
			}
			p = p->left;
		}
		else (data > p->val) {
			if (p->right == NULL) {
				p->right = q;
				break;
			}
			p = p->right;
		}
	}

	return root;
}

node* buildTree() {

	int data;
	cin >> data;

	node* root = NULL;

	while (data != -1) {
		root = construct(root, data);
		cin >> data;
	}

	return root;
}

void displayInorder(node*root) {
	if (root == NULL) {
		return;
	}

	displayInorder(root->left);
	cout << root->data << " ";
	displayInorder(root->right);
}

void displayPreorder(node*root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	displayPreorder(root->left);
	displayPreorder(root->right);
}

bool search(node*root, int item) {
	if (root == NULL) {
		return false;
	}

	if (root->data == item) {
		return true;
	}

	if (item > root->data) {
		return search(root->right, item);
	} else {
		return search(root->left, item);
	}
}

bool isBST(node*root, int minRange = INT_MIN, int maxRange = INT_MAX) {
	if (root == NULL) {
		return true;
	}

	bool leftBST = isBST(root->left, minRange, root->data);
	bool rightBST = isBST(root->right, root->data, maxRange);

	if (leftBST and rightBST and root->data > minRange and root->data < maxRange) {
		return true;
	} else {
		return false;
	}
}

int firstTimeVisitLevel = 0;

void leftView(node*root, int level) {
	if (root == NULL) {
		return;
	}

	if (firstTimeVisitLevel == level) {
		cout << root->data << " ";
		firstTimeVisitLevel++;
	}

	leftView(root->left, level + 1);
	leftView(root->right, level + 1);
}

void leftBoundary(node*root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		return;
	}

	cout << root->data << " ";

	if (root->left != NULL) {
		leftBoundary(root->left);
	} else {
		leftBoundary(root->right);
	}
}

void printLeaf(node*root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		cout << root->data << " ";
		return;
	}

	printLeaf(root->left);
	printLeaf(root->right);
}

int numberOfBST(int n) {
	if (n == 0 or n == 1) {
		return 1;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += numberOfBST(i - 1) * numberOfBST(n - i);
	}
	return ans;
}

int maxPath = 0;

int maxSumPath(node*root) {
	if (root == NULL) {
		return 0;
	}

	int leftMax = max(0, maxSumPath(root->left));
	int rightMax = max(0, maxSumPath(root->right));

	maxPath = max(maxPath, leftMax + rightMax + root->data);

	return max(leftMax, rightMax) + root->data;
}

class LinkListPair {
public:
	node* head;
	node* tail;

	LinkListPair() {
		head = NULL;
		tail = NULL;
	}
};

LinkListPair treeToLinkedList(node*root) {
	LinkListPair val;

	if (root == NULL) {
		return val;
	}

	if (root->left == NULL and root->right == NULL) {
		val.head = root;
		val.tail = root;
		return val;
	}

	if (root->left != NULL and root->right == NULL) {
		LinkListPair leftPair = treeToLinkedList(root->left);

		leftPair.tail->right = root;

		val.head = leftPair.head;
		val.tail = root;
		return val;
	}

	if (root->left == NULL and root->right != NULL) {

		LinkListPair rightPair = treeToLinkedList(root->right);

		root->right = rightPair.head;

		val.head = root;
		val.tail = rightPair.tail;
		return val;
	}

	if (root->left != NULL and root->right != NULL) {

		LinkListPair leftPair = treeToLinkedList(root->left);
		LinkListPair rightPair = treeToLinkedList(root->right);

		leftPair.tail->right = root;
		root->right = rightPair.head;

		val.head = leftPair.head;
		val.tail = rightPair.tail;
		return val;
	}
}

class TreeDetail {
public:
	int size;
	bool bst;
	int min;
	int max;

	TreeDetail() {
		size = 0;
		bst = true;
		min = INT_MAX;
		max = INT_MIN;
	}
};

TreeDetail largestBSTinBinaryTree(node*root) {
	TreeDetail val;

	if (root == NULL) {
		return val;
	}

	TreeDetail leftDetail = largestBSTinBinaryTree(root->left);
	TreeDetail rightDetail = largestBSTinBinaryTree(root->right);

	if (leftDetail.bst == false or rightDetail.bst == false or root->data < leftDetail.max or root->data > rightDetail.min) {
		val.bst = false;
		val.size = max(leftDetail.size, rightDetail.size);
		return val;
	}

	val.bst = true;
	val.size = leftDetail.size + rightDetail.size + 1;

	val.min = root->left != NULL ? leftDetail.min : root->data;

	val.max = root->right != NULL ? rightDetail.max : root->data;

	return val;
}

int main() {

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

	// cout<<maxPath<<endl;

	LinkListPair temp = treeToLinkedList(root);

	node* head = temp.head;

	while (head != NULL) {
		cout << head->data << " ";
		head = head->right;
	}
	cout << endl;

	return 0;
}

// 8 5 1 6 7 2 3 10 12 13 14 -1