#include<string>
#include<iostream>
#include<algorithm>

int main()
{
	using namespace std;

	string str_sample("Hello string! Wake up to a beautiful day!");
	cout << "The original sample string is: " << endl;
	cout << str_sample << endl << endl;

	//Delete character from the string given position and count
	cout << "Truncating the second sentence: " << endl;
	str_sample.erase(13, 28);
	cout << str_sample << endl;

	//find a character 's' in the string using STL algorithm
	string::iterator char_s_i = find(str_sample.begin()
		, str_sample.end(), 's');

	//if character found, erase to deletes a character
	cout << "Erasing character 's' from the sample string: " << endl;
	if (char_s_i != str_sample.end())
		str_sample.erase(char_s_i);

	cout << str_sample << endl << endl;

	//erase a range of character using an overloaded version of erase()
	cout << "Erasing a range between begin() and end(): " << endl;
	str_sample.erase(str_sample.begin(), str_sample.end());

	//Verify the length after the erase() operation above
	if (str_sample.length() == 0)
		cout << "The string is empty" << endl;

	return 0;
}