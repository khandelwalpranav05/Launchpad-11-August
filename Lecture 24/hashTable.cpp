#include <iostream>

using namespace std;

template <typename T>
class node{
public:
	string key;
	T value;
	node<T>* next;

	node(string key,T value){
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

};

template <typename T>
class HashTable{

	int currSize;
	int maxSize;
	node<T>** bucket;

	int hashFunction(string key){
		int idx = 0;
		int multiFactor = 1;

		for(int i=0;i<key.length();i++){

			int p = ((key[i]%maxSize)*(multiFactor%maxSize))%maxSize;

			idx = (idx%maxSize + p%maxSize)%maxSize;

			multiFactor = ((multiFactor%maxSize)*(37%maxSize))%maxSize;
		}

		return idx%maxSize;
	}

	void rehash(){

		node<T>** oldBucket = bucket;
		int oldSize = this->maxSize;

		this->maxSize = 2*oldSize;
		bucket = new node<T>*[maxSize];

		for(int i=0;i<maxSize;i++){
			bucket[i] = NULL;
		}

		for(int i=0;i<oldSize;i++){

			node<T>* temp = oldBucket[i];

			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
		}

		delete [] oldBucket;
	}

public:
	HashTable(int default_size = 7){
		this->maxSize = default_size;
		this->currSize = 0;
		bucket = new node<T>*[maxSize];
	}

	void insert(string key,T value){

		int idx = hashFunction(key);

		node<T>* n = new node<T>(key,value);

		n->next = bucket[idx];
		bucket[idx] = n;
		currSize++;

		float loadFactor = float(currSize)/maxSize;
		if(loadFactor>0.7){
			rehash();
		}

	}

	void display(){
		for(int i=0;i<maxSize;i++){

			node<T>* temp = bucket[i];

			while(temp!=NULL){
				cout<<temp->key<<" "<<temp->value<<" ,";
				temp = temp->next;
			}
			cout<<endl;
		}

		cout<<"**************************"<<endl;
	}

	T* search(string key){

		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}

			temp = temp->next;
		}

		return NULL;
	}

	void erase(string key){

		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		cout<<"Check1"<<endl;

		if(temp==NULL){
			return;
		}

		cout<<"Check2"<<endl;

		if(temp->key==key){
			bucket[idx] = temp->next;

			temp->next = NULL;
			delete temp;
			return;
		}

		if(temp->next==NULL){
			return;
		}

		cout<<"Check3"<<endl;


		while(temp->next->key!=key){
			temp=temp->next;
			if(temp->next==NULL){
				return;
			}
		}

		cout<<"Check4"<<endl;


		node<T>* tobeDeleted = temp->next;
		temp->next = temp->next->next;
		delete tobeDeleted;
	}

};

int main(){

	HashTable<int> h;

	h.insert("India",140);
	// h.display();
	h.insert("Pakistan",120);
	// h.display();
	h.insert("dlksjbfldkjsknfd",789);
	// h.display();
	h.insert("US",16);
	// h.display();
	h.insert("Norway",2);
	h.insert("Canada",5);
	h.insert("Swi",3);

	h.insert("Sri Lanka",89);

	h.display();


	// h.erase("Norway");
	h.erase("sjbfvksj");
	// h.insert("Norway",3);

	// h.insert("bat",123);
	// h.insert("tab",159);

	h.display();

	// int* a =h.search("India");
	// cout<<(*a)<<endl;

	return 0;
}