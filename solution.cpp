void solution( ) {
	//step0: initialize variables
	bool continue_loop = true, is_valid_entry = true // use lower case and seperate words using underscores (snake case)
	int valid_count = 0;
	
	//step1: iterate from 0 to 10,000
	for( int entry = 0; entry <= 10,000; entry += 3 ) {
		//step1.1: check the specified conditions for entry
		//check that entry us divisible by( 2 or 3) and 11
		is_valid_entry = (entry % 2 == 0 || entry % 3 == 0) && entry % 11 == 0;
		
		//step1.2: print entry if it met the required conditions
		if (is_valid_entry) {
			cout << entry << endl;
			++valid_count;
		}
		
		//step 1.3: determine if five entries were printed
		if (valid_count == 5) continue_loop = false;
		
		is_valid_entry = false;
	}
}
