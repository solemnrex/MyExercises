//#pragma once
#ifndef EXAMPLES_H
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<typename KeyType>
struct ReverseSort
{
	bool operator () (const KeyType& key1, const KeyType& key2)
	{
		return (key1 > key2);
	}
};

//Type-define the map and multimap definition for easy readability
typedef map<int, string> MAP_INT_STRING;
typedef multimap<int, string> MMAP_INT_STRING;

template <typename T>
void DisplayContents(const T& input)
{
	for (auto element_i = input.cbegin()
		; element_i != input.cend()
		; ++element_i)
		cout << element_i->first << " -> " << element_i->second << endl;
}

template <typename T>
void DisplayContents_n(const T& input)
{
	for (auto element_i = input.cbegin()
		; element_i != input.cend()
		; ++element_i)
		cout << element_i->first << " -> " << element_i->second << endl;
	cout << endl;
}

template <typename T1,typename T2>
void DisplayUnorderedMap(unordered_map<T1,T2>& input)
{
	cout << "Number of pairs, size(): " << input.size() << endl;
	cout << "Max bucket count = " << input.max_bucket_count() << endl;
	cout << "Load factor: " << input.load_factor() << endl;
	cout << "Max load factor = " << input.max_load_factor() << endl;
	cout << "Unordered Map contains: " << endl;

	for (auto element_i = input.cbegin()
		; element_i != input.cend()
		; ++element_i)
		cout << element_i->first << " -> " << element_i->second << endl;

	cout << endl;
}

struct PredIgnoreCase;

typedef map<string, string> DIRECTORY_WITHCASE;
typedef map<string, string, PredIgnoreCase> DIRECTORY_NOCASE;

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
#endif // !EXAMPLES_H
