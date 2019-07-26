#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Test.h"
#include "Unique.h"
using namespace std;

void Test::test(int n, int max) {
		int* arr = new int[n];
		for (int i = 0; i < n; ++i) {
			int number = rand() % max;
			arr[i] = number;
		}
		bool isUnique = Unique::unique(arr, n);
		cout << "[";
		for (int i = 0; i < n-1; ++i) cout << arr[i] << ", ";
		cout << arr[n-1] << "]" << endl;
		cout << "Array unique is: " << (isUnique ? "true" : "false") << endl;
	}

int main() {
	srand(time(NULL));
	Test::test(5, 10);
	Test::test(20, 100);
	Test::test(50, 200);
}