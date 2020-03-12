#include <iostream>

using namespace std;

class A {
	private:
		string name1;
	protected:
		string name2;
	public:
		string name3;
};

class B : public A {
public:
	void test() {
		cout << name1 << endl;
		cout << name2 << endl;	//Accessible ebevcause it is a derived form A
		cout << name3 << endl;	//Not accesible since it is private in A
	}
	friend class C;	//has direct acess to private things of b i.e. for test classes
	friend bool operator==(const B& target1; const B& target2);)	//giving direct acess ot external fucitons
};

int main() {
	B b;
	cout << b.name1 << endl;
	cout << b.name2 << endl;	//not accessible since it si not a deriived class og A
	cout << b.name3 << endl;	//not accesible since it is private in A
	/*
	Person p("Joan", "Smith", "May 1st 2000");
	Student s("20111111" "Math", "Stats", p);
	
	vector<Students> student;
	student.push_back(s);*/
}
