#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string str_sample1("Hello");
	string str_sample2(" String!");

	//concatenate
	str_sample1 += str_sample2;
	cout << str_sample1 << endl << endl;

	string  str_sample3(" Fun is not needing to use pointers!");
	str_sample1.append(str_sample3);
	cout << str_sample1 << endl << endl;

	const char* const_cstyle_string = " You however still can!";
	str_sample1.append(const_cstyle_string);
	cout << str_sample1 << endl;

	return 0;
}