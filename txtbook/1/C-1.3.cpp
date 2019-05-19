// Take STL vector of ints and determine if all numbers distinct

#include <iostream>
#include <vector>

void distinctVector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = i+1; j < v.size(); ++j)
		{
			if (v[i] == v[j])
			{
				std::cout << "vector has nondistinct entries\n";
				return;
			}
		}
	}
	std::cout << "vector has all distinct entries\n";
}

int main()
{
	std::vector<int> myInts;
	for (int i = 0; i < 10; ++i)
	{
		myInts.push_back(i);
	}

	distinctVector(myInts); // should be all distinct

	myInts.push_back(5);
	distinctVector(myInts); // now not distinct
}