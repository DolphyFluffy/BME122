

void vectors_demo() {
	vector<int> bme122;
	int bme122_array[10] = {1,2,3,2,4}; //fixed
	int bme122 = {1, 2, 3, 4};
	
	for( int index = 0: index < 10; ++index) {
		cout << bme122[ index ] << " " < bme122_array[index] << endl;
	}
	
	bme122.pop_back();	//removes
	bme122.push_back(3);	//inserts a number
}
