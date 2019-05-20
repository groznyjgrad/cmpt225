// Output all permutations over the alphabet {a, b, c, d, e, f} 

#include <iostream>
using namespace std;

void swap(char* pos1, char* pos2) // better to take in pointers to the elements being swapped
{
	char tmp = *pos2;
	*pos2 = *pos1;
	*pos1 = tmp;
}

void permute(char alpha[], int firstIndex, int lastIndex)
{
	if (firstIndex == lastIndex) // corresponds to being at the last character of the string
	{
		cout << alpha << endl; // we have a full-length permutation now, so print it
	}
	else
	{
		for (int i = firstIndex; i <= lastIndex; ++i)
		{
			swap(alpha+firstIndex, alpha+i);
			permute(alpha, firstIndex+1, lastIndex);
			swap(alpha+firstIndex, alpha+i);
		}
	}
}

int main()
{
	char alpha[] = {'a','b','c'};
	permute(alpha, 0, 2);
}

/*
Strategy:

Consider a string which has the given alphabet in order:

	abcdef

Swap the first character in the alphabet with every character (including itself). This constructs all possible 
permutations of the first character in a string. For the given alphabet, this looks like:

	abcdef (a-a swap) String 1
	bacdef (a-b swap) 		 2
	cbadef (a-c swap)		 3
	dbcaef (a-d swap)		 4
	ebcdaf (a-e swap)		 5
	fbcdea (a-f swap)		 6

There are 6 resulting strings since the first character can be swapped with each of the six characters.

Then for each of these strings, repeat the above process by swapping the second character with every
other character (including itself). For string 1 above, this yields:

	abcdef (b-b swap) String 1-1
	acbdef (b-c swap)		 1-2
	adcbef (b-d swap)		 1-3
	aecdbf (b-e swap)		 1-4
	afcdeb (b-f swap)		 1-5
	
There are 5 resulting strings since the second character can be swapped with each of the five remaining
characters (the first character is fixed).
Since there are 6 strings from the first iteration, there are a total of 6*5=30 strings from the second
iteration. This corresponds to the fact that there are 30 permutations of length 2 over a 6-letter alphabet.

We can repeat this process for the third, fourth, and fifth characters. The last character need not be 
swapped since all other positions will be fixed. This will generate all 6! permutations.

Implementation:

*/