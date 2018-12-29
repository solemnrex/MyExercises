//#pragma once
#ifndef EXAMPLE_H_
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <string>
using namespace std;

template <typename T>
bool is_even(const T& num) 
{
	return ((num % 2) == 0);
}

template <typename T>
void DisplayContents(const T& input)
{
	for (auto element_i = input.cbegin()
		; element_i != input.cend()
		; ++element_i)
		cout << *element_i << ' ';

	cout << "| Number of elements: " << input.size() << endl;
}

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

template <typename T>
void DisplayContentsLines(const T& input)
{
	for (auto element_i = input.cbegin()
		; element_i != input.cend()
		; ++element_i)
		cout << *element_i << endl;

	cout << "| Number of elements: " << input.size() << endl;
}


void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
void example7();
void example8();
void example9();
void example10();
void example11();
void example12();

#endif // !EXAMPLE_H_
