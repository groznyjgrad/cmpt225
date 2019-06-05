#include <iostream>
#include <string>
using namespace std;

class CharList;

class CharDLL {
friend class CharList;						// give private access to CharList
public:
	CharDLL();								// initializes a node without data
	~CharDLL();								// destructor, frees all associated memory
	
private:	
	char c_;								// character data held by node
	CharDLL* prev_;							// pointer to previous node
	CharDLL* next_;							// pointer to following node
};


class CharList {
public:		
	CharList(string s);						// constructor, initializes a list with contents of 's'
	~CharList();							// destructor, frees all associated memory

	bool empty() const;						// is list empty?
	int size() const;						// return number of elements in list
	string to_string();						// return characters in list as a string

	void insert(char c);					// inserts 'c' at the front of the list
	void insert(char c, char d);			// inserts 'c' before first occurrence of 'd', 
											// or EOL if 'd' does not occur
	void insert(char c, char d, int n);     // inserts 'c' before the n-th occurrence of 'd',
											// or EOL if 'd' does not occur exactly n times

	void append(char c);					// inserts 'c' at the back of the list
	void append(char c, char d);			// inserts 'c' after the first occurrence of 'd'
											// or EOL if 'd' does not occur
	void append(char c, char d, int n);		// inserts 'c' after the n-th occurrence of 'd',
											// or EOL if 'd' does not occur exactly n times

	void remove(char c);					// deletes the first occurrence of 'c',
											// or nothing if 'c' does not occur
	void remove(char c, int n);				// deletes the n-th occurrence of 'c',
											// or nothing if 'c' does not occur exactly n times
private:
	CharDLL* head_;							// pointer to header node (sentinel)
	CharDLL* tail_;							// pointer to trailer node (sentinel)
};
