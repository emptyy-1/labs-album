#include <iostream>

int main()
{
	int n = 0;
	std::cout << "Enter (integer): ";
	std::cin >> n;

	if (n < 0)
	{
		n = -n;
	}

	int sum = 0;
	while (n > 0)
	{
		sum = sum + (n % 10);
		n = n / 10;
	}

	std::cout << "Sum = " << sum << '\n';

	return 0;
}
