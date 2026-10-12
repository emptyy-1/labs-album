#include <iostream>

int main()
{
	int n = 0;
	std::cout << "Enter number: ";
	std::cin >> n;

	if (n < 0)
	{
		n = -n;
	}

	int count = 0;
	for (int d = 0; d <= 9; d++)
	{
		int temp = n;
		bool found = false;

		if (temp == 0 && d == 0)
		{
			found = true;
		}

		while (temp > 0)
		{
			if (temp % 10 == d)
			{
				found = true;
				break;
			}
			temp = temp / 10;
		}

		if (found)
		{
			count++;
		}
	}

	std::cout << "Distinct digits = " << count << '\n';

	return 0;
}
