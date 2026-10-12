#include <iostream>

int main()
{
	int k = 0;
	std::cout << "Enter count: ";
	std::cin >> k;

	if (k <= 0)
	{
		std::cout << "Error: count must be positive\n";
		return 0;
	}

	long long a = 0;
	long long b = 1;

	std::cout << "Fibonacci: ";
	for (int i = 0; i < k; i++)
	{
		std::cout << a << ' ';
		long long next = a + b;
		a = b;
		b = next;
	}
	std::cout << '\n';

	return 0;
}
