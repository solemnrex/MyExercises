// example11.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//不能实例化的基类被称为抽象基类，这样的基类只有一个用途，那就是从它派生出其他类。纯虚函数与抽象基类
//

#include "pch.h"
#include <iostream>
using namespace std;

class Fish
{
public:
	virtual void Swim() = 0;

};

class Carp :public Fish
{
public:
	void Swim()
	{
		cout << "Carp swims slow in the lake!" << endl;
	}

};

class Tuna :public Fish
{
public:
	void Swim()
	{
		cout << "Tuna swims fast in the sea!" << endl;
	}

};

void MakeFishSwim(Fish& input_fish)
{
	input_fish.Swim();
}

int main()
{
	//Fish my_fish; //编译报错，纯虚函数的抽象基类不能实例化
	Carp my_lunch;
	Tuna my_dinner;

	MakeFishSwim(my_lunch);
	MakeFishSwim(my_dinner);

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
