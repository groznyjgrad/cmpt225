// Given a n by n matrix M of type float, replace M with its tranpose without
// using a temporary matrix

#include <iostream>
using namespace std;

void TransposeMatrix(float M[][3]) {
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			// swap M[i][j] with M[j][i]
			float temp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = temp;
			cout << "M" << i << "-" << j << " is " << M[i][j] << endl;
			// You are swapping the entries again, resetting to the original!
		}
	}
}

int main()
{
	float M[3][3];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			M[i][j] = 0;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		M[1][i] = 1;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << "Original: M" << i << "-" << j << " is " << M[i][j] << endl;
		}
	}

	TransposeMatrix(M);
	cout << endl;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << "Transpose: M" << i << "-" << j << " is " << M[i][j] << endl;
		}
	}
}

