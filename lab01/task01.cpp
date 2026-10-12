#include <iostream>

int main()
{
	int n = 0;
	long long factorial = 1; 

	std::cout << "Enter number: ";
	std::cin >> n;

	if (n < 0)
	{
		std::cout << "Error: negative number\n";
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		factorial = factorial * i;
	}

	std::cout << "factorial = " << factorial << '\n';

	return 0;
}