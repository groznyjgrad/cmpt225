// Modify implementation of Scores so that at most maxEnt/2 of the scores can come from
// a single player. 

#include <iostream>
#include <string>

// We only need to modify the Scores::add method to check whether there
// would exist >= maxEnt/2 entries from the same name after adding a 
// new GameEntry object

void Scores::add(const GameEntry& e)
{ // Created a GameEntry object, and now want to add it to the Scores array
	int newScore = e.getScore();
	if (numEntries == maxEntries) { // array is full
		if (newScore <= entries[maxEntries-1].getScore()) {return;}
	}
	else { numEntries++; } // array is not full, add one to count

	// Check if there are maxEnt/2 entries from the same name
	string newName = e.getName();
	int num_of_entries = 0;
	for (int i = 0; i < numEntries; ++i)
	{
		if (entries[i].getName() == newName) { num_of_entries++; }
		if (num_of_entries >= maxEnt/2) {return;} // do not add entry
	}
	// At this point the new GameEntry should be inserted

	// rest of code here for shifting entries, etc.	No difference from
	// original.
}