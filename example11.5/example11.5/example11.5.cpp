// example11.5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//Base类相比于SimpleClass多了一个虚函数，因此其虚函数表指针会占用空间。
//在C 中, 可使用类型转换运算符dynamic_cast确定Base指针指向的是否是Derived对象, 再根据结果执行额外的操作。
//这被称为运行阶段类型识别（Run Time Type Identification，RTTI）。虽然大多数C 编译器都支持RTTI，但应尽
//可能避免这样做。因为需要知道基类指针指向的是派生类对象通常是一种糟糕的编程实践。
//

#include "pch.h"
#include <iostream>
using namespace std;

class SimpleClass
{
	int a, b;
public:
	void FuncDoSomething() {}
};

class Base
{
	int a, b;
public:
	virtual void FuncDoSomething() {}
};



int main()
{
	cout << "sizeof(SimpleClass) = " << sizeof(SimpleClass) << endl;
	cout << "sizeof(Base) = " << sizeof(Base) << endl;

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
