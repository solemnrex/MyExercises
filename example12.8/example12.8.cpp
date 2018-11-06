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

	bool operator < (const Date& compare_to)
	{
		if (year_ < compare_to.year_)
			return true;
		else if (month_ < compare_to.month_)
			return true;
		else if (day_ < compare_to.day_)
			return true;
		else
			return false;
	}

	bool operator <= (const Date& compare_to)
	{
		if (this->operator==(compare_to))
			return true;
		else
			return this->operator<(compare_to);
	}

	bool operator > (const Date& compare_to)
	{
		return !(this->operator<=(compare_to));
	}

	bool operator >= (const Date& compare_to)
	{
		return !(this->operator<(compare_to));
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

	if (holiday1 < holiday2)
		cout << "operator<: holiday1 happen first." << endl;
	
	if (holiday2 > holiday1)
		cout << "operator>: holiday2 happen later." << endl;

	if (holiday1 <= holiday2)
		cout << "operator<=: holiday1 happens on or before holiday2." << endl;

	if (holiday2 >= holiday1)
		cout << "operator>=: holiday2 happens on or later holiday1." << endl;

	return 0;
}