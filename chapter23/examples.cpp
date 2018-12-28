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
