#include <iostream>
#include <fstream>
using namespace std;

// Here I've left the code as I found it, to show you
// a contrasting (and in my opinion, nowhere near as clear)
// style.  Many C++ coders have this style.


// Find the mode of an array.
//
// Parameters:
//  arr is an integer array with n elements
// Return value:
//  return the mode
//

long getMode (long* set_of_ints, int num_elements) {
	// Find maximum value of the input array.
	int max_value = 0;
	for (int i = 0; i < num_elements; ++i) {
		if (set_of_ints[i] > max_value) max_value = set_of_ints[i];
	}

	// Use an array to count the frequency of each integer number.
	int countFrequency[max_value];
	for (int i = 0; i < num_elements; ++i) {
		int num = set_of_ints[i];
		++countFrequency[num];
	}

	long mode = 0;
	for (int i = 0; i < num_elements; ++i) {
		if (countFrequency[i] > mode) mode = countFrequency[i];
	}
  return mode;
}

// Input is the number of elements, followed by that many integers.
// Writes mode of elements to file specified as first command-line argument.
int main (int argc,  char* argv[]) {

	// ofstream for writing result.
	ofstream outputfile;

	// Parse command-line arguments.
	if (argc != 2) {
		// Note that the program name is the first argument, so argc==1 if there are no additional arguments.
		cerr << "Expected one argument." << endl;
		cerr << "  Usage: " << argv[0] << " output_filename" << endl;
		return 1;
	} else {
		// Open the filename specified for input.
		outputfile.open (argv[1]);
	}


	// Read a set of elements into an array.
	int num_elements;
	long* set_of_ints;

	// Get the number of elements
	cout << "Enter the number of elements:" << endl;
	cin >> num_elements;

	// Create array in dynamic memory.
	set_of_ints = new long[num_elements];

	for (int i=0; i<num_elements; i++) {
		cout << "Enter a number:" << endl;
		cin >> set_of_ints[i];
	}

	long mode = getMode(set_of_ints, num_elements);

	cout << "The mode is " << mode << endl;

	outputfile << mode << endl;
	outputfile.close();

	// Free up memory.  Note use of delete [], since this is an array.
	delete [] set_of_ints;

	return 0;
}
