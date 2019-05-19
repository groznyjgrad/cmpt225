// Section 1 Problems

// R-1.3

struct Pair {
	int first;
	double second;
};

// R-1.6

double* dblPtrs[10];
double dblArr[10];

for (int i = 0; i < 10; ++i) {
	dblArr[i] = 0.0;
}

// R-1.7

int sumSmaller(int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += i;
	}
	return sum;
}

// R-1.8
bool isMultiple(long n, long m) {
	if ( (n%m) == 0 ){
		return true; // modular divison yields 0 only when n is a multiple of m
	}
	return false;
}

// R-1.9

void printArray(int** A, int m, int n) {
	for (int i = 0; i < m; ++i) // have m rows
	{
		cout << "[ ";
		for (int j = 0; j < n; ++j) // have n columns in each row
		{
			cout << A[i][j] << " ";
		}
		cout << "]\n";
	}
}
/* Note that creating a 2d array such as Matrix[2][2] is equivalent to creating a single
1d array of length 2*2 = 4, or Matrix[4] in terms of memory. The difference is that a 2d 
array can be represented in more ways. For example, a 2x2 matrix can be represented by an array 
of two pointers, each of which point to the first element in each row of the matrix.


int main()
{
	int** aMatrix;
	aMatrix = new int* [2];
	for (int i = 0; i < 2; ++i)
	{
		aMatrix[i] = new int[2];
	}

	aMatrix[0][0] = 1;
	aMatrix[0][1] = 2;
	aMatrix[1][0] = 3;
	aMatrix[1][1] = 4;

	printArray(aMatrix, 2, 2);
	delete[] aMatrix;
}*/

// R-1.11

class Flower {
public: 
	Flower(){
		flowerName = "NONE";
		numPetals = 0;
		flowerPrice = 0;
	}

	// don't need destructor because we are not allocating memory with 'new'

	void set_flowerName(string name) {flowerName = name;}
	void set_numPetals(int n) {numPetals = n;}
	void set_flowerPrice(float price) {flowerPrice = price;}

	string get_flowerName() {return flowerName;}
	int get_numPetals() {return numPetals;}
	float get_flowerPrice() {return flowerPrice;}

private:
	string flowerName;
	int numPetals;
	float flowerPrice;
};

/*
int main()
{
	Flower myFlower;
	myFlower.set_flowerName("Rose");
	myFlower.set_numPetals(4);
	myFlower.set_flowerPrice(11.99);

	cout << myFlower.get_flowerName() << "\n";
	cout << myFlower.get_numPetals() << "\n";
	cout << myFlower.get_flowerPrice() << "\n";

}*/