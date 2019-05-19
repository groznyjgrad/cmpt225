// Function that prints all odd values in a vector of ints

#include <iostream>
#include <vector>

void printOdd(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i]%2 != 0)
		{
			std::cout << v[i] << " ";
		}
	}
	std::cout << "\n";
}

int main()
{
	std::vector<int> myInts;
	for (int i = 0; i < 10; ++i)
	{
		myInts.push_back(i);
	}

	printOdd(myInts);
}