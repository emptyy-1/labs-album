#include <iostream>

int main()
{
	int n = 0;
	std::cout << "Enter natural number: ";
	std::cin >> n;

	if (n <= 1)
	{
		std::cout << "Not prime\n";
		return 0;
	}

	bool is_prime = true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			is_prime = false;
			break;
		}
	}

	if (is_prime)
	{
		std::cout << "Prime\n";
	}
	else
	{
		std::cout << "Not prime\n";
	}

	return 0;
}