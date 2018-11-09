template <typename T1 = int, typename T2 = double>
class HoldsPair
{
private:
	T1 value1_;
	T2 value2_;
public:
	//constructor
	HoldsPair(const T1& value1, const T2& value2)
		:value1_(value1), value2_(value2) {}

	//accessor functions
	const T1&  GetFirstValue() const
	{
		return value1_;
	}

	const T2&  GetSecondValue() const
	{
		return value2_;
	}
};

#include <iostream>
using namespace std;

int main()
{
	HoldsPair <> int_floate_pair(300, 10.09);
	HoldsPair<short, const char*> short_string_pair(25, "Learn templates, love C++");//no const compile will have error/waring.

	cout << "The first object contains -" << endl;
	cout << "Value1: " << int_floate_pair.GetFirstValue() << endl;
	cout << "Value2: " << int_floate_pair.GetSecondValue() << endl;

	cout << "The second object contains -" << endl;
	cout << "Value1: " << short_string_pair.GetFirstValue() << endl;
	cout << "Value2: " << short_string_pair.GetSecondValue() << endl;

	return 0;
}