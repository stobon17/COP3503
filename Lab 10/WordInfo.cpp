#include "WordInfo.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

WordInfo::WordInfo() {
	//default constructor
}

//Member functions
void WordInfo::ReadWordsFromFile(const char *filename) {
	ifstream inputFile(filename);
	string line;
	while (getline(inputFile, line)) {
		vector<char> linesTaken;
		for (char character : line) {
			const int charInt = int(character);
			if ((65 <= charInt && charInt < 91) || (97 <= charInt && charInt < 123) || charInt == 32 || charInt == 45 || charInt == 39) {
				linesTaken.push_back(charInt);
			}
		}

		string parsedString(linesTaken.begin(), linesTaken.end());
		transform(parsedString.begin(), parsedString.end(), parsedString.begin(), ::tolower);

		istringstream myISS(parsedString);
		vector<string> result{
		  istream_iterator<string>(myISS),{}
		};

		for (string word : result) {
			if (!word.empty() && word.front() == '\'') {
				word.erase(word.begin());
			}
			if (!word.empty() && word.back() == '\'') {
				word.pop_back();
			}
			if (word != "--") {
				totalWords += 1;
				if (wordsToCount.find(word) != wordsToCount.end()) {
					wordsToCount[word] += 1;
				}
				else {
					wordsToCount[word] = 1;
				}
			}
		}
	}
}

void WordInfo::DisplayStats() const {
	cout << "Total number of words: " << totalWords << endl;
	cout << "Number of unique words: " << wordsToCount.size() << endl;
	cout << "Average word length: " << GetAvgWordSize() << endl;
	cout << "Longest word: " << GetLongestWord() << endl;
}

void WordInfo::MostCommonWords(int count, bool ignoreCommonFile) const {
	vector<pair<string, int>> sortedMap;
	for (auto iterand = wordsToCount.begin(); iterand != wordsToCount.end(); ++iterand) {
		sortedMap.push_back(make_pair(iterand->first, iterand->second));
	}

	sort(sortedMap.begin(), sortedMap.end(), [](pair<string, int> &first, pair<string, int> &second) {
		return first.second > second.second;
	});

	if (ignoreCommonFile) {
		cout << count << " most frequent words (ignoring most commonly used): " << endl;
		int counter = 0;
		for (auto iterand : sortedMap) {
			if (counter < count) {
				if (wordsToIgnore.find(iterand.first) == wordsToIgnore.end()) {
					cout << "   " << iterand.first << " " << iterand.second << endl;
					counter += 1;
				}
			}
			else {
				break;
			}
		}
	}
	else {
		cout << count << " most frequent words:" << endl;
		for (int i = 0; i < count; ++i) {
			cout << "   " << sortedMap[i].first << " " << sortedMap[i].second << endl;
		}
	}
}

void WordInfo::LongestWords(vector<string> &words) const {
	vector<pair<string, int>> sortedMap;

	for (auto iterand = wordsToCount.begin(); iterand != wordsToCount.end(); ++iterand) {
		sortedMap.push_back(make_pair(iterand->first, iterand->second));
	}

	sort(sortedMap.begin(), sortedMap.end(), [](pair<string, int> &first, pair<string, int> &second) {
		return first.first.size() > second.first.size();
	});

	words.clear();

	words.push_back(sortedMap.front().first);
	unsigned cur_max = sortedMap.front().first.size();
	for (size_t i = 1; i < sortedMap.size(); ++i) {
		if (sortedMap[i].first.size() == cur_max) {
			words.push_back(sortedMap[i].first);
		}
		else {
			break;
		}
	}
}

void WordInfo::SetIgnoreWords(vector<string> &ignore) {
	for (const string &word : ignore) {
		wordsToIgnore[word] = word;
	}
}

int WordInfo::SearchForWord(const char *word) {
	return wordsToCount[word];
}

vector<string> WordInfo::SearchPartial(const char *word) {
	vector<string> partialMatch;
	for (auto iterand = wordsToCount.begin(); iterand != wordsToCount.end(); ++iterand) {
		if (iterand->first.find(word) != string::npos) {
			partialMatch.push_back(iterand->first);
		}
	}
	return partialMatch;
}

unsigned WordInfo::GetTotalWords() const {
	return totalWords;
}

unsigned WordInfo::GetUniqueWords() const {
	return wordsToCount.size();
}

string WordInfo::GetLongestWord() const {
	vector<string> longestWords;
	LongestWords(longestWords);
	return longestWords.front();
}

unsigned WordInfo::GetAvgWordSize() const {
	unsigned charCount = 0;
	for (auto iterand = wordsToCount.begin(); iterand != wordsToCount.end(); ++iterand) {
		charCount += iterand->first.size() * iterand->second;
	}
	return charCount / totalWords;
}

WordInfo::~WordInfo() {
	//default
}