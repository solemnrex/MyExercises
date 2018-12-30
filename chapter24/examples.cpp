#include "examples.h"

void example1()
{
	stack <int> stack_ints;
	stack <double> stack_doubles;

	//A stack of doubles contained in a vector
	stack <double, vector<double>> stack_doubles_in_vector;

	stack <int> stack_ints_copy(stack_ints);
}

void example2()
{
	stack <int> stack_ints;
	
	cout << "Pushing {25, 10, -1, 5} on stack in that order:" << endl;
	stack_ints.push(25);
	stack_ints.push(10);
	stack_ints.push(-1);
	stack_ints.push(5);

	cout << "Stack contains " << stack_ints.size() << " elements" << endl;
	while (stack_ints.size() != 0)
	{
		cout << "Popping topmost element: " << stack_ints.top() << endl;
		stack_ints.pop();
	}

	if (stack_ints.empty())
		cout << "Popping all elements empties stack!" << endl;

}

void example3()
{
	queue <int> q_integers;
	queue <double> q_doubles;
	queue <double, list<double>> q_doubles_in_list;
	queue <int> q_copy(q_integers);
}

void example4()
{
	queue <int> q_integers;

	cout << "Pushing {10, 5, -1, 20} into queue:" << endl;
	q_integers.push(10);
	q_integers.push(5);
	q_integers.push(-1);
	q_integers.push(20);

	cout << "Queue contains " << q_integers.size() << " elements" << endl;
	cout << "Element at front: " << q_integers.front() << endl;
	cout << "Element at back: " << q_integers.back() << endl;

	while (q_integers.size() != 0)
	{
		cout << "Deleting element: " << q_integers.front() << endl;
		q_integers.pop();
	}

	if (q_integers.empty())
		cout << "The queue now is empty!" << endl;
}

void example5()
{
	priority_queue <int> pq_integers;
	priority_queue <double> pq_doubles;
	priority_queue <int, deque<int>, greater<int>> pq_integers_inverse;
	priority_queue <int> pq_copy(pq_integers);
}

void example6()
{
	priority_queue <int> pq_integers;

	cout << "Pushing {10, 5, -1, 20} into queue:" << endl;
	pq_integers.push(10);
	pq_integers.push(5);
	pq_integers.push(-1);
	pq_integers.push(20);

	cout << "Deleting the " << pq_integers.size() << " elements" << endl;

	while (!pq_integers.empty())
	{
		cout << "Deleting element: " << pq_integers.top() << endl;
		pq_integers.pop();
	}

	if (pq_integers.empty())
		cout << "The priority queue now is empty!" << endl;
}

void example7()
{
	priority_queue <int,vector<int>,greater<int>> pq_integers;

	cout << "Pushing {10, 5, -1, 20} into queue:" << endl;
	pq_integers.push(10);
	pq_integers.push(5);
	pq_integers.push(-1);
	pq_integers.push(20);

	cout << "Deleting the " << pq_integers.size() << " elements" << endl;

	while (!pq_integers.empty())
	{
		cout << "Deleting element: " << pq_integers.top() << endl;
		pq_integers.pop();
	}

	if (pq_integers.empty())
		cout << "The priority queue now is empty!" << endl;
}
