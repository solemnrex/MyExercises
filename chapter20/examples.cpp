#include "examples.h"

void example1()
{
	//map and multimap key of type int to value of type string
	map<int, string> map_int_to_string1;
	multimap<int, string> mmap_int_to_string1;

	//map and multimap constructed as a copy of another;
	map<int, string> map_int_to_string2(map_int_to_string1);
	multimap<int, string> mmap_int_to_string2(mmap_int_to_string1);

	//map and multimap constructed given a part of another map or multimap
	map<int, string> map_int_to_string3(map_int_to_string1.cbegin(),
		map_int_to_string1.cend());
	multimap<int, string> mmap_int_to_string3(mmap_int_to_string1.cbegin(),
		mmap_int_to_string1.cend());

	//map and multimap with a predict that inverse sort order
	map<int, string, ReverseSort<int>> map_int_to_string4(map_int_to_string1.cbegin(),
		map_int_to_string1.cend());
	multimap<int, string, ReverseSort<int>> mmap_int_to_string4(mmap_int_to_string1.cbegin(),
		mmap_int_to_string1.cend());
}

void example2()
{
	MAP_INT_STRING map_int_to_string;

	//insert key-value pairs int the map using value_type
	map_int_to_string.insert(MAP_INT_STRING::value_type(3, "Three"));

	//insert key-value pairs int the map using function make_pair
	map_int_to_string.insert(make_pair(-1, "Minus One"));

	//Insert a pair object directly
	map_int_to_string.insert(pair<int, string>(1000, "One Thousand"));

	//Insert using an array-like syntax for inserting key-value pairs
	map_int_to_string[1000000] = "One Million";

	cout << "The map contains " << map_int_to_string.size();
	cout << " key-value pairs. They are: " << endl;
	DisplayContents(map_int_to_string);

	//instantiate a multimap that is a copy of a map
	MMAP_INT_STRING mmap_int_to_string(map_int_to_string.cbegin(),
		map_int_to_string.cend());

	/*The insert function works the same way for multimap too
	A multimap can store duplicates - insert a duplicates*/
	mmap_int_to_string.insert(make_pair(1000, "One Thousand"));

	cout << endl << "The multimap contains " << mmap_int_to_string.size();
	cout << " key-value pairs. They are: " << endl;
	DisplayContents(mmap_int_to_string);

	//The mulimap can also return the number of pairs with the same key
	cout << "The number of pairs in the multimap with 1000 as their key: "
		<< mmap_int_to_string.count(1000) << endl;
}

void example3()
{
	map<int,string> map_int_to_string;

	map_int_to_string.insert(make_pair(3, "Three"));
	map_int_to_string.insert(make_pair(45, "Forty Five"));
	map_int_to_string.insert(make_pair(-1, "Minus One"));
	map_int_to_string.insert(make_pair(1000, "One Thousand"));

	cout << "The map contains " << map_int_to_string.size();
	cout << " key-value pairs. They are: " << endl;
	DisplayContents(map_int_to_string);

	cout << "Enter the key you wish to find: ";
	int Key = 0;
	cin >> Key;

	auto PairFound_i = map_int_to_string.find(Key);
	if (PairFound_i != map_int_to_string.cend())
	{
		cout << "Key " << PairFound_i->first << " points to value: ";
		cout << PairFound_i->second << endl;
	}
	else
		cout << "Sorry, pair with key " << Key << " not in map" << endl;
}

void example4()
{
	multimap<int, string> mmap_int_to_string;

	mmap_int_to_string.insert(make_pair(3, "Three"));
	mmap_int_to_string.insert(make_pair(45, "Forty Five"));
	mmap_int_to_string.insert(make_pair(-1, "Minus One"));
	mmap_int_to_string.insert(make_pair(1000, "One Thousand"));

	mmap_int_to_string.insert(make_pair(-1, "Minus One"));
	mmap_int_to_string.insert(make_pair(1000, "One Thousand"));

	cout << endl << "The multimap contains " << mmap_int_to_string.size();
	cout << " key-value pairs. They are: " << endl;
	DisplayContents_n(mmap_int_to_string);

	//Erasing an element with key as -1 from the multimap
	auto NumPairsErased = mmap_int_to_string.erase(-1);
	cout << "Erased " << NumPairsErased << " pairs with -1 as key." << endl;

	//Erase an element given an iterator from the multimap
	auto PairFound_i = mmap_int_to_string.find(45);
	if (PairFound_i != mmap_int_to_string.cend())
	{
		mmap_int_to_string.erase(PairFound_i);
		cout << "Erased a pair with 45 as key using an iterator"<< endl;
	}

	//Erase a range from the multimap...
	cout << "Erasing the range of pairs with 1000 as key." << endl;
	mmap_int_to_string.erase(mmap_int_to_string.lower_bound(1000)
		, mmap_int_to_string.upper_bound(1000));

	
	cout << endl << "The multimap now contains " << mmap_int_to_string.size();
	cout << " key-value pairs. They are: " << endl;
	DisplayContents_n(mmap_int_to_string);

}

struct PredIgnoreCase
{
	bool operator () (const string& str1, const string& str2) const
	{
		string str1_no_case(str1), str2_no_case(str2);
		std::transform(str1.cbegin(), str1.cend(), str1_no_case.begin(), tolower);
		std::transform(str2.cbegin(), str2.cend(), str2_no_case.begin(), tolower);

		return (str1_no_case < str2_no_case);
	}
};
		
void example5()
{
	DIRECTORY_NOCASE dir_case_insensitive;

	dir_case_insensitive.insert(make_pair("John", "2345764"));
	dir_case_insensitive.insert(make_pair("JOHN", "2345764"));
	dir_case_insensitive.insert(make_pair("Sara", "42367236"));
	dir_case_insensitive.insert(make_pair("Jack", "32435348"));

	cout << "Displaying contents of the case-insensitive map:" << endl;
	DisplayContents_n(dir_case_insensitive);

	//case sensitive map: case of string-key affects insertion & search
	DIRECTORY_WITHCASE dir_case_sensitive(dir_case_insensitive.cbegin()
		, dir_case_insensitive.cend());

	cout << "Displaying contents of the case-sensitive map:" << endl;
	DisplayContents_n(dir_case_sensitive);

	//search for a name in the two maps and display result
	cout << "Please enter a name to search: " << endl << "> ";
	string str_name_input;
	cin >> str_name_input;

	//find in the map...
	auto pair_in_nocase_dir_i = dir_case_insensitive.find(str_name_input);
	if (pair_in_nocase_dir_i != dir_case_insensitive.cend())
	{
		cout << pair_in_nocase_dir_i->first << "'s number in the case-insensitive";
		cout << " directory is: " << pair_in_nocase_dir_i->second << endl;
	}
	else
	{
		cout << str_name_input << "'s number not found ";
		cout << "in the case-insensitive directory" << endl;
	}

	//find in the case-sensitive map...
	auto pair_in_casesens_dir_i = dir_case_sensitive.find(str_name_input);
	if (pair_in_casesens_dir_i != dir_case_sensitive.cend())
	{
		cout << pair_in_casesens_dir_i->first << "'s number in the case-insensitive";
		cout << " directory is: " << pair_in_casesens_dir_i->second << endl;
	}
	else
	{
		cout << str_name_input << "'s number not found ";
		cout << "in the case-sensitive directory" << endl;
	}
}

void example6()
{
	unordered_map<int, string> umap_int_to_string;
	umap_int_to_string.insert(make_pair(1, "One"));
	umap_int_to_string.insert(make_pair(45, "Forty Five"));
	umap_int_to_string.insert(make_pair(1001, "Thousand One"));
	umap_int_to_string.insert(make_pair(-2, "Minus Two"));
	umap_int_to_string.insert(make_pair(-1000, "Minus One Thousand"));
	umap_int_to_string.insert(make_pair(100, "One Hundred"));
	umap_int_to_string.insert(make_pair(12, "Twelve"));
	umap_int_to_string.insert(make_pair(-100, "Minus One Hundred"));

	DisplayUnorderedMap<int, string>(umap_int_to_string);
	
	cout << "Inserting one more element" << endl;
	umap_int_to_string.insert(make_pair(300, "Three Hundred"));
	DisplayUnorderedMap<int, string>(umap_int_to_string);

	cout << "Enter the key you wish to find: ";
	int Key = 0;
	cin >> Key;

	auto element_i = umap_int_to_string.find(Key);
	if (element_i != umap_int_to_string.cend())
	{
		cout << "Found! Key " << element_i->first << " points to value: ";
		cout << element_i->second << endl;
	}
	else
		cout << Key << " has no corresponding value in unordered map" << endl;
}


