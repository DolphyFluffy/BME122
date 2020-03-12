#include <iostream>

using namespace std;

class Person {	//private by default
	string f_name, l_name, dob;
	
public:
	Person() {	}	//implicitky initializes akk three strings to ""
	Person( string new_f_name, string new_l_name, string new_dob) :
		f_name(new_f_name), l_name( new_l_name), dob( new_dob) { }
		//initializer list
	void set_f_name(string new_f_name) {	//mutator
		f_name = new_f_name;
	}
	
	string get_f_name() {	//acessor
		return f_name;
	}
};	//mandatory semi-colan after declaration

void change_name(Person p) {
	//there is an internal copy of Person created inside this function
	//this copy contains all the values from the original person
	//changes made to this copy iwll have no effect of the caller
	// that is, someone who is invoking this function
	p.set_f_name("Mike");
}
	
void change_name_by_ref(Person& p) {
	//instead of an interanl copy of Person,we have provided access
	//to the memory location of the caller for Person object
	//changes made to this object will have effect on the caller
	//this would be done to optimise memory access or
	//to delegate responsibility fo chanign values to a specific function
	p.set_f_name("Mikey");
}

int main() {
	Person p; //instantiates a Person object
	p.set_f_name = "George";
	cout << p.get_f_name <<endl;
	
	change_name_by_ref(p);
	cout << p.get_f_name <<endl;
	}
