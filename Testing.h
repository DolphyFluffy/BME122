#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "Define.h"
#include <cassert>
#include <iostream>
#include <vector>
#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
		return true;
	}

	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));

		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)	//checks if first exists and first and last are equal
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)	//checks that first and last don't point to any additional nodes
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))	//sees if the first element is equal to DroneRecord(100)
		ASSERT_FALSE(manager1.empty() && manager2.empty())
		
		return true;
	}

	// PURPOSE: select() and search() work properly
	bool test3() {
		DronesManager manager3, manager4, manager5;

		manager3.insert_back(DronesManager::DroneRecord(12345));
		manager3.insert_back(DronesManager::DroneRecord(12346));	//same element + position
		manager3.insert_back(DronesManager::DroneRecord(12347));
		manager3.insert_back(DronesManager::DroneRecord(12348));

		manager4.insert_back(DronesManager::DroneRecord(22345));
		manager4.insert_back(DronesManager::DroneRecord(12346));	//same element + position
		manager4.insert_back(DronesManager::DroneRecord(22347));
		manager4.insert_back(DronesManager::DroneRecord(22348));

		//testing select method
		assert(manager3.select(2) == DronesManager::DroneRecord(12347));
		assert(manager3.select(0) == DronesManager::DroneRecord(12345)); //tests at index 0 
		assert(manager3.select(-1) == DronesManager::DroneRecord(12348)); //tests outside index boundary
		assert(manager3.select(7) == DronesManager::DroneRecord(12348)); //tests outside index boundary
		assert(manager5.select(4) == DronesManager::DroneRecord()); //tests empty linked list at index 4
		assert(manager5.select(0) == DronesManager::DroneRecord()); //tests empty linked list at index 0		
		assert(manager4.select(1) == manager3.select(1));

		//testing search method
		assert(manager3.search(DronesManager::DroneRecord(12347)) == 2);
		assert(manager4.search(DronesManager::DroneRecord(12346)) == manager3.search(DronesManager::DroneRecord(12346))); //test if 2 same elements and their positions are the same
		assert(manager4.search(DronesManager::DroneRecord(22348)) == 3);
		assert(manager5.search(DronesManager::DroneRecord(22348)) == 0); //tests empty linked list
		assert(manager4.search(DronesManager::DroneRecord(33333)) == 4); //tests for a record that does not exist

		return true;
	}

	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
		DronesManager manager3, manager4;

		manager3.insert_back(DronesManager::DroneRecord(12345));
		manager4.insert_back(DronesManager::DroneRecord(22345));

		assert(manager3.remove_front()); //removes the one element in the list
		assert(manager3.get_size() == 0); //checks that the size = 0
		assert(manager3.empty()); //checks that the list is empty
		assert(!manager3.remove_back()); //checks that another element cannot be removed from the back
		assert(!manager3.remove_front()); //checks that another element cannot be removed from the front

		assert(manager4.remove_back()); //removes the one element in the list
		assert(manager4.get_size() == 0); //checks that the size = 0
		assert(manager4.empty()); //checks the list is empty
		assert(!manager4.remove_back()); //checks that another element cannot be removed from the back
		assert(!manager4.remove_front()); //checks that another element cannot be removed from the front

		return true;
	}

	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
		DronesManager manager3, manager4, manager5, manager6, manager7, manager8;

		manager3.insert_back(DronesManager::DroneRecord(12345));
		manager3.insert_back(DronesManager::DroneRecord(12346));
		manager3.insert_back(DronesManager::DroneRecord(12347));
		manager3.insert_back(DronesManager::DroneRecord(12348));

		manager4.insert_back(DronesManager::DroneRecord(22345));
		manager4.insert_back(DronesManager::DroneRecord(12346));
		manager4.insert_back(DronesManager::DroneRecord(22347));
		manager4.insert_back(DronesManager::DroneRecord(22348));

		manager8.insert_back(DronesManager::DroneRecord(22345));
		manager8.insert_back(DronesManager::DroneRecord(12346));
		manager8.insert_back(DronesManager::DroneRecord(22347));
		manager8.insert_back(DronesManager::DroneRecord(22348));

		manager6.insert_front(DronesManager::DroneRecord(59765));

		//testing replace
		assert(!(manager5.replace(0, DronesManager::DroneRecord(11111)))); //Tries to replace an empty record 
		assert(!(manager5.replace(4, DronesManager::DroneRecord(12345)))); //checks that an empty node cannot be replaced at an index != 0
		assert(!(manager4.replace(4, DronesManager::DroneRecord(22222)))); //checks that one cannot replace at an invalid index (equal to size)
		assert(!(manager4.replace(10,DronesManager::DroneRecord(22222)))); //checks that one cannot replace at an invalid index (greater than size)
		assert(!(manager4.replace(-2,DronesManager::DroneRecord(22222)))); //checks that one cannot replace at an invalid index (less than zero)
		assert(manager3.replace(2, DronesManager::DroneRecord(01242)));
		assert(manager3.select(2) == DronesManager::DroneRecord(01242));
		assert(manager3.get_size() == 4);
		assert(manager3.replace(3, DronesManager::DroneRecord(01242))); //tests for replacing last value
		assert(manager3.select(3) == DronesManager::DroneRecord(01242));
		assert(manager3.get_size() == 4);
		assert(manager3.replace(0, DronesManager::DroneRecord(01242))); //tests for replacing first value
		assert(manager3.select(0) == DronesManager::DroneRecord(01242));
		assert(manager3.get_size() == 4);
		assert(manager6.replace(0, DronesManager::DroneRecord(16543))); //tests for one-element list
		assert(manager6.select(0) == DronesManager::DroneRecord(16543));
		assert(manager6.get_size() == 1); 
		
		//testing reverse list
		assert(manager4.reverse_list());
		assert(manager4.select(0) == DronesManager::DroneRecord(22348));	//test if the value has moved to the correct spot
		assert(manager4.select(1) == DronesManager::DroneRecord(22347));
		assert(manager4.select(2) == DronesManager::DroneRecord(12346));
		assert(manager4.select(3) == DronesManager::DroneRecord(22345));


		//testing empty reverse list
		assert(manager7.reverse_list());
		assert(manager7.get_size() == 0);

		//testing one-element reverse list
		assert(manager6.reverse_list());
		assert(manager6.select(0) == DronesManager::DroneRecord(16543));

		return true;
	}

	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
		DronesManager manager3, manager4, manager5;

		manager3.insert_back(DronesManager::DroneRecord(12345));
		manager3.insert_back(DronesManager::DroneRecord(12346));
		manager3.insert_back(DronesManager::DroneRecord(12347));
		manager3.insert_back(DronesManager::DroneRecord(12348));

		//Continually testing if the first element is the new element added
		assert(manager3.insert_front(DronesManager::DroneRecord(23423)));
		assert(manager3.select(0) == DronesManager::DroneRecord(23423));
		assert(manager3.get_size() == 5);
		assert(manager3.insert_front(DronesManager::DroneRecord(74383)));
		assert(manager3.select(0) == DronesManager::DroneRecord(74383));
		assert(manager3.get_size() == 6);
		
		assert(manager5.insert_front(DronesManager::DroneRecord(74383)));
		assert(manager5.get_size() == 1);
		assert(manager5.select(0) == DronesManager::DroneRecord(74383));
		
		return true;
	}

	// PURPOSE: inserting at different positions in the list
	bool test7() {
		DronesManager manager3, manager4, manager5;

		manager3.insert_back(DronesManager::DroneRecord(12345));
		manager3.insert_back(DronesManager::DroneRecord(12346));
		manager3.insert_back(DronesManager::DroneRecord(12347));
		manager3.insert_back(DronesManager::DroneRecord(12348));

		manager4.insert_back(DronesManager::DroneRecord(22345));
		manager4.insert_back(DronesManager::DroneRecord(12346));
		manager4.insert_back(DronesManager::DroneRecord(22347));
		manager4.insert_back(DronesManager::DroneRecord(22348));

		assert(manager3.insert(DronesManager::DroneRecord(34522), 2));
		assert(manager3.select(2) == DronesManager::DroneRecord(34522));
		assert(manager3.get_size() == 5);
		assert(!(manager3.insert(DronesManager::DroneRecord(87392), 5)));	//inserting at an index > size - 1
		assert(!(manager3.insert(DronesManager::DroneRecord(87392), 8)));	//inserting at an index > size - 1
		assert(!(manager3.insert(DronesManager::DroneRecord(87392), -18)));	//inserting at a negative index

		return true;
	}

	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
		DronesManager manager3, manager4, manager5;	//manager5 is empty

		manager3.insert_back(DronesManager::DroneRecord(12345));
		manager3.insert_back(DronesManager::DroneRecord(12346));
		manager3.insert_back(DronesManager::DroneRecord(12347));
		manager3.insert_back(DronesManager::DroneRecord(12348));

		manager4.insert_back(DronesManager::DroneRecord(22345));
		manager4.insert_back(DronesManager::DroneRecord(12346));
		manager4.insert_back(DronesManager::DroneRecord(22347));
		manager4.insert_back(DronesManager::DroneRecord(22348));

		assert(!(manager5.remove(3)));	//removing on an empty list
		assert(!(manager5.remove(0)));
		assert(manager4.remove(2));
		assert(manager4.get_size() == 3);
		assert(manager4.search(DronesManager::DroneRecord(22347)) == 3);
		assert(manager4.remove(1));
		assert(manager4.get_size() == 2);
		assert(manager4.search(DronesManager::DroneRecord(12346)) == 2);
		assert(manager4.remove(1));
		assert(manager4.get_size() == 1);
		assert(manager4.search(DronesManager::DroneRecord(12348)) == 1);
		assert(manager4.remove(0));
		assert(manager4.get_size() == 0);
		assert(manager4.search(DronesManager::DroneRecord(12348)) == 0);
		assert(!(manager3.remove(-5)));		//removing at an invalid (negtive) index
		assert(!(manager3.remove(100)));	//removing at an invalid index (index >> size -1)	

		//testing manager3, specifically if it removes an element from a linked list of size 2 at index 0
		assert(manager3.remove(2));
		assert(manager3.get_size() == 3);
		assert(manager3.search(DronesManager::DroneRecord(12347)) == 3);
		assert(manager3.remove(1));
		assert(manager3.get_size() == 2);
		assert(manager3.search(DronesManager::DroneRecord(12346)) == 2);
		assert(manager3.remove(0));
		assert(manager3.get_size() == 1);
		assert(manager3.search(DronesManager::DroneRecord(12345)) == 1);
		assert(manager3.remove(0));
		assert(manager3.get_size() == 0);
		assert(manager3.search(DronesManager::DroneRecord(12345)) == 0);
		assert(!(manager3.remove(0)));	//removing from an empty list
		assert(!(manager3.remove(1)));	//removing from index > size - 1

		//checking you can still insert into the list after all the remove alterations
		assert(manager3.insert(DronesManager::DroneRecord(33333), 0));
		assert(manager3.insert_back(DronesManager::DroneRecord(44444)));
		assert(manager3.insert_front(DronesManager::DroneRecord(22222)));
		assert(manager3.get_size() == 3);
		return true;
	}

	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {

		DronesManager manager3;

		//checking for various types of inserts
		assert(manager3.insert_back(DronesManager::DroneRecord(12345)));
		assert(manager3.insert_front(DronesManager::DroneRecord(12346)));
		assert(manager3.insert(DronesManager::DroneRecord(12347), 1));
		assert(manager3.insert_back(DronesManager::DroneRecord(12348)));
		assert(!(manager3.insert(DronesManager::DroneRecord(98363), -11)));	//inserting at an invalid (negative) index
		assert(!(manager3.insert(DronesManager::DroneRecord(87540), 6)));	//inserting at index > size - 1

		//checking for various types of deletes
		assert(!(manager3.remove(6)));	//removing at index > size - 1
		assert(manager3.remove(1));
		assert(manager3.remove(2));
		assert(!(manager3.remove(-23))); //removing at an invalid (negative index)

		return true;
	}

	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
		DronesManager manager1;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager1.insert_back(DronesManager::DroneRecord(200));
		manager1.insert(DronesManager::DroneRecord(300), 1);
		manager1.insert_back(DronesManager::DroneRecord(400));
		manager1.insert_front(DronesManager::DroneRecord(500));
		manager1.insert(DronesManager::DroneRecord(600), 3);
		manager1.insert(DronesManager::DroneRecord(700), 5);
		manager1.insert_back(DronesManager::DroneRecord(800));

		assert(manager1.reverse_list());
		
		assert(manager1.remove_back());
		assert(manager1.remove(1));
		assert(manager1.remove_front());
		assert(manager1.remove_back());
		assert(manager1.remove_back());
		assert(manager1.remove_back());
		assert(manager1.remove_back());
		assert(manager1.remove_back());
		assert(!(manager1.remove_back()));	//removing when empty

		return true;
	}
};

#endif
