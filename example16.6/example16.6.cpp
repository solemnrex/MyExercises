#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;
	string str("Hello string! We will reverse you!");
	cout << "The original sample string is: " << endl;
	cout << str << endl << endl;

	reverse(str.begin(), str.end());
	
	cout << "After applying the std::reverse algorithm: " << endl;
	cout << str << endl;

	return 0;
}