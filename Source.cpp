#include "Define.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

DronesManager::DronesManager() {
	first = last = NULL; //sets both first and last to NULL
	size = 0; //initialize size to 0
}

DronesManager::~DronesManager() {
	//free up all the nodes in the list
	//[droneID = 100] -> [droneID = 200] -> [droneID = 300] -> NULL
	DroneRecord* cur = first;
	while (cur)
	{
		cur = cur->next;
		delete first;
		first = cur;
	}
	first = last = NULL;
	size = 0;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	bool is_equal = (lhs.droneID == rhs.droneID);
	return is_equal;	//if equal return true, else return fals
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	if (first == NULL && last == NULL)	//if first and last point to nothing, list is empty
		return true;
	else
		return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	//checks if linked list is empty
	if (empty())
		return DroneRecord(0);

	//checks if inputted index is within actual index bounds
	else if (index > size - 1 || index < 0)
		return *last;

	else {	//general case: iterate through list to find the DroneRecord at the index
		DroneRecord* cur = first;
			for(int i = 0; i < index; i++)
				cur = cur->next;
		return *cur;
	}
}

unsigned int DronesManager::search(DroneRecord value) const {
	if (empty())
		return 0;

	DroneRecord* cur = first;
	int index = 0;
	while (cur) {
		if (cur->droneID == value.droneID)	//checking if the DroneID at a particular index = the passed values DroneID
			return index;
		index++;
		cur = cur->next;
	}
	return index;	//returns the size of the list of not found
}

void DronesManager::print() const {
	int index = 0;
	DroneRecord* cur = first;

	while (cur)
	{
		cout << "Node " << index << ":" << endl;
		cout << cur->droneID << endl;

		cur = cur->next;
		index++;
	}
}


bool DronesManager::insert(DroneRecord value, unsigned int index) {
	//if index is outside of the bounds
	if (index >= size || index < 0)
	{
		if (index == size && size == 0) {	//if list is empty and index is 0, insert at front
			first = last = new DroneRecord(value);
			size++;
			return true;
		}
		else return false;
		
	} else {
		int count = 0;	//number of visited DroneRecords
		DroneRecord* cur = first;
		while (count < index)
		{
			cur = cur->next;
			count++;
		}
		//inserting at the index
		DroneRecord* imp = new DroneRecord(value);
		imp->next = cur;
		imp->prev = cur->prev;
		cur->prev->next = imp;
		cur->prev = imp;
		size++;
		return true;
	}
}

bool DronesManager::insert_front(DroneRecord value) {
	if (empty())	//base case if list is empty
	{
		first = new DroneRecord(value);
		first->prev = first->next = NULL;	//set what the pointers to previous and next element to NULL since list only has one element
		last = first;						//last points to the same element as first
		size++;
		return true;
	}
	else {	//general case
		DroneRecord* cur = new DroneRecord(value);
		cur->next = first;
		first->prev = cur;
		first = cur;
		size++;
		return true;
	}
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	if (empty())
	{
		first = new DroneRecord(value);
		first->prev = first->next = NULL;
		last = first;
		size++;
		return true;
	}
	else {
		DroneRecord* cur = new DroneRecord(value);
		last->next = cur;
		cur->prev = last;
		last = cur;
		size++;
		return true;
	}
	return false;
}

bool DronesManager::remove(unsigned int index) {
	if (empty())
		return false; //nothing to remove
		
	if (index > size-1 || index < 0)	//if index is not within bounds, can't remove the element
		return false;
		
	if (size == 1) {	//for a one element list
		delete first, last;
		first = last = NULL;
		size--;
		return true;
	}
	
	else if (index == 0)	//remove first element
		remove_front();
		
	else if (index == size - 1)	//removing last element
		remove_back();
		
	else {	//general case
		DroneRecord* cur = first;
		for (int i = 0; i < index; i++)
			cur = cur->next;
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		cur = NULL;
		size--;

		return true;
	}
}

bool DronesManager::remove_front() {
	if (empty())	//base case: empty list
		return false;
	
	if (first == last) {	//one element list
		delete first, last;
		first = last = NULL;
		
	} else {	//general case
		DroneRecord* cur = first;
		cur->next->prev = NULL;
		first = cur->next;
		cur->next = NULL;
		delete cur;
		cur = NULL;
	}

	size--;
	return true;
}

bool DronesManager::remove_back() {
	if (empty())
		return false;
	
	if (first == last) {
		delete first, last; 
		first = last = NULL;
		
	} else {
		DroneRecord* cur = last;
		cur->prev->next = NULL;
		last = cur->prev;
		cur->prev = NULL;
		delete cur;
		cur = NULL;
	}
	
	size--;
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	//we replaced by inserting at the index then deleting the DroneRecord at the index originaly
	if (empty())
		return false;
		
	else if (index >= size || index < 0)	//index outside of the rand
		return false;
	
	else if (first == last)	//one element list
	{
		DroneRecord* cur = first;
		first = new DroneRecord(value);
		last = first;
		first->prev = NULL;
		last->next = NULL;
		delete cur;
		cur = NULL;
		return true;
	} 
	else if (index == 0) {	//replacing the first DroneRecord
		DroneRecord* cur = first;
		first = new DroneRecord(value);
		first->next = cur->next;
		cur->next->prev = first;
		first->prev = NULL;
		cur->next = NULL;
		delete cur;
		cur = NULL;
	}
	else if (index == size - 1) {	//replacing the last DroneRecord
		DroneRecord* cur = first;
		for (int i = 0; i < index; i++)
			cur = cur->next;
		
		DroneRecord* imp;
		imp = new DroneRecord(value);
		cur->prev->next = imp;
		imp->prev = cur->prev;
		cur->prev = NULL;
		imp->next = NULL;
		last = imp;
		delete cur;
		cur = NULL;	//setting pointer to NULL after deleting ensures that we don't dereference a deletes pointer
		return true;
	}
	else
	{
		DroneRecord* cur = first;
		for (int i = 0; i < index; i++)	//finds the desired index DroneRecord to replace
			cur = cur->next;
		DroneRecord* imp = new DroneRecord(value);
		cur->prev->next = imp;
		imp->next = cur->next;
		cur->next->prev = imp;
		imp->prev = cur->prev;
		delete cur;
		cur = NULL;
		return true;
	}
}

bool DronesManager::reverse_list() {
	//if the list is empty or has one element don't do anything to it
	if (empty() || first == last)
		return true;
		
	DroneRecord *cur = first; 
	DroneRecord* prev = NULL; 
	DroneRecord* next = NULL; 

	last = first; 

	while (cur)
	{
		next = cur->next; 
		cur->next = prev;
		cur->prev = next;

		prev = cur;
		cur = next;
	}
	first = prev; 
	
	return true;
}
