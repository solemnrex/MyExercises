// example9.12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyString
{
public:
	//Constructor
	MyString(const char* initial_input_)
	{
		if (initial_input_ != NULL)
		{
			buffer_ = new char[strlen(initial_input_) + 1];
			strcpy(buffer_, initial_input_);
		}
		else
			buffer_ = NULL;
	}

	//Copy Constructor
	MyString(const MyString& copy_source)
	{
		if (copy_source.buffer_ != NULL)
		{
			buffer_ = new char[strlen(copy_source.buffer_) + 1];
			strcpy(buffer_, copy_source.buffer_);
		}
		else
			buffer_ = NULL;
	}

	~MyString()
	{
		if (buffer_!=NULL)
		{
			delete[] buffer_;
		}
	}

	int GetLength()
	{
		return strlen(buffer_);
	}

	const char* GetString()
	{
		return buffer_;
	}
private:
	char* buffer_;
};

class Human
{
public:
	Human(const MyString& input_name_, int input_age_, bool input_gender)
		:name_(input_name_), age_(input_age_), gender_(input_gender) {}
	int GetAge()
	{
		return age_;
	}

private:
	int age_;
	bool gender_;
	MyString name_;
};



int main()
{
	MyString first_man("Adam");
	MyString first_woman("Eva");
	cout << "sizeof(MyString) = " << sizeof(MyString) << endl;
	cout << "sizeof(first_man) = " << sizeof(first_man) << endl;
	cout << "sizeof(first_woman) = " << sizeof(first_woman) << endl;

	Human first_male_human(first_man, 25, true);
	Human first_female_human(first_woman, 18, false);

	cout << "sizeof(Human) = " << sizeof(Human) << endl;
	cout << "sizeof(first_male_human) = " << sizeof(first_male_human) << endl;
	cout << "sizeof(first_female_human) = " << sizeof(first_female_human) << endl;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
