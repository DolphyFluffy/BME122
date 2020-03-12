#include <iostream>

using namespace std;

void practice4( ) {
	int size;
	
	cout << "Please enter desired size of array\n";
	cin >> size;
	int number[ size ];
	
	for( int i = 0; i < size ; i++) {
		cout << "Please enter a value less than 11\n";
		cin >> i;
		i+2;
	}
	
	for( int i = size; i > 0 ; i--) {
		cout << i + "\n";
	}
}

int main ( ) {
	practice4( );
}
