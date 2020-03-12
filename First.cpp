#include <iostream>	//libraries that coem with the language
#include <vector>	//a part of something called STL

//#include "igor.h"	//custom files we create

using namespace std;	//a set of names defined under standard (std) collection of names
						//google no like but we ok because we aren't creating big programs

int main( ) {	//code runs if the main method exists
	int igor;	//int, char, float, double, string
	
	cout << igor << endl;	//may not be 0, may get some arbitrary garbage values from memory - because cleanign ti takes extra time
	
	cout << "Hello BME 122!" << endl;	//::namespace specified - std::cout - cout is derived from std
	
	cout << "How much do you like cake? \n" << endl;
	cin >> igor;	//console input stores into igor
	
	cout << "This is how much you like cake: " << igor << endl;
	return 0;
}


