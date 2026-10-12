#include <iostream>

int main()
{
	int L = 0;
	int N = 0;
	std::cout << "Enter L and N: ";
	std::cin >> L >> N;

	if (L <= 0 || N <= 0)
	{
		std::cout << "Error: L and N must be positive\n";
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < L + i; j++)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}

	return 0;
}
