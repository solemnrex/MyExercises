#include "examples.h"

void example1()
{
	vector<int> vec_integers;

	for (int sample_value = -9; sample_value < 10; ++sample_value)
		vec_integers.push_back(sample_value);

	cout << "Enter number to find in collection: ";
	int num_to_find = 0;
	cin >> num_to_find;

	auto element_i = find(vec_integers.cbegin()
		, vec_integers.cend()
		, num_to_find);
	
	if (element_i != vec_integers.cend())
		cout << "Result: Value " << *element_i << " found!" << endl;
	else
		cout << "Result: No element contains value " << num_to_find << endl;

	auto even_number_i = find_if(vec_integers.cbegin()
		, vec_integers.cend()
		, [](const int& num) {return (num % 2) == 0; });

	if (even_number_i != vec_integers.cend())
	{
		cout << "Number '" << *even_number_i << "' found at position [";
		cout << distance(vec_integers.cbegin(), even_number_i);
		cout << "]" << endl;
	}

}

void example2()
{
	vector<int> vec_integers;

	cout << "Populating a vector<int> with values from -9 to 9" << endl;

	for (int sample_value = -9; sample_value < 10; ++sample_value)
		vec_integers.push_back(sample_value);

	size_t n_zeros = count(vec_integers.cbegin(), vec_integers.cend(), 0);
	cout << "Number of instances of '0': " << n_zeros << endl << endl;

	size_t n_evens = count_if(vec_integers.cbegin()
		, vec_integers.cend()
		, is_even<int>
	);
	cout << "Number of even elements: " << n_evens << endl;
	cout << "Number of odd elements: ";
	cout << vec_integers.size() - n_evens << endl;
}

void example3()
{
	vector<int> vec_integers;
	for (int sample_value = -9; sample_value < 10; ++sample_value)
		vec_integers.push_back(sample_value);

	vec_integers.push_back(9);
	vec_integers.push_back(9);

	list <int> list_integers;
	for (int sample_value = -4; sample_value < 5; ++sample_value)
		list_integers.push_back(sample_value);

	cout << "The contents of the sample vector are: " << endl;
	DisplayContents(vec_integers);

	cout << "The contents of the list vector are: " << endl;
	DisplayContents(list_integers);

	cout << "Search() for the contents of list in vector:" << endl;
	auto range_i = search(vec_integers.cbegin()
		, vec_integers.cend()
		, list_integers.cbegin()
		, list_integers.cend());

	if (range_i != vec_integers.cend())
	{
		cout << "Sequence in list found in vector at position: ";
		cout << distance(vec_integers.cbegin(), range_i) << endl;
	}

	cout << "Searching {9, 9, 9} in vector using search_n(): " << endl;
	auto partial_range_i = search_n(vec_integers.cbegin()
		, vec_integers.cend()
		, 3
		, 9);

	if (partial_range_i != vec_integers.cend())
	{
		cout << "Searching {9, 9, 9} found in vector at position: ";
		cout << distance(vec_integers.cbegin(), partial_range_i) << endl;
	}
}

void example4()
{
	vector <int> vec_integers(3);
	fill(vec_integers.begin(), vec_integers.end(), 9);

	vec_integers.resize(6);
	fill_n(vec_integers.begin() + 3, 3, -9);
	cout << "The contents of the vector are: " << endl;
	DisplayContents(vec_integers);

}

void example5()
{
	vector<int> vec_integers(10);
	generate(vec_integers.begin(), vec_integers.end(), rand);
	cout << "Elements in the vector of size " << vec_integers.size();
	cout << " assigned by 'generat' are: " << endl << "{";
	for (size_t i = 0; i < vec_integers.size(); ++i)
		cout << vec_integers[i] << " ";
	cout << "}" << endl << endl;

	list<int> list_integers(10);
	generate_n(list_integers.begin(), 5, rand);
	cout << "Elements in the list of size " << list_integers.size();
	cout << " assigned by 'generat_n' are: " << endl << "{";
	list <int>::const_iterator locator_i = list_integers.cbegin();
	for (locator_i; locator_i != list_integers.cend(); ++locator_i)
		cout << *locator_i << " ";
	cout << "}" << endl;
}

void example6()
{
	vector <int> vec_integers;
	for (int n_count = 0; n_count < 10; ++n_count)
		vec_integers.push_back(n_count);

	cout << "Displaying the vector of integers: " << endl;
	DisplayElementKeepCount<int> functor =
		for_each(vec_integers.cbegin(), vec_integers.cend(), DisplayElementKeepCount<int>());
	cout << endl;

	cout << "'" << functor.count << "' elements were displayed" << endl;

	string sample("for_each and strings!");
	cout << "String: " << sample << ", length " << sample.length() << endl;

	cout << "String displayed using lambda:" << endl;
	int n_chars = 0;
	for_each(sample.cbegin()
		, sample.cend()
		, [&n_chars](const char& s) {++n_chars; cout << s << ' '; });
	cout << endl;
	cout << "'" << n_chars << "' characters were displayed" << endl;
}

void example7()
{
	string sample("THIS is a TEst string!");
	cout << "The sample string is: " << sample << endl;

	string str_lower_copy;
	str_lower_copy.resize(sample.size());

	transform(sample.cbegin()
		, sample.cend()
		, str_lower_copy.begin()
		, tolower);
	cout << "Result of 'transform' on the string with 'tolower':" << endl;
	cout << "\"" << str_lower_copy << "\"" << endl << endl;

	vector<int> vec_integers1, vec_integers2;
	for (int n_num = 0; n_num < 10; ++n_num)
	{
		vec_integers1.push_back(n_num);
		vec_integers2.push_back(10 - n_num);
	}

	deque <int> dq_result_addition(vec_integers1.size());
	transform(vec_integers1.cbegin()
		, vec_integers1.cend()
		, vec_integers2.cbegin()
		, dq_result_addition.begin()
		, plus<int>());
	
	cout << "Result of 'transform' using binary function 'plus':" << endl;
	cout << endl << "Index \t vec_integers1 \t+ vec_integers2  \t   =  Result(in deque)" << endl;
	for (size_t n_index = 0; n_index < vec_integers1.size(); ++n_index)
	{
		cout << n_index << "     \t     " << vec_integers1[n_index] << "     \t+       ";
		cout << vec_integers2[n_index] << " \t   =   ";
		cout << dq_result_addition[n_index] << endl;
	}

}

void example8()
{
	list<int> list_integers;
	for (int n_count = 0; n_count < 10; ++n_count)
		list_integers.push_back(n_count);

	cout << "Source (list) contents: " << endl;
	DisplayContents(list_integers);

	vector <int> vec_integers(list_integers.size() * 2);
	
	auto last_pos_i = copy(list_integers.cbegin()
		, list_integers.cend()
		, vec_integers.begin());

	copy_if(list_integers.cbegin()
		, list_integers.cend()
		, last_pos_i
		, [](const int & num) {return (num % 2) == 1; });

	cout << "Destination (vector) after copy and copy_if:" << endl;
	DisplayContents(vec_integers);

	//Remove all instances of '0', resize vector using erase()
	auto new_end_i = remove(vec_integers.begin(), vec_integers.end(), 0);
	vec_integers.erase(new_end_i, vec_integers.end());

	new_end_i = remove_if(vec_integers.begin()
		, vec_integers.end()
		, [](const int & num) {return (num % 2) == 1; });
	vec_integers.erase(new_end_i, vec_integers.end());//resizing

	cout << "Destination (vector) after remove,remove_if erase:" << endl;
	DisplayContents(vec_integers);

}

void example9()
{
	vector <int> vec_integers(6);

	fill(vec_integers.begin(), vec_integers.begin() + 3, 8);
	fill_n(vec_integers.begin() + 3, 3, 5);

	//shuffle the container
	random_shuffle(vec_integers.begin(), vec_integers.end());

	cout << "The initial contents of the vector are: " << endl;
	DisplayContents(vec_integers);

	cout << endl << "Using 'std::replace' to replace value 5 by 8" << endl;
	replace(vec_integers.begin(), vec_integers.end(), 5, 8);

	cout << "Using 'std::replace_if' to replace even value by -1" << endl;
	replace_if(vec_integers.begin()
		, vec_integers.end()
		, [](const int& num) {return (num % 2) == 0; }, -1);

	cout << endl << "Contents of the vector after replacements:" << endl;
	DisplayContents(vec_integers);
}

void example10()
{
	vector <string> vec_names;
	vec_names.push_back("John Doe");
	vec_names.push_back("Jack Nicholson");
	vec_names.push_back("Sean Penn");
	vec_names.push_back("Anna Hoover");

	//insert a duplicate into the vector
	vec_names.push_back("Jack Nicholson");

	cout << "The initial contents of the vector are: " << endl;
	DisplayContentsLines(vec_names);

	cout << "The sorted vector contents names in the order:" << endl;
	sort(vec_names.begin(), vec_names.end());
	DisplayContentsLines(vec_names);

	cout << "Searching for \"John Doe\" using 'binary_search':" << endl;
	bool element_found = binary_search(vec_names.cbegin(), vec_names.cend(), "John Doe");

	if (element_found)
		cout << "Result: \"John Doe\" was found in the vector!" << endl;
	else
		cout << "Element not found " << endl;

	auto new_end_i = unique(vec_names.begin(), vec_names.end());
	vec_names.erase(new_end_i, vec_names.end());

	cout << "The contents of the vector after using 'unique':" << endl;
	DisplayContentsLines(vec_names);
}

void example11()
{
	vector <int> vec_integers;
	for (int n_num = 0; n_num < 10; ++n_num)
		vec_integers.push_back(n_num);

	cout << "The initial contents: " << endl;
	DisplayContents(vec_integers);

	vector <int> vec_copy(vec_integers);
	
	cout << "The effect of using partition():" << endl;
	partition(vec_integers.begin(), vec_integers.end(), is_even<int>);
	DisplayContents(vec_integers);

	cout << "The effect of using stable_partition():" << endl;
	stable_partition(vec_copy.begin(), vec_copy.end(), is_even<int>);
	DisplayContents(vec_copy);
}

void example12()
{
	list <string> list_names;
	list_names.push_back("John Doe");
	list_names.push_back("Brad Pitt");
	list_names.push_back("Jack Nicholson");
	list_names.push_back("Sean Penn");
	list_names.push_back("Anna Hoover");

	cout << "The sorted contents of the list are: " << endl;
	list_names.sort();
	DisplayContentsLines(list_names);

	cout << "The lowest index where \"Brad Pitt\" can be insert is:";
	auto min_insert_pos_i = lower_bound(list_names.begin(), list_names.end()
		, "Brad Pitt");
	cout << distance(list_names.begin(), min_insert_pos_i) << endl;

	cout << "The highest index where \"Brad Pitt\" can be insert is:";
	auto max_insert_pos_i = lower_bound(list_names.begin(), list_names.end()
		, "Brad Pitt");
	cout << distance(list_names.begin(), max_insert_pos_i) << endl;

	cout << endl;

	cout << "List after inserting Brad Pitt in  sorted order: " << endl;
	list_names.insert(min_insert_pos_i, "Brad Pitt");

	DisplayContentsLines(list_names);


}
