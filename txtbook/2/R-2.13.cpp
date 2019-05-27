// R-2.13  Perform array reference out of bounds and catch exception

#include <iostream>
#include <string>

class OutOfBounds
{
public:
	OutOfBounds(string msg) {errorMsg = msg;}
	get_errorMsg() {return errorMsg;}
private:
	string errorMsg;
};

int getElement(int arr[], int len, int i)
{
	try {
		return arr[i];
		if (i > len) {
			throw OutOfBounds("Array index out of bounds!"); 
		}
	}

	catch(OutOfBounds& oobError) {
		cout << "getElement() called with invalid index i" << endl;
		return -1;
	}
}

int main()
{
	int myArr[] = {1, 2, 3, 4};
	cout << getElement(myArr[], 3) << endl; // valid index, returns 3

	cout << getElement(myArr[], 4) << endl; // invalid index

}