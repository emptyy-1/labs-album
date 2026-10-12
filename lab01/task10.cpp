#include <iostream>

int main()
{
	int n = 0;
	std::cout << "Enter natural number: ";
	std::cin >> n;

	if (n <= 1)
	{
		std::cout << "No prime divisors\n";
		return 0;
	}

	std::cout << "Prime divisors: ";
	for (int d = 2; d <= n; d++)
	{
		if (n % d == 0)
		{
			std::cout << d << ' ';
			while (n % d == 0)
			{
				n = n / d;
			}
		}
	}
	std::cout << '\n';

	return 0;
}