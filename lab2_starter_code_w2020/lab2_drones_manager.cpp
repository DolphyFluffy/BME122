#include "lab2_drones_manager.hpp"
#include <iostream>

using namespace std;
//works
DronesManager::DronesManager() {
	first = last = NULL;	//sets both first and ast to NULL
	size = 0;
}

//works
DronesManager::~DronesManager() {
	//frees up all the nodes in the list
	//[droneID = 100] ->[droneID] -> [droneID = 300] -> NULL
	DroneRecord* cur = first;
	while(cur) {
		cur = cur->next;
		delete first;
		first = cur;
	}
	first = last = NULL;
	size = 0;
}

//works
bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	bool are_equal = lhs.droneID == rhs.droneID;		
	return are_equal;
}

unsigned int DronesManager::get_size() const {
	return size;
}

//works
bool DronesManager::empty() const {
	if(!first) return true;
	else return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	if(empty())
		return DroneRecord(0);
		
	else if(index > this->get_size()) 
		return *last;
		
	else {
		DroneRecord* cur = first;
		for( int i = 0; i < index; i++) {
			cur = cur->next;
		}
		return *cur;
	}	
}

unsigned int DronesManager::search(DroneRecord value) const {
	if(empty())
		return 0;
		
	DroneRecord* target = new DroneRecord(value);
	DroneRecord* cur = first;
	int index = 0;
	
	while(cur) {
		if(cur->droneID == target->droneID) {
			return index;
		}
		cur = cur->next;
		++index;
	}
	
	return size;
}

void DronesManager::print() const {
	DroneRecord* cur = first;
	while(cur) {
		cout << cur->droneID;
		cur = cur->next;
	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if(!first)
		insert_front(value);
	else if(index > size -1)
		return false;
	else if(index == 0)
		insert_front(value);
	else if(index == size - 1)
		insert_back(value);
	else {
		DroneRecord* cur = first;
		DroneRecord* pre = NULL;
		DroneRecord* new_val = new DroneRecord(value);
		int idx = 0;
		while(cur) {
			if(idx == index) {
				pre->next = new_val;
				cur->prev = new_val;
				new_val->prev = pre;
				new_val->next = cur;
			}
			pre = cur;
			cur = cur->next;
			++idx;
		}
	}
	return true;
}

bool DronesManager::insert_front(DroneRecord value) {
	if (empty()) { // base case: empty list
		first = new DroneRecord(value); 
		first->prev = first->next = NULL;
		last = first;

	} else { // general case: non-empty list
		DroneRecord* second = first; // init end ptr
		first = new DroneRecord(value);
		first->next = second;
		second->prev = first;
	//DOOO NOTT DOOO first = &value;
		//sets a pointer to point to a location ont he stack
		//value is freed at the end of the scope
		//hence this wil lead to very bad things
	}
	++size;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	if (!last) { // base case: empty list
	last = new DroneRecord(value); 
	first = last;	
	last->prev = last->next = NULL;

	} else { // general case: non-empty list
		DroneRecord* add = new DroneRecord(value);
		add->prev = last;
		last->next = add;
		last = add;
		//second_last->next = new DroneRecord(value);
		//last = second_last->next;
	}
	++size;
	return true;
}

bool DronesManager::remove(unsigned int index) {
	if(!first || index > size -1) {
		return false;
		
	} else if (!first->next) { // base case: list with one node
		delete first, last;
		first = last = NULL;
		
	} else if(index == 0) {
		remove_front();
		
	} else if(index == size - 1) {
		remove_back();
		
	} else {
		DroneRecord* cur = first->next;
		DroneRecord* pre = first;
		DroneRecord* remove = NULL;
		int idx = 0;
		
		while(cur) {
			if(idx == index) {
				remove = cur;
				cur = cur->next;
				pre->next = cur;
				cur->prev = pre;
				delete remove;
			}
			pre = cur;
			cur = cur->next;
		}	
	}
	return true;
}

bool DronesManager::remove_front() {
	if (empty()) { // base case: empty list
		return false; // nothing to do
		
	} else if (!first->next) { // base case: list with one node
		delete first, last;
		first = last = NULL;
				
	} else { // general case: a list with more than one node
		DroneRecord* remove = first; // init end pointer
		first = first->next;
		delete remove; // free memory for the last node
		remove = NULL;
	}
	
	--size; // update size
	return true; // return true
}

bool DronesManager::remove_back() {
	if (empty()) { // base case: empty list
		return false; // nothing to do
		
	} else if (!first->next) { // base case: list with one node
		delete first, last;
		first = last = NULL;
				
	} else { // general case: a list with more than one node
		DroneRecord* remove = last; // init end pointer
		last = last->prev;
//		last->next = NULL; //issue
		delete remove; // free memory for the last node
		remove = NULL;
	}
	
	--size; // update size
	return true; // return true
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if(empty())
		return false;
	else if(index > size - 1)
		return false;
	else {
		DroneRecord* cur = first->next;
		//DroneRecord* replace = new DroneRecord(value);
		while(cur) {
			int idx = 0;
		
			if(idx == index) {
				*cur = value;
			}
			cur = cur->next;
		}
	}
}

bool DronesManager::reverse_list() {
	if(empty() || size == 1)
		return false;
    //Node* next = NULL;
    else {
    	DroneRecord* pre = first;
   		DroneRecord* cur = first->next;
    	while(cur) {
	        pre->next = pre->prev;
	        pre->prev = cur;
	        pre = cur;
	        cur = cur->next;
	    }
	    cur->prev = NULL;
	    cur->next = pre;
	    last = first;
    	first = cur;
	}
    
    return true;
}

