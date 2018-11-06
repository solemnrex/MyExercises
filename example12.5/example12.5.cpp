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

	//Binary addition operator
	Date operator + (int days_to_add)
	{
		Date new_date(day_ + days_to_add, month_, year_);
		return new_date;
	}

	//Binary subtraction operator
	Date operator - (int days_to_sub)
	{
		return Date(day_ - days_to_sub, month_, year_);
	}

	void DisplayDate()
	{
		cout << day_ << " / " << month_ << " / " << year_ << endl;
	}
};

int main()
{
	//Instantiate and initialize a date object to 25 Dec 2011
	Date holiday(25, 12, 2011);

	cout << "holiday on: ";
	holiday.DisplayDate();

	Date previous_holiday(holiday - 19);
	cout << "previous_holiday on: ";
	previous_holiday.DisplayDate();

	Date next_holiday(holiday + 6);
	cout << "next_holiday on: ";
	next_holiday.DisplayDate();

	return 0;
}