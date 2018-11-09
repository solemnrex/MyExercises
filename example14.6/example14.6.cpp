template <typename T>
class EverythinsButInt
{
public:
	EverythinsButInt()
	{
		static_assert(sizeof(T) != sizeof(int), "No int please!");
	}
};

int main()
{
	EverythinsButInt<int> test;

	return 0;
}