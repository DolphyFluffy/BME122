#include <iostream>
#include <vector>
#include <cassert>
//#include <assert.h>
//#define NDEBUG

using namespace std;

//PURPOSE: Representas an instance of Artwork or one piece of Artwork STEP!
class Artwork {
	string artist_name, title;
	unsigned int year_made;	//primitive data, so need to initialize (always be positive)
public:
	//empty/default constructor
	Artwork() : year_made(0) {}
	
	//prametric constructor
	Artwork(string new_artist, string new_title, unsigned int new_year) :
		artist_name( new_artist), title( new_title), year_made(new_year) {}
		
	//overloaded operator ==
	bool operator==(const Artwork& rhs) const { //envuer that the pbject is not modified
		bool are_equal = artist_name == rhs.artist_name;
		are_equal = are_equal && title == rhs.title;
		are_equal = are_equal && year_made == rhs.year_made;
		return are_equal;
		}
};

//Step2
class SoldArtwork : public Artwork {
	string cust_name, cust_addr;
	double sale_amount;
public:
	//empty/default constructor
	SoldArtwork() : sale_amount(0) {}
	
	//parametric constructor
	SoldArtwork( string new_cust_name, string new_cust_addr, double new_sale_amount, 
		Artwork new_artwork) : cust_name(new_cust_name), cust_addr(new_cust_addr), //implicit setters
		sale_amount(new_sale_amount), Artwork(new_artwork)	/*calling Artwork constructor*/ {}
		
	bool operator==(const SoldArtwork& rhs) const { //envuer that the pbject is not modified
		bool are_equal = cust_name == rhs.cust_name;
		are_equal = are_equal && cust_addr == rhs.cust_addr;
		are_equal = are_equal && sale_amount == rhs.sale_amount;
		are_equal = are_equal && static_cast<Artwork>(rhs) == static_cast<Artwork>(*this);	//calls original artwork class
		return are_equal;	//static cast treats the object as a base flass
	}
};

//PURPOSE: Represetnes models artwork pieces held by an art gallery
class ArtCollection {
	vector<Artwork> my_artwork; //private attribute; a collection of Artwork instances
	vector<SoldArtwork> my_sold_artwork; //private attribute; a collection of SoldArtwork instances
public:
	bool insert_artwork(const Artwork& artwork_info) {//method signature; specifies name and parameter only
	
		bool has_duplicate = false;	//use a boolean to keep track of duplicate detection
		
		for( int entry = 0; entry < my_artwork.size() && !has_duplicate; ++entry) {	//iterate through my_artwork to check for duplicate values
			if(my_artwork[entry] == artwork_info) {	
				has_duplicate = true;
			}
		}
	
	if( has_duplicate == false) {	//if it doesn't have duplicate
		my_artwork.push_back(artwork_info);	//inserts the artwork into the Artwork vector
	}
	
	return !has_duplicate; //retrun true if insertion works;else return false
}
	//PURPOSE: Facilitates a sale of Artwork and placement of SoldWrtwork instanc into the corospoding vector
	bool sell_artwork(const SoldArtwork& artwork_info) { //soldartwork?
		
		bool have_sold = false;	//keeps tracl of sucessful sale
		
		for( int entry = 0; entry < my_artwork.size() &&!have_sold; ++entry) {	//iterate through my_artwork that matheces artork_info
			if(my_artwork[entry] == static_cast<Artwork>(artwork_info)) {	//use operator == to compare vector element agaisn the element that is passed in
				swap(my_artwork[entry], my_artwork[my_artwork.size() - 1]);
				my_artwork.pop_back();	//remove the last entry
				my_sold_artwork.push_back(artwork_info); //insert sold_artwork intot he m_sold_artwork vector
				have_sold = true;
			}
		}
		
		return have_sold;//return true if you sell the artwork, otherwise 
	}
	
	bool operator==(const ArtCollection& rhs) const {
		//iterate through my_artwork vectors of lhs and rhs
		//compare each pair of values and check if they are equal
		bool are_equal = true; //do this until its wrong
		
		if(my_artwork.size() != rhs.my_artwork.size() || my_sold_artwork.size() != rhs.my_sold_artwork.size()) //if one holds, check the other
			are_equal = false;
		
		//sort(my_artwork.begin(), my_artwork.end());	sorts the collection
		//sort(my_sold_artwork.begin(), my_sold_artwork.end())
		
		
		for( unsigned int index = 0; index < my_artwork.size(); ++index) {
			if(!(my_artwork[index] == rhs.my_artwork[index])) //if true, evaluates as false
				are_equal = false;
		}
		
		for( unsigned int index = 0; index < my_sold_artwork.size(); ++index) {
			if(!(my_sold_artwork[index] == rhs.my_sold_artwork[index]))
				are_equal = false;
		}
		return are_equal;
	}
	
	// external fucntion which will have direct acces to private members of ArtCollection
	friend ArtCollection operator+(const ArtCollection& lhs, const ArtCollection& rhs);
	friend class ArtCollectionTest;
};

ArtCollection operator+(const ArtCollection& lhs, const ArtCollection& rhs) {
	ArtCollection target(lhs);	//copy cnstructpr
	
	for( unsigned int index = 0; index < rhs.my_artwork.size(); ++index) {
		target.my_artwork.push_back(rhs.my_artwork[index]);
	}
	
	for( unsigned int index = 0; index < rhs.my_sold_artwork.size(); ++index) {
		target.my_sold_artwork.push_back(rhs.my_sold_artwork[index]);
	}
	
	return target;
}

//test colelctions should be mutually independednt
class ArtCollectionTest {
	vector<Artwork> test_values;
	vector<SoldArtwork> test_vals;
	
	void setup() {
		Artwork a1("Igor", "Da Igor", 2020), a2("BME 122 Class", "Quadcopters", 2019), a3("BME 122 Sad", "C++ is Hard", 2020);
		test_values.push_back(a1);
		test_values.push_back(a2);
		
		SoldArtwork s1("Bob", "23 New Lane", 500.90, a1), s2("Steve", "333 Candy Lane", 1.2, a2);
		test_vals.push_back(s1);
		test_vals.push_back(s2);
	}
	void test_insert_artwork() {
		ArtCollection test_collection;
		
		cout << (test_collection.insert_artwork(test_values[0]) ? "Test insert_artwork passed" : "Test failed") << endl;	//basic testcase
	
		assert(test_collection.my_artwork.size() == 1);
		cout << "Test1: my_artwork.size() passed" << endl;
		
		assert(!(test_collection.insert_artwork(test_values[0])));
		cout << "Test2: insert_artwork() passed" << endl;
		
		assert(test_collection.my_artwork.size() == 1);
		cout << "Test3: my_artwork.size() passed" << endl;
	}
	void test_sell_artwork() {
		ArtCollection test_collection;
		
		test_collection.insert_artwork(test_values[0]);
		test_collection.insert_artwork(test_values[1]);
		
		//test orginal size of artwork vector
		assert(test_collection.my_artwork.size() == 2);
		cout << "Test4: my_artwork.size() passed" << endl;
	
		//selling one artwork
		assert(test_collection.sell_artwork(test_vals[1]));
		cout << "Test5: sell_artwork passed" << endl;
		
		//test artwork vector size after beign sold
		assert(test_collection.my_artwork.size() == 1);
		cout << "Test6: my_artwork.size() passed" << endl;
		
		//selling the artwork again
		assert(!(test_collection.sell_artwork(test_vals[1])));
		cout << "Test7: sell_artwork passed" << endl;
		
		//selling artwork that isnt there - doesnt work
		//assert(!(test_collection.sell_artwork(test_vals[2])));
		//cout << "Test8 sell_artwork passed" << endl;
		
		//test that the artwork is removed from artwork vector and moved to sold artwork vector
		//look for instance of the artwork and remove it
		//size of my artwork decreases
		//look for instance of that artwork
		//size of sold artwork increases
		
	}
	void test_operator_overloading() {
		ArtCollection test_1, test_2, test_3, test_4;
		
		test_1.insert_artwork(test_values[0]);
		test_1.insert_artwork(test_values[1]);
		assert(test_1.sell_artwork(test_vals[1]));
		//cout<< "Test8: sell_artwork passed" << endl;
		
		test_2.insert_artwork(test_values[0]);
		test_2.insert_artwork(test_values[1]);
		assert(test_2.sell_artwork(test_vals[0]));
		//cout << "lols worked" << endl;
		
		test_3.insert_artwork(test_values[0]);
		
		test_4.insert_artwork(test_values[1]);
		assert(test_4.sell_artwork(test_vals[1]));
		
		assert(!(test_1 == test_2));
		cout << "Test8: Operator== (ArtCollection) passed" << endl;
		
		assert((test_3 + test_4) == test_1);
		cout << "Test9: Operator+ passed" << endl;
		
		//assert((test_3 == test_4));
		//cout << "Test9: operator== (ArtCollection) passed" << endl;
		
		//test operator+
		//artcollection 1 + artcollection 2 = artcollection 3
		//assert((a1 + a2) == a3);
		//cout << "Test10: operator+ passed" << endl;
		
		//assert(test_collection.test_values[0] == test_collection.a2[1]);
		//test operator == for
			//artwork
			//soldartwork
			//artcollection
		
		
	}
public:
	void run() {
		setup();
		//test_artwork_methods();
		//test_sold_artworl_methods(_;
		test_insert_artwork();			//3 calls for this
		test_sell_artwork();			//3 calls for this
		test_operator_overloading();	//3 calls for this
		
		//teardown();
	}
};		
		
//bool ArtCollection::insert_artwork(const Artwork& artwork_into) { //method definition; specifies the actual code//


int main() {
	ArtCollectionTest ac_test;
	ac_test.run();
//Notes:
//Functions - comupttional unit outside a class
//varibale - outside a class

//Methods - funtion inside a class
//Member/attribute - variables that are inside a class

}
