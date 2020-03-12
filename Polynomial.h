#include <iostream>
#include <vector>

using namespace std;

#ifndef POLYNOMIAL
#define POLYNOMIAL

class Polynomial {
	vector<int> data;

public:
	//CONSTRUCTORS
	Polynomial(int A[], int size);
	Polynomial();
	Polynomial(string fileName);
	~Polynomial();
	
	//SERVICE FUNCTIONS
	bool operator==(const Polynomial& target);
	void print();
	
	Polynomial operator+(const Polynomial& target);
	Polynomial operator-(const Polynomial& target);
	Polynomial operator*(const Polynomial& target);
	
	Polynomial derivative();
	
	friend class PolynomialTest;
};

#endif
