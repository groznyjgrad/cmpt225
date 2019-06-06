// Testing charList implementation 

#include "charList.h"

using namespace std;

int main()
{
	CharList* typical_string = new CharList("Spencer Zeng");
	CharList* one_letter = new CharList("S");
	CharList* five_letters = new CharList("zzzzz");

	delete typical_string;
	delete one_letter;
	delete five_letters;
}
