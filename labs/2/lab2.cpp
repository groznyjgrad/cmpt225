#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int* readArray(int& size) // need to return array and its size
{
	string input;
	getline(cin, input);
	istringstream ss(input);

	ss >> size; 

	int* inpArr = new int[size];

	int i = 0;
	while (i <= size)
	{
		ss >> inpArr[i]; // stream buffer will move forward as it reads
		i++;
	}

	return inpArr;
}

void printArray(int arr[], int size)
{
	if (size == 0)
	{
		cout << "[]" << endl;
		return;
	}
	if (size == 1)
	{
		cout << "[" << arr[0] << "]" << endl;
		return;
	}

	cout << "[";
	for (int i = 0; i < size-1; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[size-1] << "]" << endl;
}

void sortArray(int arr[], int size) // strategy: insertion sort
// LARGEST to SMALLEST
{ 
	int i, cur, j;

	for (i = 1; i < size; ++i) // sort all the elements
	{ 
		cur = arr[i]; // select element to place in correct position
		j = i-1; 

		while (j >= 0 && arr[j] < cur) // not in order if arr[j] < cur
		{
			arr[j+1] = arr[j]; // shift j right to j+1
			j--; // decrement j to move and assess left element
		}
		arr[j+1] = cur; // loops fails when position has been found
	}
}

int main()
{
	int size = 0;
	int* myArr = readArray(size);

	printArray(myArr, size);
	sortArray(myArr, size);
	// now sorted
	cout << "sorted: ";
	printArray(myArr, size);

	delete[] myArr;
}