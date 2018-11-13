//#pragma once
#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <vector>
#include <iostream>
#include <deque>
//#include <algorithm>
using namespace std;

void example1();
void example2();
void example3();
void example2();
void example4();
void example5();
void example6();
void example7();
void example8();

template<typename T>
//void DisplayVector(const vector<T>& vec_input);
void DisplayVector(const vector<T>& vec_input)
{
	//vector<int>::const_iterator->auto
	for (vector<T>::const_iterator element_i = vec_input.cbegin();
		element_i != vec_input.cend(); ++element_i)
		cout << *element_i << ' ';

	cout << endl;
}

#endif // !EXAMPLE_H


