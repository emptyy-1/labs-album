#include <iostream>

int main()
{
	int a = 0;
	int b = 0;
	std::cout << "Enter two natural numbers: ";
	std::cin >> a >> b;

	if (a <= 0 || b <= 0)
	{
		std::cout << "Error: numbers must be positive\n";
		return 0;
	}

	int x = a;
	int y = b;
	while (y != 0)
	{
		int temp = y;
		y = x % y;
		x = temp;
	}

	int NOD = x;
	long long NOK = ((long long)a * b) / NOD;

	std::cout << "NOD = " << NOD << '\n';
	std::cout << "NOK = " << NOK << '\n';

	return 0;
}
