#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool is_inc = true, is_dec = true;
        for( int index = 0; index < A.size() - 1; index++ ) {
            if( A[ index ] > A[ index + 1]) 
                is_inc = false;
            else if (A[ index ] < A[ index + 1]) 
                is_dec = false;
        }
    return is_inc || is_dec; 
    }
};

int main( ) {
	vector<int> test_vector1 = {1, 2, 3, 4, 4, 3};
	
}
