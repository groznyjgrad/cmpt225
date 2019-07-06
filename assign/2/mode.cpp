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

// Strategy: consider each element of the array as a candidate mode. After selecting a candidate
// mode from the array, count its frequency in the array. Then if its frequency is greater than the 
// frequency of the current mode, replace the current mode with the value of the candidate mode.
// Therefore, once each element has been considered, the element with the greatest frequency will
// have been stored and can then be returned as the true mode of the array. 
long mode (long* arr, int n) {
	// integer value and frequency of the current mode
	long current_mode = 0;
	int current_mode_count = 0;
	// integer value and frequency of the candidate mode
	long candidate_mode = 0;
	int candidate_count = 0;

	for (int i = 0; i < n; ++i) {  // select a candidate mode
		candidate_mode = arr[i];
		candidate_count = 0;         // reset count for each candidate mode 
		for (int j = 0; j < n; ++j) {   // count the frequency of the candidate mode
			if (arr[j] == candidate_mode) ++candidate_count;
		}
		if (candidate_count > current_mode_count) {   // replace current mode 
			current_mode = candidate_mode;
			current_mode_count = candidate_count;
		}
	}
	return current_mode;
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
	int n;
	long* arr;

	// Get the number of elements
	cout << "Enter the number of elements:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	arr = new long[n];

	for (int i=0; i<n; i++) {
		cout << "Enter a number:" << endl;
		cin >> arr[i];
	}

	long m = mode(arr, n);

	cout << "The mode is " << m << endl;

	outputfile << m << endl;
	outputfile.close();

	// Free up memory.  Note use of delete [], since this is an array.
	delete [] arr;

	return 0;
}
