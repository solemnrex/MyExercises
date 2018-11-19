#pragma once
#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
using namespace std;

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
void example7();
void example8();

template<typename T>
void DisplayContents(const T& input)
{
	for (auto element_i = input.cbegin() //auto and cbegin: C++11
		; element_i != input.cend()
		; ++element_i)
		//cout << *element_i << ' ';
		cout << *element_i << endl;
		
	cout << endl;
}

inline bool SortPredicateDescending(const int& lsh, const int& rsh)
{
	//define criteria for list::sort: return true for desired order
	return (lsh > rsh);
}

struct ContactItem
{
private:
	string contact_name_;
	string phone_number_;
	string display_representation_;

public:
	//constructor and destructor
	ContactItem(const string& name, const string& number);

	string get_phone_number() const;

	//used by list::remove() given contact list item
	bool operator == (const ContactItem& item_to_compare) const;

	//used by list::sort() without parameters
	bool operator <(const ContactItem& item_to_compare)const;
	
	//used in displaycontents via cout
	operator const char*() const;
};


