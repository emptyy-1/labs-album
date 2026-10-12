#include <iostream>

int main()
{
	int n = 0;
	std::cout << "Enter number: ";
	std::cin >> n;

	int original = n;
	if (original < 0)
	{
		original = -original;
	}

	int temp = original;
	long long reversed = 0;
	while (temp > 0)
	{
		reversed = reversed * 10 + (temp % 10);
		temp = temp / 10;
	}

	if (reversed == original)
	{
		std::cout << "Palindrome\n";
	}
	else
	{
		std::cout << "Not palindrome\n";
	}

	return 0;
}
