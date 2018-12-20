#include "examples.h"

void example1()
{
	//a simple set or multiset of integers (using default sort predicate)
	set <int> set_integers1;
	multiset <int> mset_integers1;

	//set and multiset instantiated given a user defined sort predicate
	set <int, SortDesending<int>> set_integers2;
	multiset <int, SortDesending<int>> mset_integers2;

	//creating one set from another, or part of another container
	set <int> set_integers3(set_integers1);
	multiset <int> mset_integers3(mset_integers1.cbegin(), mset_integers1.cend());
}

void example2()
{
	set <int> set_integers;
	multiset <int> mset_integers;

	set_integers.insert(60);
	set_integers.insert(-1);
	set_integers.insert(3000);
	cout << "Writing the contens of the set to the screen" << endl;
	DisplayContents(set_integers);

	mset_integers.insert(set_integers.begin(), set_integers.end());
	mset_integers.insert(3000);

	cout << "Writing the content of the multiset to the screen" << endl;
	DisplayContents(mset_integers);

	cout << "Number of instances of '3000' in the multiset are:" << " '";
	cout << mset_integers.count(3000) << "'" << endl;
}

void example3()
{
	set <int> set_integers;
	set_integers = { 43,78,-1,124 };

	//display set_integers to the screen
	DisplayContents(set_integers);

	//Try finding an element
	auto element_found_i = set_integers.find(-1);

	//check if found...
	if (element_found_i != set_integers.end())
		cout << "Element " << *element_found_i << " found!" << endl;
	else
		cout << "Element not found in set!" << endl;

	//Try finding another element
	auto another_find_i = set_integers.find(12345);

	//Check if found...
	if (another_find_i != set_integers.end())
		cout << "Element " << *another_find_i << " found!" << endl;
	else
		cout << "Element 12345 not found in set!" << endl;

}

void example4()
{
	MSETINT mset_integers;

	//initial mset_integers
	mset_integers = { 43,78,78,-1,124,-1 };

	cout << "multiset contains " << mset_integers.size() << " elements.";
	cout << " There are: " << endl;

	//write contents of the multiset to the screen
	DisplayContents(mset_integers);

	cout << "Please enter a number to be erased from the set" << endl;
	int number_to_erase = 0;
	cin >> number_to_erase;

	cout << "Erasing " << mset_integers.count(number_to_erase);
	cout << " instances of value " << number_to_erase << endl;

	//try finding an element
	mset_integers.erase(number_to_erase);

	cout << "multiset contains " << mset_integers.size() << " elements.";
	cout << " There are: " << endl;
	DisplayContents(mset_integers);
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
void example5()
{
	set<ContactItem> set_contacts;
	set_contacts.insert(ContactItem("Jack Welsch", "+1 7889 879 879"));
	set_contacts.insert(ContactItem("Bill Gates", "+1 97 7897 8799 8"));
	set_contacts.insert(ContactItem("Angela Merkel", "+49 23456 5466"));
	set_contacts.insert(ContactItem("Vladimir Putin", "+7 6645 4564 797"));
	set_contacts.insert(ContactItem("Manmohan Singh", "+91 234 4564 789"));
	set_contacts.insert(ContactItem("Barck Obama", "+1 745 641 314"));
	DisplayContents_n(set_contacts);

	cout << "Enter a person whose number you wish to delete: ";
	string name_input;
	getline(cin, name_input);

	auto contact_found_i = set_contacts.find(ContactItem(name_input, ""));
	if (contact_found_i != set_contacts.end())
	{
		//erase the contact found in set
		set_contacts.erase(contact_found_i);
		cout << "Displaying contents after erasing: " << name_input << endl;
		DisplayContents_n(set_contacts);
	}
	else
		cout << "Contact not found" << endl;
}

void example6()
{
	//instantiate unordered_set of int to string:
	unordered_set<int> usetInt;

	//usetInt = { 1000,-3,2011,300,-1000,989,-300,111 };
	usetInt.insert(1000);
	usetInt.insert(-3);
	usetInt.insert(2011);
	usetInt.insert(300);
	usetInt.insert(-1000);
	usetInt.insert(989);
	usetInt.insert(-300);
	usetInt.insert(111);

	DisplayContents(usetInt);
	usetInt.insert(999);
	DisplayContents(usetInt);

	//find
	cout << "Enter int you want to check for existence in set: ";
	int key = 0;
	cin >> key;
	auto pairthousand_i = usetInt.find(key);

	if (pairthousand_i != usetInt.cend())
		cout << *pairthousand_i << " found in set" << endl;
	else
		cout << key << " not available in set" << endl;

}
