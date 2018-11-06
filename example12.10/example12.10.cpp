#include <iostream>
#include <string>
using namespace std;

class MyString
{
private:
	char* buffer_;

	//private default constructor
	MyString() {}

public:
	//constructor
	MyString(const char* initial_input)
	{
		if (initial_input != NULL)
		{
			buffer_ = new char[strlen(initial_input) + 1];
			strcpy_s(buffer_, strlen(initial_input) + 1, initial_input);
		}
		else
			buffer_ = NULL;
	}

	//copy constructor: insert from listing 9.9 here
	MyString(const MyString& copy_source);

	//copy assignment operator: insert from listing 12.9 here
	const char& operator =(const MyString& copy_source);

	const char& operator [](int index)const
	{
		if (index < strlen(buffer_))
			return buffer_[index];
	}

	//Destructor
	~MyString()
	{
		if (buffer_ != NULL)
			delete buffer_;
	}

	int GetLength() const
	{
		return strlen(buffer_);
	}

	operator const char* ()
	{
		return buffer_;
	}
};

int main()
{
	cout << "Type a statement: ";
	string strinput;
	getline(cin, strinput);

	MyString you_said(strinput.c_str());

	cout << "Using operator [] for displaying you input: " << endl;
	for (int i = 0; i < you_said.GetLength(); ++i)
		cout << you_said[i] << " ";
	cout << endl;

	cout << "Enter index 0 - " << you_said.GetLength() - 1 << ": ";
	int index = 0;
	cin >> index;
	cout << "Input character at zero-based position: " << index;
	cout << " is " << you_said[index] << endl;

	return 0;
}