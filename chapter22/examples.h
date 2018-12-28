#pragma once
#ifndef EXAMPLES_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using namespace std;

void example1();
void example2();
void example3();
void example4();
void example5();

template <typename T>
void DisplayContents(const T& input)
{
	for (auto element_i = input.cbegin(); element_i != input.cend(); ++element_i)
		cout << *element_i << endl;
}
#endif // !EXAMPLES_H_
