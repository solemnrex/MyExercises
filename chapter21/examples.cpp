#include "examples.h"

void example1()
{
	vector<int> vec_integers;
	for (int n_count = 0; n_count < 10; ++n_count)
		vec_integers.push_back(n_count);

	list <char> list_chars;
	for (char n_char = 'a'; n_char < 'k'; ++n_char)
		list_chars.push_back(n_char);

	cout << "Displaying the vector of integers: " << endl;

	for_each(vec_integers.begin()
		, vec_integers.end()
		, DisplayElement <int>());

	cout << endl << endl;

	cout << "Displaying the list of characters: " << endl;

	for_each(list_chars.begin()
		, list_chars.end()
		, [](char& element) {cout << element << ' '; });

}

void example2()
{
	vector <int> vec_integers;
	for (int n_count = 0; n_count < 10; ++n_count)
		vec_integers.push_back(n_count);
	
	cout << "Displaying the vector of integers: " << endl;

	DisplayElementKeepCount<int> Result;
	Result = for_each(vec_integers.cbegin()
		, vec_integers.cend(), DisplayElementKeepCount<int>());

	cout << endl << endl;

	cout << "'" << Result.count << "' elements were displayed!" << endl;

}

void example4()
{
	vector <int> vec_integers;
	cout << "The vector contains the following sample values: ";

	for (int n_count = 25; n_count < 32; ++n_count)
	{
		vec_integers.push_back(n_count);
		cout << n_count << ' ';
	}
	cout << endl << "Enter divisor(> 0): ";
	int Divisor = 2;
	cin >> Divisor;

	vector <int>::const_iterator element_i = find_if(vec_integers.cbegin()
		, vec_integers.cend()
		, IsMultiple <int>(Divisor));

	if (element_i != vec_integers.cend())
	{
		cout << "First element in vector dicisible by " << Divisor;
		cout << ": " << *element_i << endl;
	}
}

void example5()
{
	vector <int> vec_multiplicand, vec_multiplier;

	for (int n_count1 = 0; n_count1 < 10; ++n_count1)
		vec_multiplicand.push_back(n_count1);

	for (int n_count2 = 100; n_count2 < 110; ++n_count2)
		vec_multiplier.push_back(n_count2);

	vector <int> vec_result;

	vec_result.resize(10);
	transform(vec_multiplicand.cbegin()
		, vec_multiplicand.cend()
		, vec_multiplier.cbegin()
		, vec_result.begin()
		, Multply<int>());

	cout << "The contents of the first vector are: " << endl;
	for (size_t n_index1 = 0; n_index1 < vec_multiplicand.size(); ++n_index1)
		cout << vec_multiplicand[n_index1] << ' ';
	cout << endl;

	cout << "The contents of the second vector are: " << endl;
	for (size_t n_index2 = 0; n_index2 < vec_multiplier.size(); ++n_index2)
		cout << vec_multiplier[n_index2] << ' ';
	cout << endl;

	cout << "The result of the multiplication are: " << endl;
	for (size_t n_index = 0; n_index < vec_result.size(); ++n_index)
		cout << vec_result[n_index] << ' ';
	cout << endl;

}

void example7()
{
	vector <string> vec_names;

	vec_names.push_back("jim");
	vec_names.push_back("Jack");
	vec_names.push_back("Sam");
	vec_names.push_back("Anna");

	cout << "The names in vector in order of insertion: " << endl;
	DisplayContents(vec_names);

	cout << "Names after sorting using default std::less: " << endl;
	sort(vec_names.begin(), vec_names.end());
	DisplayContents(vec_names);

	cout << "Names after sorting using predicate that ignore case: " << endl;
	sort(vec_names.begin(), vec_names.end(),CompareStringNoCase());
	DisplayContents(vec_names);
}

bool CompareStringNoCase::operator()(const string & str1, const string & str2) const
{
	string str1_lower_case;
	str1_lower_case.resize(str1.size());
	transform(str1.cbegin(), str1.cend(), str1_lower_case.begin(), tolower);

	string str2_lower_case;
	str2_lower_case.resize(str2.size());
	transform(str2.cbegin(), str2.cend(), str2_lower_case.begin(), tolower);
	return (str1_lower_case<str2_lower_case);
}


