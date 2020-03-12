#include <iostream>

using namespace std;

class Test {
public:
	int i;	//on the heap
};

class Person {
	string name;
};

class Print {
	
};

int main() {
	Test* t = new Test(); //pointer of the type Test*
	cout << (*t).i; //syntax for using object pointers
	cout << t->i; //sbbreviated syntax for using object pointers
	delete t;
	
	Person* p = new Person(); //person instance on the heap
	cout << p << endl;	//prints memory allocation of the object
}

//only objects 
