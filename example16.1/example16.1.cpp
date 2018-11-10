#include <iostream>
#include <string>

int main()
{
	using namespace std;
	const char* const_Cstyle_string = "Hello String!";
	cout << "constant string is: " << const_Cstyle_string << endl;

	std::string str_from_const(const_Cstyle_string);
	cout << "str_from_const is: " << str_from_const << endl;

	std::string str2("Hello String!");
	std::string str2_copy(str2);
	cout << "str2_copy is: " << str2_copy << endl;

	//initialize a string to the first 5 characters of another
	std::string str_partial_copy(const_Cstyle_string, 5);
	cout << "str_partial_copy is: " << str_partial_copy << endl;

	//initialize a string object to contain 10 'a's
	std::string str_repeat_chars(10, 'a');
	cout << "str_repeat_chars is: " << str_repeat_chars << endl;

	return 0;
}