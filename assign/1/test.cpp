// Testing charList implementation 

#include "charList.h"

int main() {
	CharList* typical_string = new CharList("abcd"); // change this to simpler string
	CharList* one_letter = new CharList("s");

	int typical_string_passed = 0;
	int one_letter_passed = 0;
	int num_of_tests = 16;

	// Tests on typical_string
	typical_string->Size();
	if (typical_string->Size() == 4) { typical_string_passed++; }
	else { cout << "Error" << endl;}

	if (typical_string->ToString() == "abcd") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Insert('x');
	if (typical_string->ToString() == "xabcd") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Remove('x');
	if (typical_string->ToString() == "abcd") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Remove('x'); // should not affect string
	if (typical_string->ToString() == "abcd") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Insert('d','c');
	if (typical_string->ToString() == "abdcd") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Remove('d',2);
	if (typical_string->ToString() == "abdc") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Insert('a','f'); // should insert EOL
	if (typical_string->ToString() == "abdca") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Insert('b','a',2);
	if (typical_string->ToString() == "abdcba") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Insert('d','a',3); // should insert EOL
	if (typical_string->ToString() == "abdcbad") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Append('p');
	if (typical_string->ToString() == "abdcbadp") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Append('p','d');
	if (typical_string->ToString() == "abdpcbadp") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Append('z','f');
	if (typical_string->ToString() == "abdpcbadpz") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Append('c','p',2);
	if (typical_string->ToString() == "abdpcbadpcz") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Append('c','p',3);
	if (typical_string->ToString() == "abdpcbadpczc") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	typical_string->Remove('d',2);
	if (typical_string->ToString() == "abdpcbapczc") { typical_string_passed++; }
	else { cout << "Error" << endl;}

	// Tests on one_letter
	if (one_letter->Size() == 1) { one_letter_passed++; }
	else { cout << "Error" << endl;}
;
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	one_letter->Insert('x');
	if (one_letter->ToString() == "xs") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	one_letter->Remove('x');
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	one_letter->Remove('x'); // should not affect string
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	one_letter->Remove('s',2); // should not affect string
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	one_letter->Insert('d','s');
	if (one_letter->ToString() == "ds") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('d');

	one_letter->Insert('d','c'); // should insert EOL
	if (one_letter->ToString() == "sd") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('d');

	one_letter->Insert('b','s',1);
	if (one_letter->ToString() == "bs") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('b');

	one_letter->Insert('b','s',2); // should insert EOL
	if (one_letter->ToString() == "sb") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('b');

	one_letter->Append('p');
	if (one_letter->ToString() == "sp") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('p');

	one_letter->Append('c','p');
	if (one_letter->ToString() == "sc") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('c');

	one_letter->Append('c','p',3);
	if (one_letter->ToString() == "sc") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('c');

	one_letter->Remove('s',2);
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	one_letter->Remove('s',1);
	if (one_letter->ToString() == "(list is empty)") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	one_letter->Insert('s');
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	// Test results

	if (typical_string_passed + one_letter_passed == num_of_tests*2) {
		cout << "passed" << endl;
	}
	else {cout << "failed" << endl;}

	// Free memory
	delete typical_string;
	delete one_letter;
}
