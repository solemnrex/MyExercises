// example12.4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

template <typename T>
class smart_pointer
{
private:
	T* m_raw_pointer_ptr; 
public:
	smart_pointer(T* data_ptr) :m_raw_pointer_ptr(data_ptr) {} //constructor
	~smart_pointer() { delete m_raw_pointer_ptr;} //destructor

	T& operator* () const //dereferencing operator
	{
		return *(m_raw_pointer_ptr);
	}

	T* operator-> () const //member selection operator
	{
		return m_raw_pointer_ptr;
	}

};

class Data
{
private:
	int day_, month_, year_;
	string data_in_string_;
public:
	//constructor that initializes the object to a day, month and year
	Data(int input_day, int input_month, int input_year)
		:day_(input_day), month_(input_month), year_(input_year) {};

	void DisplayData()
	{
		cout << day_ << " / " << month_ << " / " << year_ << endl;
	}
};
int main()
{
	smart_pointer<int> dynamic_int_ptr(new int(42));
	cout << "Dynamically allocated integer value = " << *dynamic_int_ptr << endl;

	smart_pointer<Data> data_ptr(new Data(25, 11, 2018));
	cout << "Data is = ";
	data_ptr->DisplayData();

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
