#include<string>
#include<iostream>

int main()
{
	using namespace	std;

	string str_sample("Good day string! Today is beautiful!");
	cout << "The sample string is: " << endl;
	cout << str_sample << endl << endl;

	//find substring "day" in it
	size_t char_pos = str_sample.find("day", 0);

	//check if the substring is found..
	if (char_pos != string::npos)
		cout << "First instance of \"day\" was found at position " << char_pos;
	else
		cout << "Substring is not found" << endl;

	cout << endl << endl;

	cout << "Locating all instance of \"day\"" << endl;
	size_t sub_string_pos=str_sample.find("day", 0);

	while (sub_string_pos!=string::npos)
	{
		cout << "\"day\" found at position " << sub_string_pos << endl;

		//make find search forward from the next charater
		size_t search_position = sub_string_pos + 1;

		sub_string_pos = str_sample.find("day", search_position);
	}

	cout << endl;

	cout << "Locating all instance of character 'a'" << endl;
	const char char_to_search = 'a';
	char_pos = str_sample.find(char_to_search, 0);

	while (char_pos!=string::npos)
	{
		cout << "'" << char_to_search << "' found";
		cout << " at position: " << char_pos << endl;

		//make find search forward from the next character
		size_t char_search_pos = char_pos + 1;

		char_pos = str_sample.find(char_to_search, char_search_pos);
	}

	return 0;
}