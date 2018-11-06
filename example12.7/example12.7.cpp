#include <iostream>
using namespace std;

class Date
{
private:
	int day_, month_, year_;

public:
	//constructor that initialize the object to a day, month and year
	Date(int input_day, int input_month, int input_year)
		:day_(input_day), month_(input_month), year_(input_year) {};

	bool operator == (const Date& compare_to)
	{
		return ((day_ == compare_to.day_)
			&& (month_ == compare_to.month_)
			&& (year_ == compare_to.year_));
	}

	bool operator != (const Date& compare_to)
	{
		return !(this->operator==(compare_to));
	}

	void DisplayDate()
	{
		cout << day_ << " / " << month_ << " / " << year_ << endl;
	}
};

int main()
{
	Date holiday1(25, 12, 2011);
	Date holiday2(31, 12, 2011);

	cout << "holiday1 is: ";
	holiday1.DisplayDate();
	cout << "holiday2 is: ";
	holiday2.DisplayDate();

	if (holiday1 == holiday2)
		cout << "Equality operator: The two are on the same day" << endl;
	else
		cout << "Equality operator: The two are on different day" << endl;

	if (holiday1 != holiday2)
		cout << "Inequality operator: The two are on different day" << endl;
	else
		cout << "Inequality operator: The two are on the same day" << endl;

	return 0;
}