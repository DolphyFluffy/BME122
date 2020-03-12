#include <iostream>
#include <vector>

using namespace std;

void jan10th_exercise( ) {
	int valid_count = 0;
	for( int i = 0; i <= 10000; i+=3)	{
		if( (i% 2 == 0 ||i% 3 == 0) && i% 11 == 0)
		{
			if(valid_count < 5)
			{
				cout << i << endl;
				valid_count++;
			}
		}
	}
}



int main( ) {
	jan10th_exercise();
}
