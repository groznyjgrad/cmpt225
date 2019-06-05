// Testing charList implementation 

#include "charList.h"

using namespace std;

int main()
{
	CharList* my_name = new CharList("Spencer Zeng");
	cout << my_name->to_string() << endl;

	my_name->append('g');
	cout << my_name->to_string() << endl;
	
}

