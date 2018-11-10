#include <string>
#include <algorithm>
#include <iostream>
#include "works.h"

int main()
{
	using namespace std;

	cout << "Please enter a string for case-convertion: " << endl;
	cout << ">";

	string str_input;
	getline(cin, str_input);
	cout << endl;

	transform(str_input.begin(), str_input.end(), str_input.begin(), toupper);
	cout << "The string converted to upper case is: " << endl;
	cout << str_input << endl << endl;

	transform(str_input.begin(), str_input.end(), str_input.begin(), tolower);
	cout << "The string converted to lower case is: " << endl;
	cout << str_input << endl << endl;

	//-------------------------
	work1();
	work2();
	work3();
	work4();
	return 0;
}