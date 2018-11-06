#include <iostream>
using namespace std;

class Fish
{
public:
	virtual void Swim()
	{
		cout << "Fish swims in water" << endl;
	}

	//base class should always have virtual destructor
	virtual ~Fish() {}
};

class Tuna :public Fish
{
public:
	void Swim()
	{
		cout << "Tuna swims real fast in the sea. " << endl;
	}

	void BecomeDinner()
	{
		cout << "Tuna became dinner in Sushi. " << endl;
	}
};

class Carp :public Fish
{
public:
	void Swim()
	{
		cout << "Carp swims real slow in the lake. " << endl;
	}

	void Talk()
	{
		cout << "Carp talked carp. " << endl;
	}
};

void DetectFishType(Fish* input_fish)
{
	Tuna* is_tuna_ptr = dynamic_cast<Tuna*>(input_fish);
	if (is_tuna_ptr)
	{
		cout << "Detect Tuna. Making Tuna dinner: " << endl;
		is_tuna_ptr->BecomeDinner();
	}

	Carp* is_carp_ptr = dynamic_cast<Carp*>(input_fish);
	if (is_carp_ptr)
	{
		cout << "Detect Carp. Making carp talk: " << endl;
		is_carp_ptr->Talk();
	}

	cout << "Verifying type using virtual Fish::Swim: " << endl;
	input_fish->Swim();
}

int main()
{
	Carp my_lunch;
	Tuna my_dinner;

	DetectFishType(&my_dinner);
	cout << endl;
	DetectFishType(&my_lunch);
}