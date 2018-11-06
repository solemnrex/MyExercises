#include <iostream>
using namespace std;

class MyString
{
private:
	char* buffer_;

	//private default constructor
	MyString():buffer_(NULL)
	{
		cout << "Default constructor called" << endl;
	}

public:
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

	MyString operator + (const MyString& add_this)
	{
		cout << "operator + called: " << endl;
		MyString new_string;

		if (add_this.buffer_ != NULL)
		{
			new_string.buffer_ = new char [this->GetLength() + strlen(add_this.buffer_) + 1];

			strcpy_s(new_string.buffer_, this->GetLength() + strlen(add_this.buffer_) + 1, buffer_);
			strcat_s(new_string.buffer_, this->GetLength() + strlen(add_this.buffer_) + 1, add_this.buffer_);
		}
		return new_string;
	}

	//constructor
	MyString(const char* initial_input)
	{
		cout << "Constructor called for: " << initial_input << endl;
		if (initial_input != NULL)
		{
			buffer_ = new char[strlen(initial_input) + 1];
			strcpy_s(buffer_, strlen(initial_input) + 1, initial_input);
		}
		else
			buffer_ = NULL;
	}

	//copy constructor: insert from listing 9.9 here
	MyString(const MyString& copy_source)
	{
		cout << "Copy constructor to copy from: " << copy_source.buffer_ << endl;
		if (copy_source.buffer_ != NULL)
		{
			//ensure deep copy by first allocating own buffer
			buffer_ = new char[copy_source.GetLength() + 1];

			//copy from the source into local buffer
			strcpy_s(buffer_, copy_source.GetLength() + 1, copy_source.buffer_);
		}
		else
			buffer_ = NULL;

	}


	//copy assignment operator: insert from listing 12.9 here
	MyString& operator =(const MyString& copy_source)
	{
		cout << "Copy assignment operator to copy from: " << copy_source.buffer_ << endl;
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

	//move constructor: insert from listing 9.9 here
	MyString(MyString&& move_source)
	{
		cout << "Move constructor to copy from: " << move_source.buffer_ << endl;
		if (move_source.buffer_ != NULL)
		{
			buffer_ = move_source.buffer_;
			move_source.buffer_ = NULL;
		}
	}
	
	//move assignment operator: insert from listing 12.9 here
	MyString& operator =(MyString&& move_source)
	{
		cout << "move assignment operator to copy from: " << move_source.buffer_ << endl;
		if ((this != &move_source) && (move_source.buffer_ != NULL))
		{
			delete[] buffer_;

			buffer_ = move_source.buffer_;
			move_source.buffer_ = NULL;
		}

		return *this;
	}
};

int main()
{
	MyString hello("Hello ");
	MyString world("world");
	MyString CPP(" of C++");

	MyString say_hello_again("overwrite this");
	say_hello_again = hello + world + CPP;

	return 0;
}