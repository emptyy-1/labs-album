#include <iostream>
#include <cmath>

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	std::cout << "Enter a, b, c: ";
	std::cin >> a >> b >> c;

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				std::cout << "Infinite solutions (0 = 0)\n";
			}
			else
			{
				std::cout << "No solutions\n";
			}
		}
		else
		{
			double x = -c / b;
			std::cout << "Linear equation. x = " << x << '\n';
		}
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (D > 0)
		{
			double x1 = (-b - std::sqrt(D)) / (2 * a);
			double x2 = (-b + std::sqrt(D)) / (2 * a);
			std::cout << "x1 = " << x1 << ", x2 = " << x2 << '\n';
		}
		else if (D == 0)
		{
			double x = -b / (2 * a);
			std::cout << "Single root x = " << x << '\n';
		}
		else
		{
			std::cout << "No real roots\n";
		}
	}

	return 0;
}