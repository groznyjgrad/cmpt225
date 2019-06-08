// Testing charList implementation 

#include "charList.h"

int main() {
	CharList* typical_string = new CharList("Spencer Zeng"); // change this to simpler string
	CharList* one_letter = new CharList("S");

	int typical_string_passed = 0;
	int one_letter_passed = 0;
	int num_of_tests = 13;

	// Tests on typical_string
	cout << "call typical_string->Size(), expect: 12" << endl;
	cout << typical_string->Size() << endl;
	if (typical_string->Size() == 12) { typical_string_passed++; }

	cout << "call typical_string->ToString(), expect: \"Spencer Zeng\"" << endl;
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer Zeng") { typical_string_passed++; }

	cout << "call typical_string->Insert('x'), expect: \"xSpencer Zeng\"" << endl;
	typical_string->Insert('x');
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "xSpencer Zeng") { typical_string_passed++; }

	cout << "call typical_string->Remove('x'), expect \"Spencer Zeng\"" << endl;
	typical_string->Remove('x');
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer Zeng") { typical_string_passed++; }

	cout << "call typical_string->Insert('x','Z'), expect: \"Spencer xZeng\"" << endl;
	typical_string->Insert('x','Z');
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer xZeng") { typical_string_passed++; }

	cout << "call typical_string->Remove('e', 3), expect \"Spencer xZng\"" << endl;
	typical_string->Remove('e',3);
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer xZng") { typical_string_passed++; }

	cout << "call typical_string->Insert('x','f'), expect: \"Spencer xZngx\"" << endl;
	typical_string->Insert('x','f');
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer xZngx") { typical_string_passed++; }

	cout << "call typical_string->Insert('x','n', 2), expect: \"Spencer xZxngx\"" << endl;
	typical_string->Insert('x','n',2);
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer xZxngx") { typical_string_passed++; }

	cout << "call typical_string->Insert('x','n', 3), expect: \"Spencer xZxngxx\"" << endl;
	typical_string->Insert('x','n',3);
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer xZxngxx") { typical_string_passed++; }

	cout << "call typical_string->Append('p'), expect: \"Spencer xZxngxp\"" << endl;
	typical_string->Append('p');
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Spencer xZxngxxp") { typical_string_passed++; }

	cout << "call typical_string->Append('p', 'S'), expect: \"Sppencer xZxngxp\"" << endl;
	typical_string->Append('p','S');
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Sppencer xZxngxxp") { typical_string_passed++; }

	cout << "call typical_string->Append('p', 'f'), expect: \"Sppencer xZxngxp\"" << endl;
	typical_string->Append('p','f');
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Sppencer xZxngxxp") { typical_string_passed++; }

	cout << "call typical_string->Append('p', 'e', 2), expect: \"Sppencer xZxngxxp\"" << endl;
	typical_string->Append('p','e',2);
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Sppencepr xZxngxxp") { typical_string_passed++; }

	cout << "call typical_string->Append('p', 'e', 3), expect: \"Sppencer xZxngxxp\"" << endl;
	typical_string->Append('p','e',3);
	cout << typical_string->ToString() << endl;
	if (typical_string->ToString() == "Sppencepr xZxngxxp") { typical_string_passed++; }

	if (typical_string_passed == num_of_tests) {cout << "typical_string passed" << endl;}
	else {cout << "typical_string failed one or more tests" << endl;}

	// Tests on one_letter


	// Free memory
	delete typical_string;
	delete one_letter;
}
