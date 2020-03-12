#include <iostream>

using namespace std;

int* foo() {
	int a = 5;
	return &a;
}

int main() {
	int *p = foo();
	*p = 7;
}
