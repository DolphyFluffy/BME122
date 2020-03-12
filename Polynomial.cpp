#include <iostream>
#include <vector>
#include "Polynomial.h"
#include <ctime>
#include <random>
#include <fstream>
#include <cassert>

using namespace std;

//CONSTRUCTORS	
Polynomial::Polynomial(int A[], int size) {
	data.resize(size);
	for(int i = 0; i < size; i++) {
		data[i] = A[i];
	}
}

Polynomial::Polynomial() {
	srand(time(0));
	int degree = rand() % 1001;
	int coefficient;
	data.resize(degree + 1);
	for(int i = 0; i < degree + 1; i++) {
		coefficient = rand() % 2000 - 1001;
		data[i] = coefficient;
	}
}
	
Polynomial::Polynomial(string fileName) {
	ifstream my_ifstream;
	int coefficient;
	int size;
	
	my_ifstream.open(fileName);
	if(!my_ifstream.fail()) {
		my_ifstream >> size;	//fisrt line in file
		data.resize(size);
		for(int i = 0; i < size; i++) {
			my_ifstream >> data[i];	
		}
	}
}

Polynomial::~Polynomial() {
}

//SERVICE FUNCTIONS	
bool Polynomial::operator==(const Polynomial& target) {
	bool are_equal = true;
	if(this->data.size() == target.data.size()) {
		for(int i = 0; i < target.data.size() && are_equal; i++) {
			if(this->data[i] != target.data[i])
				are_equal = false;
		}	
	} else {
		are_equal = false;
	}
	return are_equal;
	//find the size of the polymomial
	//iterate though and them compare data to target
}

void Polynomial::print() {
	for( int i = 0; i < data.size(); i++) {
		cout << data[i] << "x^" << i; 
		if(i != data.size() - 1)
			cout << " + ";
	}
	cout << endl;
}

Polynomial Polynomial::operator+(const Polynomial& target){
	Polynomial added;
	added.data.resize(max(data.size(), target.data.size()));
		
	for( int i = 0; i < min(data.size(), target.data.size()); i++) {
		added.data[i] = data[i] + target.data[i];
	}
	
	for( int i = min(data.size(), target.data.size()); i < added.data.size(); i++) {
		added.data[i] = (data.size() >= target.data.size()) ? data[i] : target.data[i];
	}
	
	return added;
}

Polynomial Polynomial::operator-(const Polynomial& target){
	Polynomial sub;
	sub.data.resize(max(data.size(), target.data.size()));
		
	for( int i = 0; i < min(data.size(), target.data.size()); i++) {	
		sub.data[i] = data[i] - target.data[i];
	}
	
	for( int i = min(data.size(), target.data.size()); i < sub.data.size(); i++) {
		sub.data[i] = (data.size() >= target.data.size()) ? data[i] : target.data[i];
	}
	
	return sub;
}

Polynomial Polynomial::operator*(const Polynomial& target) {
	
	int new_size = (data.size() - 1) + (target.data.size() - 1) + 1;	//degree*degree +1 = size of new array
	int degree;
	int A[new_size] = {0};
	Polynomial mult(A,new_size);

	for( int i = 0; i < data.size(); i++) {
		for(int j = 0; j < target.data.size(); j++) {
			degree = i+j;
			mult.data[degree] += data[i]*target.data[j];
		}
	}
	return mult;
}

Polynomial Polynomial::derivative(){
	//derivative is degree*current coeeficient
	for( int i = 0; i < data.size(); i++) {
		data[i] *= i;
	}
	
	return *this;
}

class PolynomialTest {
public:
	bool test_constructor1() {
		int a[4] = {1,2,3,4};
		int size = 4;
		bool same = true;
		Polynomial A(a,size);
		if(A.data.size() == size) {
			for(int i = 0; i < size; i++) {
				if(A.data[i] != a[i])
					same = false;
			}
		}
		else
			return false;
		
		return same;
	}
	
	void test_print() {
		int a[6] = {1,0,3,7,9,6};
		int size = 6;
		Polynomial A(a, size);
		A.print();
	}
	
	bool test_constructor2() {
		Polynomial A;
		bool it_works = false;
		if(A.data.size() > 0 || A.data.size() < 1000) {
			for(int i = 0; i < A.data.size(); i++) {
				if(A.data[i] > -1000 || A.data[i] < 1000) 
					it_works = true;
			}
		}
		return it_works;
	}
	
	bool test_constructor3() {
		Polynomial A("test_page1.txt");
		int b[3] = {1,4,5};
		int size = 3;
		Polynomial B( b, size);
		return A == B;
	}
	
	//operator==
	bool test_operator_overloading1() {
		int a[4] = {1,2,3,4};
		int size_a = 4;
		int b[4] = {1,2,3,4};
		int size_b = 4;
		
		Polynomial A(a,size_a);
		Polynomial B(b,size_b);
		
		return A == B;
	}
	
	//operator+
	bool test_operator_overloading2() {
		int a[6] = {1,0,3,7,9,6};
		int size_a = 6;
		int b[4] = {1,2,3,4};
		int size_b = 4;
		int a_and_b[6] = {2,2,6,11,9,6};
		int size_a_and_b = 6;
		
		Polynomial A(a,size_a);
		Polynomial B(b,size_b);
		Polynomial A_and_B(a_and_b,size_a_and_b);
		
		return (A + B) == A_and_B;
	}
	
	//operator-
	bool test_operator_overloading3() {
		int a[4] = {4,5,1,2};
		int size_a = 4;
		int b[7] = {1,2,3,4,9,11,34};
		int size_b = 7;
		int a_minus_b[7] = {3,3,-2,-2,9,11,34};
		int size_a_minus_b = 7;
		
		Polynomial A(a,size_a);
		Polynomial B(b,size_b);
		Polynomial A_minus_B(a_minus_b,size_a_minus_b);
		
		return (A - B) == A_minus_B;
	}
	
	//operator*
	bool test_operator_overloading4() {
		int a[2] ={2,1};
		int size_a = 2;
		int b[3] = {4,2,1};
		int size_b = 3;
		int a_mult_b[4] = {8,8,4,1};
		int size_a_mult_b = 4;
		
		Polynomial A(a,size_a);
		Polynomial B(b,size_b);
		Polynomial A_mult_B(a_mult_b,size_a_mult_b);
		
		return (A * B) == A_mult_B;
	}
	
	bool test_derivative() {
		int a[7] = {3,4,7,8,3,1,45};
		int size_a = 7;
		int a_der[7] = {0,4,14,24,12,5,270};
		int size_a_der = 7;
		
		Polynomial A(a,size_a);
		Polynomial A_Der(a_der,size_a_der);
	
		return 	A.derivative() == A_Der;
	}

	void run() {
		test_print();
		cout <<"Test Print passed" << endl;
		
		if (test_constructor1())
			cout <<"Test Constructor1 Passed" << endl;
		else
			cout << "Test Constructor1 Failed" << endl;
			
		if (test_constructor2())
			cout <<"Test Constructor2 Passed" << endl;
		else
			cout << "Test Constructor2 Failed" << endl;
			
		if (test_constructor3())
			cout <<"Test Constructor3 Passed" << endl;
		else
			cout << "Test Constructor3 Failed" << endl;
			
		if (test_operator_overloading1())
			cout <<"Test Operator Overloading1 Passed" << endl;
		else
			cout << "Test Operator Overloading1 Failed" << endl;
			
		if (test_operator_overloading2())
			cout <<"Test Operator Overloading2 Passed" << endl;
		else
			cout << "Test Operator Overloading2 Failed" << endl;
			
		if (test_operator_overloading3())
			cout <<"Test Operator Overloading3 Passed" << endl;
		else
			cout << "Test Operator Overloading3 Failed" << endl;
			
		if (test_operator_overloading4())
			cout <<"Test Operator Overloading4 Passed" << endl;
		else
			cout << "Test Operator Overloading4 Failed" << endl;
		
		if (test_derivative())
			cout <<"Test Derivative Passed" << endl;
		else
			cout << "Test Derivative Failed" << endl;
	}
};

int main() {
	PolynomialTest my_test;
	my_test.run();
	
	return 0;
}
