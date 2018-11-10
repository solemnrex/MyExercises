#include <string>
#include <iostream>

int main()
{
	using namespace std;

	//the sample string
	string str_STL_string("Hello string");

	//access the contents of the string using array syntax
	cout << "display the elements in the string using array-syntax: " << endl;
	for (size_t char_counter = 0; char_counter < str_STL_string.length(); ++char_counter)
	{
		cout << "Character [" << char_counter << "] is: ";
		cout << str_STL_string[char_counter] << endl;
	}
	cout << endl;

	//access the contents of a string using iterator
	cout << "display the elements in the string using iterator: " << endl;
	int char_offset = 0;
	string::const_iterator character_locator_i = str_STL_string.begin();
	for (character_locator_i = str_STL_string.begin()
		; character_locator_i != str_STL_string.end()
		; ++character_locator_i)
	{
		cout << "Character [" << char_offset++ << "] is: ";
		cout << *character_locator_i << endl;
	}
	cout << endl;

	//access the elements of a string  as a C-style string
	cout << "The char* representation of the string is: ";
	cout << str_STL_string.c_str() << endl;

	return 0;
}