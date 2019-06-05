// Testing charList implementation 

#include "charList.h"

using namespace std;

int main()
{
	CharList* my_name = new CharList("Spencer Zeng");
	cout << "Testing constructor: expect \"Spencer Zeng\"" << endl;
	cout << my_name->to_string() << endl;

	my_name->append('g');
	cout << "Testing append('g'): expect \"Spencer Zengg\"" << endl;
	cout << my_name->to_string() << endl;

	my_name->insert('S');
	cout << "Testing insert:('S') expect \"SSpencer Zengg\"" << endl;
	cout << my_name-> to_string() << endl;

	my_name->remove('e');
	cout << "Testing remove('e'): expect \"SSpncer Zengg\"" << endl;
	cout << my_name-> to_string() << endl;

	my_name->remove('g', 2);
	cout << "Testing remove('g',2): expect \"SSpncer Zeng\"" << endl;
	cout << my_name-> to_string() << endl;

	my_name->remove('g', 2);
	cout << "Testing remove('g',2): expect \"SSpncer Zeng\" (no change)" << endl;
	cout << my_name-> to_string() << endl;

	my_name->insert('e', 'n');
	cout << "Testing insert:('e','n') expect \"SSpencer Zeng\"" << endl;
	cout << my_name-> to_string() << endl;

	my_name->insert('g', 'f');
	cout << "Testing insert:('g','f') expect \"SSpencer Zengg\"" << endl;
	cout << my_name-> to_string() << endl;

	CharList* another_name = new CharList("n");
	my_name->insert('g', 'f');
	cout << "Testing insert:('g','f') expect \"ng\"" << endl;
	cout << another_name-> to_string() << endl;

	delete my_name;
	delete another_name;
}

