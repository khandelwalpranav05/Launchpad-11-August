#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtHead(node*&head,int data){

	node* n = new node(data);
	n->next = head;
	head = n;
	// cout<<n->data<<endl;
}

void display(node* head){

	node*temp = head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}

	cout<<endl;
}

void insertAtTail(node*&head,int data){
	if(head==NULL){
		insertAtHead(head,data);
		return;
	}

	node* tail = head;

	while(tail->next!=NULL){
		tail = tail->next;
	}

	node* n = new node(data);
	tail->next = n;
}

int length(node* head){
	if(head==NULL){
		return 0;
	}

	node* temp = head;
	int len = 1;

	while(temp!=NULL){
		temp = temp->next;
		len++;
	}

	return len;
}

bool searchIterative(node*head,int item){

	node* temp = head;

	while(temp!=NULL){
		if(temp->data==item){
			return true;
		}
		temp = temp->next;
	}

	return false;
}

void insertAtIndex(node*&head,int data,int pos){
	if(pos==0 or head==NULL){
		insertAtHead(head,data);
		return;
	}

	if(pos>=length(head)){
		insertAtTail(head,data);
	}

	int counter = 0;
	node* temp = head;
	while(counter<pos-1){
		temp = temp->next;
		counter++;
	}

	node* n = new node(data);

	n->next = temp->next;
	temp->next = n;
}

void deleteAtHead(node*&head){

	node* temp = head;
	head = head->next;
	temp->next = NULL;
	delete temp;
}

void deleteAtTail(node*&head){
	if(head==NULL){
		return;
	}

	if(length(head)==1){
		deleteAtHead(head);
		return;
	}

	node* tail = head;
	while(tail->next->next!=NULL){
		tail = tail->next;
	}

	node* p = tail->next;
	tail->next = NULL;
	delete p;
}

void deleteAtIndex(node*&head,int pos){
	if(pos==0){
		deleteAtHead(head);
		return;
	}

	if(pos>=length(head)){
		deleteAtTail(head);
		return;
	}

	int counter = 0;
	node* temp = head; 

	while(counter<pos-1){
		temp = temp->next;
	}

	node* x = temp->next;
	temp->next = temp->next->next;

	x->next = NULL;
	delete x;
}

bool searchRecursive(node*head,int item){
	if(head==NULL){
		return false;
	}

	if(head->data==item){
		return true;
	}

	return searchRecursive(head->next,item);
}

node* midPoint(node*head){

	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL and fast->next->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

void reverseIterative(node*&head){

	node* prev = NULL;
	node* curr = head;

	while(curr!=NULL){

		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = 	n;
	}

	head = prev;
}

node* reverseRecursive(node*&head){
	//Base Case
	if(head==NULL or head->next ==NULL){
		return head;
	}

	node* newHead = reverseRecursive(head->next);
	node* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;
	}

	node* c;

	if(a->data<b->data){
		c = a;
		c->next = merge(a->next,b);
	}else{
		c = b;
		c->next = merge(a,b->next);
	}

	return c;
}

node* mergeSort(node*head){
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* mid = midPoint(head);
	node* secondHalf = mid->next;
	mid->next = NULL;

	head = mergeSort(head);
	secondHalf = mergeSort(secondHalf);

	node* c = merge(head,secondHalf);
	return c;
}

int main(){

	// node* head = NULL;

	// // insertAtTail(head,147);

	// insertAtHead(head,4);
	// insertAtHead(head,3);
	// insertAtHead(head,2);
	// insertAtHead(head,1);

	// display(head);

	// insertAtTail(head,5);
	// insertAtTail(head,6);
	// display(head);

	// insertAtIndex(head,789,2);

	// display(head);

	// deleteAtHead(head);

	// display(head);

	// deleteAtTail(head);

	// display(head);

	// // node* mid = midPoint(head);
	// // cout<<mid->data<<endl;

	// // cout<<searchRecursive(head,789)<<endl;

	// reverseIterative(head);

	// display(head);

	// head = reverseRecursive(head);
	// display(head);

	// node* head1 = NULL;
	// insertAtTail(head1,1);
	// insertAtTail(head1,3);
	// insertAtTail(head1,5);

	// node* head2 = NULL;
	// insertAtTail(head2,2);
	// insertAtTail(head2,4);
	// insertAtTail(head2,6);
	// insertAtTail(head2,8);
	// insertAtTail(head2,9);

	// node* merged = merge(head1,head2);

	// display(merged);

	node* head = NULL;

	insertAtTail(head,5);
	insertAtTail(head,4);
	insertAtTail(head,3);
	insertAtTail(head,2);
	insertAtTail(head,1);

	head = mergeSort(head);
	display(head);

	return 0;
}