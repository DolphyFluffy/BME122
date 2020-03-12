#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

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
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == 100/*DronesManager::DroneRecord(100)*/)		
	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
	bool test3() {
		DronesManager manager1, manager2;
		manager2.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_front(DronesManager::DroneRecord(200));
		manager2.insert_front(DronesManager::DroneRecord(300));
		manager2.insert_front(DronesManager::DroneRecord(400));
		
		//SELECT()
		//empty list
		ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(0))
		
		//index > list size
		ASSERT_TRUE(manager2.select(6) ==  DronesManager::DroneRecord(100))
		
		//general case
		ASSERT_TRUE(manager2.select(0) ==  DronesManager::DroneRecord(400))
		
		//SEARCH
		//empty list
		ASSERT_TRUE(manager1.search(200) == 0)
		
		//value is in the list
		ASSERT_TRUE(manager2.search(300) == 2)
		
		//value is not in the list
		ASSERT_TRUE(manager2.search(500) == 4)
	    return true;
	}
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
		
		ASSERT_TRUE(manager1.remove_front())
		ASSERT_TRUE(manager2.remove_back())
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 0)	//should be same size of 0
		ASSERT_TRUE(manager1.remove_front() == false && manager2.remove_back() == false) //empty list
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(0))
			
	    return true;
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
	    return false;
	}
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
	    return false;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
	    return false;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
		DronesManager manager1, manager2;
		manager1.insert_back(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
		manager1.insert_back(DronesManager::DroneRecord(200));
		manager2.insert_back(DronesManager::DroneRecord(200));
		manager1.insert_back(DronesManager::DroneRecord(300));
		manager2.insert_back(DronesManager::DroneRecord(300));
		
		
		ASSERT_TRUE(manager1.remove_front())
		ASSERT_TRUE(manager2.remove_front())
		ASSERT_TRUE(manager1.remove_front())
		ASSERT_TRUE(manager2.remove_front())
		ASSERT_TRUE(manager1.remove_front())
		ASSERT_TRUE(manager2.remove_front())
		ASSERT_FALSE(manager2.remove_front())
		ASSERT_FALSE(manager1.remove_front())
		
	    return true;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		DronesManager manager1;
		manager1.insert(DronesManager::DroneRecord(300), 0);
		manager1.insert(DronesManager::DroneRecord(200), 0);
		manager1.remove(3);										//invalud
		manager1.insert(DronesManager::DroneRecord(400), 7);	//invallid
		manager1.insert(DronesManager::DroneRecord(500), 2);
		manager1.remove(2);
		manager1.insert(DronesManager::DroneRecord(700), 1);
		manager1.insert(DronesManager::DroneRecord(800), 10);	//invalid
		manager1.remove(6);										//inva.id
		manager1.remove(2);
		
		ASSERT_TRUE(manager1.size == 2)
		return true;
	}    
	    	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
		DronesManager manager1;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager1.insert_back(DronesManager::DroneRecord(200));
		manager1.insert(DronesManager::DroneRecord(300), 2);
		manager1.insert_back(DronesManager::DroneRecord(400));
		manager1.insert_front(DronesManager::DroneRecord(500));
		manager1.insert(DronesManager::DroneRecord(600), 3);
		manager1.insert(DronesManager::DroneRecord(700), 5);
		manager1.insert_back(DronesManager::DroneRecord(800));
		
		ASSERT_TRUE(manager1.reverse_list())
		
		//manager1.remove_front()
	   return true;
	} 
};

#endif
