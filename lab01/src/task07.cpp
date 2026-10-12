#include <iostream>
#include <cmath>

int main()
{
	double x = 0;
	double n = 0;
	std::cout << "Enter x and n: ";
	std::cin >> x >> n;

	if (x == 0 && n == 0)
	{
		std::cout << "Error: 0^0 is undefined\n";
	}
	else if (x == 0 && n < 0)
	{
		std::cout << "Error: division by zero\n";
	}
	else if (x < 0 && (long long)n != n)
	{
		std::cout << "Error: negative base with non-integer exponent\n";
	}
	else
	{
		double result = std::pow(x, n);
		std::cout << "Result = " << result << '\n';
	}

	return 0;
}
