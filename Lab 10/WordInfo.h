#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class WordInfo {
public:
	//Default constructor
	WordInfo();
	//Member functions
	void ReadWordsFromFile(const char *filename);
	void DisplayStats() const;
	void MostCommonWords(int count, bool ignoreCommonFile = false) const;
	void LongestWords(vector<string> &words) const;
	void SetIgnoreWords(vector<string> &ignore);
	int SearchForWord(const char *word);
	//Container
	vector<string> SearchPartial(const char *word);
	//Destructor
	virtual ~WordInfo();
private:
	unsigned GetTotalWords() const;
	unsigned GetUniqueWords() const;
	string GetLongestWord() const;
	unsigned GetAvgWordSize() const;
	map<string, string> wordsToIgnore;
	unordered_map<string, int> wordsToCount;
	unsigned totalWords = 0;
};