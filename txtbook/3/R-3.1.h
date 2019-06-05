class GameEntry {				// a game score entry
 public:
	GameEntry(const string& n="", int s=0);	// constructor
	string getName() const;			// get player name
	int getScore() const;			// get score
 private:
	string name;				// player's name
	int score;					// player's score
};

class Scores {				// stores game high scores
 public:
	Scores(int maxEnt = 10);			// constructor
	~Scores();					// destructor
	void add(const GameEntry& e);		// add a game entry
	GameEntry remove(int i)			// remove the ith entry
 private:
	int maxEntries;				// maximum number of entries
	int numEntries;				// actual number of entries
	GameEntry* entries;				// array of game entries
};