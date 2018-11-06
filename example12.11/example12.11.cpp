#include <iostream>
#include <string>
using namespace std;

class CDisplay
{
public:
	void operator () (string input) const
	{
		cout << input << endl;
	}
};

int main()
{
	CDisplay m_display_func_object;

	//equivalent to m_display_func_object.operator () ("Display this string!");
	m_display_func_object("Display this string!");

	return 0;
}