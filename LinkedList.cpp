#include <iostream>

using namespace std;

class Node {	//c++ implementation
	int data;
	//vector<int> data_items;
	
	Node* next;	//forward list if only next is availible
	//Node* prev; //doubly-linked list of both next and prev availible
	//<list> is an example of doubly-linked list
public:
	Node(int new_data) : data(new_data), next(NULL) { }	//set next to NULL
	
	void Print() {
		cout << data << endl; 
	}
};

class LinkedList {	//suitable to store singly-linked list or forward list
	Node* first; //pointer to the first node in the list (not the actual first node in the list)
	Node* last; //pointer to store the last node in the list
	int size; //used to store the number of nodes in the list
public:
	LinkedList() : first(NULL), last(NULL), size(0) { }
};

int main() {

}
