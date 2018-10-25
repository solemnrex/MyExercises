// example12.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <memory>
using namespace std;

class Date
{
private:
	int day_;
	int month_;
	int year_;
	
	string date_in_string_;

public:
	Date(int input_day, int input_month, int input_year)
		:day_(input_day), month_(input_month), year_(input_year) {};
	void DisplayDate()
	{
		cout << day_ << "/" << month_ << "/" << year_ << endl;
	}
};

int main()
{
	unique_ptr<int> dynamic_alloc_integer_ptr(new int);
	*dynamic_alloc_integer_ptr = 42;

	//Use smart pointer type like an int*
	cout << "Interger value is: " << *dynamic_alloc_integer_ptr << endl;

	unique_ptr<Date> holiday_ptr(new Date(25, 11, 2011));
	cout << "The new instace of date contains: ";

	//Use holiday_ptr just as you would d Date*
	holiday_ptr->DisplayDate();

	//no need to do the following when using unique_ptr:
	//delete dynamic_alloc_integer_ptr;
	//delete holiday_ptr;

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
