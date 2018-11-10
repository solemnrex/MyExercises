#include "works.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void work1()
{
	cout << "---------This is work1.-----------"<<endl;

	cout << "Input a string. " << endl;
	cout << ">";
	string str_input;
	getline(cin, str_input);
	cout << "Input string is: " << str_input << endl;

	//reverse operation
	string str2reverse(str_input);
	reverse(str2reverse.begin(), str2reverse.end());

	if (str_input == str2reverse)
		cout << "Input string is a huiwen." << endl << endl;
	else
		cout << "Input string is not a huiwen." << endl << endl;
}

void work2()
{
	cout << "---------This is work2.-----------" << endl;

	cout << "Input a string. " << endl;
	cout << ">";
	string str_input;
	getline(cin, str_input);
	cout << "Input string is: " << str_input << endl;

	string str_yy("aeiou");
	size_t counter = 0;
	for (int i = 0; i < str_yy.length(); ++i)
	{
		char char_to_search = str_yy[i];
		string::const_iterator char_pos_i = str_input.begin();
		while (char_pos_i!=str_input.end())
		{
			if (*char_pos_i == char_to_search)
				++counter;
			++char_pos_i;
		}
	}

	cout << "The number of yy is: " << counter << endl;
}

void work3()
{
	cout << "---------This is work3.-----------" << endl;

	cout << "Input a string. " << endl;
	cout << ">";
	string str_input;
	getline(cin, str_input);
	cout << "Input string is: " << str_input << endl;

	int char_index = 0;
	bool flag = true;
	while (char_index != str_input.length())
	{
		if (flag)
			str_input[char_index]=toupper(str_input[char_index]);
		flag = not(flag);
		++char_index;
	}
	cout << "Output is: " << str_input << endl << endl;
}

void work4()
{
	string str1("I");
	string str2("Love");
	string str3("STL");
	string str4("String");

	str1.append(" ");
	str2.append(" ");
	str3.append(" ");
	str4.append(" ");

	str1.append(str2);
	str1.append(str3);
	str1.append(str4);

	cout << str1 << endl;
}