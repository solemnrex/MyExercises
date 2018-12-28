#ifndef EXAMPLES_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <typename elementType>
struct DisplayElement
{
	void operator()(const elementType& element)const
	{
		cout << element << ' ';
	}
};

template <typename elementType>
struct DisplayElementKeepCount
{
	int count;

	DisplayElementKeepCount() :count(0) {}

	void operator()(const elementType& element)
	{
		++count;
		cout << element << ' ';
	}
};

template <typename numberType>
struct IsMultiple
{
	numberType Divisor;

	IsMultiple(const numberType& divisor) :Divisor(divisor) {};

	bool operator ()(const numberType& num)
	{
		return (num % Divisor == 0);
	}
};

template <typename elementType>
class Multply
{
public:
	elementType operator() (const elementType& elem1,
		const elementType& elem2)
	{
		return (elem1 * elem2);
	}
};

class CompareStringNoCase
{
public:
	bool operator()(const string& str1, const string& str2)const;
};

template <typename T>
void DisplayContents(const T& input)
{
	for (auto element_i = input.cbegin(); element_i != input.cend(); ++element_i)
		cout << *element_i << endl;
}


void example1();
void example2();
void example4();
void example5();
void example7();


#endif // !EXAMPLES_H_

