#include "example.h"

void example1()
{
	std::vector<int> vec_integers;

	//instantiate a vector with 10 elements (it can grow larger)
	std::vector <int> vec_10_initialze_element(10, 90);

	//instantiate one vector and initializa it to the contents of another
	std::vector<int> vec_array_copy(vec_10_initialze_element);

	//using iterators instantiate vector to 5 elements from another
	std::vector <int> vec_some_elements_copied(vec_10_initialze_element.cbegin(),
		vec_10_initialze_element.cbegin() + 5); //cbegin() and cend() will return a iterator 
}

void example2()
{
	vector <int> vec_integers;

	//insert sample integers into the vector:
	vec_integers.push_back(50);
	vec_integers.push_back(1);
	vec_integers.push_back(987);
	vec_integers.push_back(100);

	cout << "The vector contains ";
	cout << vec_integers.size() << " Elements" << endl;
}

void example3()
{
	//instantiate a vector with 4 elements, each initialized to 90
	vector <int> vec_integers(4, 90);
	cout << "The initial contents of the vector: ";
	DisplayVector(vec_integers);

	//insert 25 at the beginning
	vec_integers.insert(vec_integers.begin(), 25);

	//insert 2 numbers of value 45 at the end
	vec_integers.insert(vec_integers.end(), 2, 45);

	cout << "Vector after inserting elements at beginning and end: ";
	DisplayVector(vec_integers);

	//another vector containing 2 elements of value 30
	vector <int> vec_another(2, 30);

	//insert two elements from another container in position [1]
	vec_integers.insert(vec_integers.begin() + 1,
		vec_another.begin(), vec_another.end());

	cout << "Vector after inserting contents from another vector: ";
	cout << "in the middle:" << endl;
	DisplayVector(vec_integers);
}

void example4()
{
	vector <int> vec_integer_array{ 50,1,987,1001 };//or vector <int> vec_integer_array = {50,1,987,1001}

	for (size_t index = 0; index < vec_integer_array.size(); ++index)
	{
		cout << "Element[" << index << "] = ";
		cout << vec_integer_array[index] << endl;
	}

	//chaging 3rd integer from 987 to 2011
	vec_integer_array[2] = 2011;
	cout << "After replacement: " << endl;
	cout << "Element[2] = " << vec_integer_array[2] << endl;
}

void example5()
{
	vector <int> vec_integers;
	vec_integers = { 50,1,987,1001 };

	//access objects in a vectors:
	vector<int>::iterator element_locator_i = vec_integers.begin();//vector<int>::iterator->auto

	while (element_locator_i != vec_integers.end())
	{
		size_t index = distance(vec_integers.begin(), element_locator_i);

		cout << "Element at position ";
		cout << index << " is: " << *element_locator_i << endl;

		//move to the next element
		++element_locator_i;
	}
}

void example6()
{
	vector<int> vec_integers{ 50,1,987,1001 };

	cout << "Vector contains " << vec_integers.size() << " elements: ";
	DisplayVector(vec_integers);

	//Erase one element at the end
	vec_integers.pop_back();

	cout << "After a call to pop_back()" << endl;
	cout << "Vector contains " << vec_integers.size() << " elements: ";
	DisplayVector(vec_integers);
}

void example7()
{
	//instantiate a vector object holds 5 integers of default value
	vector <int> vec_integers(5);
	cout << "vector of integers was instantiate with " << endl;
	cout << "Size: " << vec_integers.size();
	cout << ", Capacity: " << vec_integers.capacity() << endl;

	//insert a 6th element in to the vector
	vec_integers.push_back(666);

	cout << "After inserting additional element... " << endl;
	cout << "Size: " << vec_integers.size();
	cout << ", Capacity: " << vec_integers.capacity() << endl;

	vec_integers.push_back(777);

	cout << "After inserting yet another element... " << endl;
	cout << "Size: " << vec_integers.size();
	cout << ", Capacity: " << vec_integers.capacity() << endl;
}

void example8()
{
	deque <int>dq_integers ;

	dq_integers.push_back(3);
	dq_integers.push_back(4);
	dq_integers.push_back(5);

	dq_integers.push_front(2);
	dq_integers.push_front(1);
	dq_integers.push_front(0);

	cout << "The contents of the deque after inserting elements ";
	cout << "at the top and bottom are:" << endl;

	for (size_t ncount = 0
		; ncount < dq_integers.size()
		; ++ncount)
	{
		cout << "Element [" << ncount << "] = ";
		cout << dq_integers[ncount] << endl;
	}

	cout << endl;

	dq_integers.pop_front();
	dq_integers.pop_back();
	
	cout << "The contents of deque after erasing an element ";
	cout << "from the top and bottom are: " << endl;

	for (deque<int>::iterator element_i = dq_integers.begin()
		; element_i != dq_integers.end()
		; ++element_i)
	{
		size_t offset = distance(dq_integers.begin(), element_i);
		cout << "Element [" << offset << "] = " << *element_i << endl;
	}
}