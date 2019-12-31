// Lexer.cpp : Defines the entry point for the console application.
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "WordInfo.h"
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	// TODO: Load words_to_ignore.txt, store those in a vector of strings to pass to your class objects
	ifstream inputFile("words_to_ignore.txt");
	string line;
	vector<string> wordsToIgnore;
	while (getline(inputFile, line)) {
		wordsToIgnore.push_back(line);
	}

	cout << "1-4: Which file to open?" << endl;
	int userOption;
	cin >> userOption;

	// TODO: Create a WordList object and set the list of words to ignore
	WordInfo wordInfo;

	vector<string> files = { "testfile.txt", "file1.txt", "file2.txt", "file3.txt", "file4.txt" };
	string file = files[userOption];

	wordInfo.ReadWordsFromFile(file.c_str());
	wordInfo.DisplayStats();
	wordInfo.MostCommonWords(userOption + 1);
	wordInfo.SetIgnoreWords(wordsToIgnore);
	wordInfo.MostCommonWords(userOption + 1, true);
	// Read the words from the file
	// Show the stats
	// Show the most frequent words, NOT using the ignore list
	// Show the most frequent words, using the ignore list (to ignore the universally common words)

	// (Show a number of common words based on the selected file + 1. First file shows 2 common words, second shows 3, 4th shows 5, etc)

	// Get and then show the longest words
	vector<string> longestWords;
	wordInfo.LongestWords(longestWords);
	cout << "Longest word(s): " << endl;
	for (auto iterand : longestWords) {
		cout << "   " << iterand << endl;
	}

	// Get input for a word, and do an exact match search for that word. (Convert input to lowercdase first!)
	cout << "Enter a word for an exact search: ";
	string searchTerm;
	cin >> searchTerm;

	transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
	int count = wordInfo.SearchForWord(searchTerm.c_str());
	cout << "\n   " << '\'' << searchTerm << "' was found " << count << " times in the list.\n";

	// Ditto for partial search...
	cout << "Enter a word for a partial search: ";
	string searchTerm2;
	cin >> searchTerm2;
	vector<string> partial_matches = wordInfo.SearchPartial(searchTerm2.c_str());
	if (partial_matches.empty())
		cout << "\n   No entries match '" << searchTerm2 << '\'' << endl;
	else {
		cout << "\nWords containing '" << searchTerm2 << '\'' << endl;
		sort(partial_matches.begin(), partial_matches.end());
		// print list o' matches
		for (string& iterand : partial_matches)
			cout << "   " << iterand << endl;
	}

	return 0;
}