#include <iostream>
using namespace std;


class MyString
{
private:
	char* buffer_;

public:
	//Constructor
	MyString(const char* initial_input)
	{
		if (initial_input != NULL)
		{
			buffer_ = new char[strlen(initial_input) + 1];
			strcpy_s(buffer_, strlen(initial_input)+1,initial_input);
		}
		else
			buffer_ = NULL;
	}

	//insert copy constructor from Listing 9.9
	MyString(const MyString& copy_source);

	//copy assignment operator
	MyString& operator = (MyString& copy_source)
	{
		if ((this != &copy_source) && (copy_source.buffer_ != NULL))
		{
			if (this->buffer_ != NULL)
				delete[] buffer_;

			//ensure deep copy by first allocating own buffer
			buffer_ = new char[strlen(copy_source.buffer_) + 1];

			//copy from the source into local buffer
			strcpy_s(this->buffer_, strlen(copy_source.buffer_) + 1, copy_source.buffer_);
		}
		return *this;
	}

	//Destructor
	~MyString()
	{
		if (buffer_ != NULL)
			delete[] buffer_;
	}

	int GetLength()
	{
		return strlen(buffer_);
	}

	operator const char*()
	{
		return buffer_;
	}
};

int main()
{
	MyString string1("Hello ");
	MyString string2(" world");

	cout << "Before assignment: " << endl;
	cout << string1 << string2 << endl;
	string2 = string1;
	cout << "After assignment string2 = string1: " << endl;
	cout << string1 << string2 << endl;

	return 0;
}