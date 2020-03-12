#include <iostream>

using namespace std;

int main() {
	int* p = new int(32);
	int* q = new int(24);
	
	*p = *q; //changes
	*q = 42;
	cout << *p << "and " *q << endl;
	//answer is 24 and 42
}

//Q2:
//we are not alloweed to add pointers or multiply pointers
//not to be used as regular operands

//Q3: 
//will take that adress and hop over by an int (4 bytes)
//location is now 0x59688
//just seeing it, not actually moving it - moving it will be p += 1
//we can also subtract - shows 4 locations back

//Q4:

//Q5:
//unknown - not our memory anymore
//dereferencing things that arent ours anymore
//might be 56 but no reason to 

//Q6:
//can't delete pointer to stack memory
//not allowes
