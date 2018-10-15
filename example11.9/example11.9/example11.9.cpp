// example11.9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 复制构造函数是保证深复制
// 虚函数Clone()，模拟复制构造函数

#include "pch.h"
#include <iostream>
using namespace std;

class Fish
{
public:
	virtual Fish* Clone() = 0;
	virtual void Swim(){};
};

class Tuna :public Fish
{
public:
	Fish* Clone()
	{
		return new Tuna(*this);
	}

	void Swim()
	{
		cout << "Tuna swims fast in the sea" << endl;
	}
};

class Carp :public Fish
{
public:
	Fish* Clone()
	{
		return new Carp(*this);
	}

	void Swim()
	{
		cout << "Carp swims slow in the lake" << endl;
	}
};



int main()
{
	const int kArraySize = 4;

	Fish* my_fishes[kArraySize] = { NULL };
	my_fishes[0] = new Tuna;
	my_fishes[1] = new Carp;
	my_fishes[2] = new Tuna;
	my_fishes[3] = new Carp;

	Fish* my_new_fishes[kArraySize];
	for (int i = 0; i < kArraySize; ++i)
		my_new_fishes[i]=my_fishes[i]->Clone();

	// invoke a virtual method to check
	for (int i = 0; i < kArraySize; ++i)
		my_new_fishes[i]->Swim();

	//memory cleanup
	for (int i = 0; i < kArraySize; ++i)
	{
		delete my_fishes[i];
		delete my_new_fishes[i];
	}
		
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
