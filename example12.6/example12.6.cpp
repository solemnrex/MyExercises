#include <iostream>
using namespace std;

class Date
{
private:
	int day_, month_, year_;

public:

	//constructor that initializes the object to a day, month and year
	Date(int input_day, int input_month, int input_year)
		:day_(input_day), month_(input_month), year_(input_year) {};

	//Binary addition assignment
	void operator += (int days_to_add)
	{
		day_ += days_to_add;
	}

	//Binary subtraction assignment
	void operator -= (int days_to_sub)
	{
		day_ -= days_to_sub;
	}

	void DisplayDate()
	{
		cout << day_ << " / " << month_ << " / " << year_ << endl;
	}
};

int main()
{
	//instantiate and initialize a date object to 25 Dec 2011
	Date holiday(25, 12, 2011);

	cout << "holiday is on: ";
	holiday.DisplayDate();

	cout << "holiday -=19 gives: "; 
	holiday -= 19;
	holiday.DisplayDate();

	cout << "holiday +=25 gives: ";
	holiday += 25;
	holiday.DisplayDate();

	return 0;
}