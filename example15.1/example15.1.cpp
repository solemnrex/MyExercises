#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//A dynamic array of integers
	vector<int> vec_integer_array;

	//insert sample integers into the array
	vec_integer_array.push_back(50);
	vec_integer_array.push_back(2991);
	vec_integer_array.push_back(23);
	vec_integer_array.push_back(9999);

	cout << "The contents of the vector are: " << endl;

	//walk the vector and read values using an iterator
	vector<int>::iterator array_walker_i = vec_integer_array.begin();

	while (array_walker_i != vec_integer_array.end())
	{
		//write the value to the screen
		cout << *array_walker_i << endl;

		//increment the iterator to access the next element
		++array_walker_i;
	}
	
	//find an element (say 2991) in the array using the 'find' algorithm.
	vector<int>::iterator element_i = find(vec_integer_array.begin()
		, vec_integer_array.end(), 2991);

	//check if value was found
	if (element_i != vec_integer_array.end())
	{
		//value was found...Determine position in the array:
		int position = distance(vec_integer_array.begin(), element_i);
		cout << "value " << *element_i;
		cout << "found in the vector at position: " << position << endl;
	}

	return 0;
}