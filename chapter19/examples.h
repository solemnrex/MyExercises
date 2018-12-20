#ifndef EXAMPLES_H_
#define EXAMPLES_H_

#include <set>
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

//used as a template parameter in set / mutiset instantiation
template <typename T>
struct SortDesending
{
	bool operator ()(const T& lhs, const T& rhs) const
	{
		return (lhs > rhs);
	}
};

template <typename T>
void DisplayContents(const T& input)
{
	for (auto element_i = input.cbegin()//auto, cbegin: c++11
		; element_i != input.cend() //cend() is new in c++11
		; ++element_i)
		cout << *element_i << ' ';

	cout << endl;
}

template <typename T>
void DisplayContents_n(const T& input)
{
	for (auto element_i = input.cbegin()//auto, cbegin: c++11
		; element_i != input.cend() //cend() is new in c++11
		; ++element_i)
		cout << *element_i << endl;

	cout << endl;
}

void example1();
void example2();
void example3();

typedef multiset <int> MSETINT;
void example4();

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
void example5();
void example6();

#endif // !EXAMPLES_H_
