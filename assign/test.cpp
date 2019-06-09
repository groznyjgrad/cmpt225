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

	if (typical_string_passed == num_of_tests) {cout << "typical_string passed all tests" << endl;}
	else {cout << "typical_string failed one or more tests" << endl;}

	// Tests on one_letter
	cout << "call one_letter->Size(), expect: 1" << endl;
	cout << one_letter->Size() << endl;
	if (one_letter->Size() == 1) { one_letter_passed++; }
	else { cout << "Error" << endl;}

	cout << "call one_letter->ToString(), expect: \"s\"" << endl;
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	cout << "call one_letter->Insert('x'), expect: \"xs\"" << endl;
	one_letter->Insert('x');
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "xs") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	cout << "call one_letter->Remove('x'), expect \"s\"" << endl;
	one_letter->Remove('x');
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	cout << "call one_letter->Remove('x'), expect \"s\"" << endl;
	one_letter->Remove('x'); // should not affect string
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	cout << "call one_letter->Remove('d', 2), expect \"s\"" << endl;
	one_letter->Remove('s',2); // should not affect string
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	cout << "call one_letter->Insert('d','s'), expect: \"ds\"" << endl;
	one_letter->Insert('d','s');
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "ds") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('d');

	cout << "call one_letter->Insert('d','c'), expect: \"sd\"" << endl;
	one_letter->Insert('d','c'); // should insert EOL
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "sd") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('d');

	cout << "call one_letter->Insert('b','s', 1), expect: \"bs\"" << endl;
	one_letter->Insert('b','s',1);
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "bs") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('b');

	cout << "call one_letter->Insert('b','s', 2), expect: \"sb\"" << endl;
	one_letter->Insert('b','s',2); // should insert EOL
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "sb") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('b');

	cout << "call one_letter->Append('p'), expect: \"sp\"" << endl;
	one_letter->Append('p');
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "sp") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('p');

	cout << "call one_letter->Append('c', 'p', 2), expect: \"sc\"" << endl;
	one_letter->Append('c','p',);
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "sc") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('c');

	cout << "call one_letter->Append('c', 'p', 3), expect: \"sc\"" << endl;
	one_letter->Append('c','p',3);
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "sc") { one_letter_passed++; }
	else { cout << "Error" << endl;}
	one_letter->Remove('c');

	cout << "call one_letter->Remove('s', 2), expect \"s\"" << endl;
	one_letter->Remove('s',2);
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	cout << "call one_letter->Remove('s', 1), expect \"\"" << endl;
	one_letter->Remove('s',1);
	cout << one_letter->ToString() << endl;
	if (one_letter->ToString() == "s") { one_letter_passed++; }
	else { cout << "Error" << endl;}

	// What happens if we remove the single character in a one element list and then call ToString()?

	if (one_letter_passed == num_of_tests) {cout << "one_letter passed all tests" << endl;}
	else {cout << "one_letter failed one or more tests" << endl;}


	// Free memory
	delete typical_string;
	delete one_letter;
}
