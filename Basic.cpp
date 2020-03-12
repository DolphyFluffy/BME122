#include <iostream>	//libraries that coem with the language
#include <vector>	//a part of something called STL

//#include "igor.h"	//custom files we create

using namespace std;	//a set of names defined under standard (std) collection of names
						//google no like but we ok because we aren't creating big programs

void jan9th_exercise1( int num) {
	if( num > 5000 && (num % 10 == 0) && ((num / 100) % 10 == 3) && ((num / 10 % 10)%2 == 0))
	{
		cout << "The number is valid \n";
	}
	else {
		cout << "The number is not valid";
	}
}

int main( ) {
	cout << "Testing 5380" << endl;
	jan9th_exercise1(5380);
	cout << "Testing 5940" << endl;
	jan9th_exercise1(5940);
	
}


