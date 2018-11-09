#include<iostream>
using namespace std;

template<typename T>
class TestStatic
{
public:
	static int static_value;
};

//static member initialization
template<typename T> int TestStatic<T>::static_value;

int main()
{
	TestStatic<int> int_year;
	cout << "Settubg static_value for int_year to 2011" << endl;
	int_year.static_value = 2011;
	TestStatic<int> int_2;

	TestStatic<double> double_1;
	TestStatic<double> double_2;
	cout << "Setting static_value for double_2 to 1011" << endl;
	double_2.static_value = 1011;

	cout << "int_2.static_value = " << int_2.static_value << endl;
	cout << "double_1.static_value = " << double_1.static_value << endl;

	return 0;
}