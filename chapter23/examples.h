//#pragma once
#ifndef EXAMPLE_H_
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
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

	cout << endl;
}

void example1();
void example2();
void example3();
void example4();
void example5();

#endif // !EXAMPLE_H_
