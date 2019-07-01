#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Note: the names in this code use a number of standard prefixes, which you should know.  I've thrown
// in a few others in this list. They can be used with CamelCase or underscore_separated naming conventions.
//
//		min		minimum
//		max		maximum
//		avg		average
//		std		standard
//		temp	temporary (try not to use "temp" by itself as a variable name.  Say what the temporary holds.)
//		num		number of (when used as a prefix only.  Used as a suffix, it indicates an index or ID number.
//					       for example, numFiles is the number of files you have.  fileNum is the ID number
//						   of one particular file.)
//
//	Some people, notably people who learned to use C-style in C++, also use "in" as a prefix for "input", 
//  and "out" as a prefix for "output".  My preference is to not use these prefixes.
//
//  In general, except in the case of the standard prefixes, I advocate writing words out fully.  Don't use
//  "rng" for "range", for instance.  As another example, it would be disastrous to abbreviate "comparisons"
//  in the following main() function as "comp".  When the brain sees "comp" it has to sort out what that
//  means--it could be "computer" or "comprehensive" or "complete" or "computation", etc.--so writing it
//  out is essential.  Most of the comments in the code are meant to help out students and could be eliminated
//  in professional code.
//
//  Note that the correct specification of what a function may throw requires parentheses around the type, as
//  with writeArray() below.

class FileOpeningException {
private:
	string errorMessage;
public:
	FileOpeningException(string message) { errorMessage = message; }
	string getMessage() { return errorMessage; }
};

string* readWords(string filename, int & arraySize);
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException);

// Writes the array arr in text format to a file named filename.
// each element of the array has its own line in the file, 
// which contains the element's index and value, separated by a space.
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException) {
	ofstream outputStream(filename.c_str());

	if (outputStream.fail()) {
		throw new FileOpeningException("Error opening " + filename);
	}

	for (int i = 0; i<arraySize; i++) {
		outputStream << i << " " << arr[i] << endl;
	}
	outputStream.close();
}

int numLinesInStream(ifstream& stream) {
	int numLines = 0;
	string tempLine;

	// getline returns 0 at end of file.
	while (getline(stream, tempLine)) {
		numLines++;
	}
	return numLines;
}

// note how the following function is all about one thing:
// the handling of the ifstream called inputStream().
// the exact computation done using inputStream() is abstracted
// to a single call (to numLinesInStream).
// Here, I don't declare the thrown object with a "throw ()" on the
// first line.  It's optional, so I'm leaving it off this time.
int numLinesInFile(string filename) {
	ifstream inputStream(filename.c_str());

	if (inputStream.fail()) {
		throw new FileOpeningException(filename + "... file not found ...");
	}

	int numLines = numLinesInStream(inputStream);

	inputStream.close();
	return numLines;
}

// Reads lines from a file named filename.
// Returns an array of strings, one per line of the file filename, 
// and places the size of the array in the reference parameter (output parameter) arraySize
string* readWords(string filename, int & arraySize) {
	string* result = NULL;
	arraySize = numLinesInFile(filename);
	ifstream inputStream(filename.c_str());

	// Read file contents into result, now that size is known
	result = new string[arraySize];			//create results array
	for (int i=0; i < arraySize; i++){
		getline(inputStream, result[i]);
	}
	inputStream.close(); //don't forget to close file

    return result;
}

// Returns true if the string s is in alphabetical order based on ASCII values and false otherwise.
// Places the number of comparisons made during the call in the reference parameter numComparisons.
bool isInAlphabeticalOrder(string s, int& numComparisons) {
	int length = s.length();
	for (int i = 0; i < length-1; ++i) {
		++numComparisons;
		if (s[i] > s[i+1]) return false;
	}
	return true;
}

// Returns the average number of words present in the input array of strings.
float avgWordLength(string* words, int numWords) {
	int totalNumChars = 0;
	for (int i = 0; i < numWords; ++i) {
		totalNumChars += words[i].length();
	}
	return float(totalNumChars) / float(numWords);
}

// Returns the average number of comparisons made by isInAlphabeticalOrder().
float avgCharComparisons(string* words, int numWords) {
	int numComparisons = 0;
	int numFunctionCalls = 0;
	for (int i = 0; i < numWords; ++i) {
		isInAlphabeticalOrder(words[i], numComparisons);
		++numFunctionCalls;
	}
	return float(numComparisons) / float(numFunctionCalls);
}

// Returns the maximum length among the words contained in the input array of strings
int maxWordLength(string* words, int numWords) {
	int maxLength = 0;
	for (int i = 0; i < numWords; ++i) {
		if (words[i].length() > maxLength) maxLength = words[i].length();
	}
	return maxLength;
}

// Returns an array avgComparisonsForLength containing the average number of comparisons made 
// by isInAlphabeticalOrder() with respect to the length of the word string. 
float* avgComparisonsForLength(string* words, int numWords) {
	int maxLength = maxWordLength(words, numWords);
	int numCallsForLength[maxLength+1] = {0};  // Count number of calls to isInAlphabeticalOrder()by word length.
											   // Use maxLength+1 so that the array index matches the word length.
	int totalComparisonsForLength[maxLength+1] = {0}; // Count number of comparisons made by isInAlphabeticalOrder() by word length.

	for (int i = 0; i < numWords; ++i) {
		int word_length = words[i].length();
		++numCallsForLength[word_length]; 
		int numComparisonsForWord = 0; 
		isInAlphabeticalOrder(words[i], numComparisonsForWord);
		totalComparisonsForLength[word_length] += numComparisonsForWord;
	}

	float* avgComparisonsForLength = new float[maxLength+1]; 
	avgComparisonsForLength[0] = 0; // Word of length 0 always takes zero comparisons
	for (int i = 1; i < maxLength; ++i) {
		avgComparisonsForLength[i] = float(totalComparisonsForLength[i]) / float(numCallsForLength[i]);
		// Example: called isInAlphabeticalOrder() three times on words of length 5, so numCallsForLength[5] = 3.
		// isInAlphabeticalOrder() made 1, 1, and 2 comparisons for each word respectively, so since 1+1+2 = 4,
		// totalComparisonsForLength[5] = 4. Then avgComparisonsForLength[5] = 4/3 = 1.3333...
	}
	return avgComparisonsForLength;
}

int main (void) {
	int numWords;
	string wordListFilename = "./wordlist";
	string outputFilename = "average_comps.txt";

	// This reads the words from wordListFilename.
	// numWords will be the number of words in the array words
	// words[i] will be the ith word
	string *words = readWords(wordListFilename, numWords);

	// TO DO:: You should compute these values.
	float avg_word_length = avgWordLength(words, numWords);
	float avg_num_comparisons = avgCharComparisons(words, numWords);
	int max_word_length = maxWordLength(words, numWords);  
	float* avg_comparisons_for_length = avgComparisonsForLength(words, numWords);
	// avgComparisonsForLength[i] is the average number of comparisons for a word of length i.


	// TO DO:: Insert your code here.
	cout << "Avg word length is: " << avg_word_length << endl;
	cout << "Avg num of comparisons made by isInAlphabeticalOrder(): " << avg_num_comparisons << endl;
	cout << endl;
	for (int i = 0; i < max_word_length; ++i) {
		cout << "Avg comparisons for length " << i << " is: " << avg_comparisons_for_length[i] << endl;
	}

	// Print average number of comparisons for each length to a file for plotting.
	writeArray(outputFilename, avg_comparisons_for_length, max_word_length);
	
	// Clean up memory and return.
	delete[] words;
	delete[] avg_comparisons_for_length;
	return 0;
}

// Notes:
// - Casted some variables to floats but did not change the return type of the function from int to float, so
// the returned value remained as an int.
