#include <iostream>
#include <string>
using namespace std;

#define ARRAY_LENGTH 25
#define PI 3.1416
#define MY_DOUBLE double
#define FAV_WHISKY "Jack Daniels"

int main()
{
	int my_numbers[ARRAY_LENGTH] = { 0 };
	cout << "Array's length: " << sizeof(my_numbers) / sizeof(my_numbers[0]) << endl;

	cout << "Enter a radius: ";
	MY_DOUBLE Radius = 0;
	cin >> Radius;
	cout << "Area is: " << PI * Radius*Radius << endl;

	string favorite_whisky(FAV_WHISKY);
	cout << "My favorite drink is: " << FAV_WHISKY << endl;

	return 0;
}