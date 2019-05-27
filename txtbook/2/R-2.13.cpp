// R-2.13  Perform array reference out of bounds and catch exception

#include <iostream>
#include <string>
using namespace std;

class OutOfBounds
{
public:
	OutOfBounds(string msg) {errorMsg = msg;}
	string get_errorMsg() {return errorMsg;}
private:
	string errorMsg;
};

int getElement(int arr[], int len, int i)
{
	try {
		if (i > len) {
			throw OutOfBounds("Array index out of bounds!"); 
		}
		return arr[i];
	}

	catch(OutOfBounds& oobError) {
		cout << "getElement() called with invalid index i" << endl;
		return -1;
	}
}

int main()
{
	int myArr[] = {1, 2, 3, 4};
	cout << getElement(myArr, 3, 3) << endl; // valid index, returns 3

	cout << getElement(myArr, 3, 4) << endl; // invalid index
}

/*
Trying to use try-catch blocks. Program is a bit silly since you have to 
input the array length already, so its clear when you are using an invalid
index.


*/