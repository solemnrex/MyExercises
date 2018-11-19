#include "example.h"

void example1()
{
	//instantiate an empty list
	list<int> list_integers;

	//instantiate a list with 10 integers
	list<int> list_with_10_integers(10);

	//instantiate a list with 4 integers, each initialized to 99
	list<int> list_with_4_integers_each_99(4, 99);

	//create an exact copy of existing list
	list<int> list_copy_another(list_with_4_integers_each_99);

	//a vector with 10 integers, each 2011
	vector<int> vector_integers(10, 2011);

	//instantiate a list using values from another container
	list<int> list_contains_copy_of_another(vector_integers.cbegin(), vector_integers.cend());

}

void example2()
{
	std::list <int> list_integers;

	list_integers.push_front(10);
	list_integers.push_front(2011);
	list_integers.push_back(-1);
	list_integers.push_back(9999);

	DisplayContents(list_integers);
}

void example3()
{
	list <int> list_integers1;

	//inserting elements at the beginning..
	list_integers1.insert(list_integers1.cbegin(), 2);
	list_integers1.insert(list_integers1.cbegin(), 1);
	
	//inserting elements at the end..
	list_integers1.insert(list_integers1.cend(), 3);

	cout << "The contents of list 1 after inserting elements:" << endl;
	DisplayContents(list_integers1);

	list <int> list_integers2;

	//inserting 4 elements of the same value 0...
	list_integers2.insert(list_integers2.cbegin(), 4, 0);

	cout << "The contents of list 2 after inserting elements:" << endl;
	cout << list_integers2.size() << " elements of value: " << endl;
	DisplayContents(list_integers2);

	list <int> list_integers3;

	//inserting elements from another list at the beginning..
	list_integers3.insert(list_integers3.cbegin(),
		list_integers1.cbegin(), list_integers1.cend());

	cout << "The contents of list 3 after inserting elements:" << endl;
	cout << "list 1 at the beginning:" << endl;
	DisplayContents(list_integers3);

	//inserting elements from another list at the end...
	list_integers3.insert(list_integers3.cend(),
		list_integers2.cbegin(), list_integers2.cend());

	cout << "The contents of list 3 after inserting elements:" << endl;
	cout << "The contents of list 2 at the end: " << endl;
	DisplayContents(list_integers3);

}

void example4()
{
	std::list <int> list_integers;

	//insert elements at the beginning and end...
	list_integers.push_back(4);
	list_integers.push_front(3);
	list_integers.push_back(5);

	//store an iterator obtained in using the insert function
	auto value2_i = list_integers.insert(list_integers.cbegin(), 2);

	cout << "Initial contents of the list:" << endl;
	DisplayContents(list_integers);

	list_integers.erase(list_integers.cbegin(), value2_i);
	cout << "Contents after erasing a range of elements:" << endl;
	DisplayContents(list_integers);

	cout << "After erasing element '" << *value2_i << "':" << endl;
	list_integers.erase(value2_i);
	DisplayContents(list_integers);

	list_integers.erase(list_integers.cbegin(), list_integers.end());
	cout << "Number of elements after erasing range: ";
	cout << list_integers.size() << endl;

}

void example5()
{
	std::list<int> list_integers={ 0,1,2,3,4,5 };

	cout << "Initial contents of the list:" << endl;
	DisplayContents(list_integers);

	list_integers.reverse();

	cout << "Contents of the list after using reverse():" << endl;
	DisplayContents(list_integers);
}

//bool SortPredicateDescending(const int& lsh, const int& rsh)
//{
//	//define criteria for list::sort: return true for desired order
//	return (lsh > rsh);
//}
void example6()
{
	// function object
	//class innerfunc
	//{
	//public:
	//	bool operator ()(const int& lsh, const int& rsh)
	//	{
	//		//define criteria for list::sort: return true for desired order
	//		return (lsh > rsh);
	//	}
	//};
	//innerfunc SortPredicateDescending;

	// lambda expression
	//auto SortPredicateDescending = [=](const int& lsh, const int& rsh)->bool
	//{
	//	//define criteria for list::sort: return true for desired order
	//	return (lsh > rsh);
	//};
	
	list<int> list_integers = { 0,-1,2011,444,-5 };

	cout << "Initial contents of the list:" << endl;
	DisplayContents(list_integers);

	list_integers.sort();

	cout << "Order of elements after sort():" << endl;
	DisplayContents(list_integers);

	list_integers.sort(SortPredicateDescending);
	cout << "Order of elements after sort() with a predicate:" << endl;
	DisplayContents(list_integers);

}

ContactItem::ContactItem(const string& name, const string& number)
{
	contact_name_ = name;
	phone_number_ = number;
	display_representation_ = (contact_name_ + ": " + phone_number_);
}
string ContactItem::get_phone_number()const
{
	return this->phone_number_;
}
bool ContactItem::operator == (const ContactItem& item_to_compare) const
{
	return (item_to_compare.contact_name_ == this->contact_name_);
}
bool ContactItem::operator <(const ContactItem& item_to_compare)const
{
	return(this->contact_name_ < item_to_compare.contact_name_);
}
ContactItem::operator const char *()const
{
	return display_representation_.c_str();
}
void example7()
{
	auto SortOnPhoneNumber = [=](const ContactItem& item1, const ContactItem& item2)->bool
	{
		return (item1.get_phone_number() < item2.get_phone_number());
	};
	list <ContactItem> contacts;
	contacts.push_back(ContactItem("Jack Welsch", "+1 7889 879 879"));
	contacts.push_back(ContactItem("Bill Gates", "+1 97 7897 8799 8"));
	contacts.push_back(ContactItem("Angela Merkel", "+49 23456 5466"));
	contacts.push_back(ContactItem("Vladimir Putin", "+7 6645 4564 797"));
	contacts.push_back(ContactItem("Manmohan Singh", "+91 234 4564 789"));
	contacts.push_back(ContactItem("Barck Obama", "+1 745 641 314"));

	cout << "List in initial order:" << endl;
	DisplayContents(contacts);

	contacts.sort();
	cout << "After sorting in alphabetical order via operater<:"<<endl;
	DisplayContents(contacts);

	contacts.sort(SortOnPhoneNumber);
	cout << "After sorting in order of phone numbers via predicate:" << endl;
	DisplayContents(contacts);

	cout << "After erasing Putin from the list:" << endl;
	contacts.remove(ContactItem("Vladimir Putin", ""));
	DisplayContents(contacts);
}

void example8()
{
	forward_list<int> flist_integers = {3,4,2,2,0};
	flist_integers.push_front(1);

	cout << "Contents of forward_list:" << endl;
	DisplayContents(flist_integers);

	flist_integers.remove(2);
	flist_integers.sort();
	cout << "Contents after removing 2 and sorting: " << endl;
	DisplayContents(flist_integers);
}
