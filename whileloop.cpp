#include <iostream>
#include <vector>

using namespace std;

void jan10th_exercise2( ) {
	int entry;
	bool continue_loop = true;	//each boolean is a decision point

	while( continue_loop ) {
		cout << "Please enter an integer between 1 and 10 inclusive\n";
		cin >> entry;
		if( entry > 0 && entry < 10){
			continue_loop = false;
		}
	}
}

int main () {
	jan10th_exercise2( );
}
