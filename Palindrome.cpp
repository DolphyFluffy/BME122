#include <iostream>

using namespace std;

bool is_palindrome(string my_str/*, int index*/) {
	//base case: empty string
	//base case: one letter
	
	
	//use substring
	if(my_str.size() <= 1) return true;
	
	//general case: more than one letter
	else {
		//compare the first and last elements
		//move towards the middle
		//example: acb
		bool is_valid = my_str[0] == my_str[my_str.size() - 1];
		return is_valid && is_palindrome(my_str.substr(1, my_str.size() - 2));
	}
}

int main() {
	
}

//substrings take everythign betweent eh first value, to the last value in parentheses
