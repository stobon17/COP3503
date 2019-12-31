#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>
using namespace std;

mt19937 random_mt;
//Open file
std::ifstream inputStream("states.csv", ifstream::in);
int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

//Dice map
void PrintMap(map<int, unsigned int> myMap) { 
	map<int, unsigned int>::iterator myIter;
	for (myIter = myMap.begin(); myIter != myMap.end(); myIter++) {
		cout << myIter->first << ": " << myIter->second << endl;
	}
}

void RollDice(int numberOfRolls, int numberOfSides) {
	//Initialize a vector with amount of rolls with a random side rolled
	vector<int> rolls;
	int numberRolled = 0;
	for (int i = 0; i < numberOfRolls; i++) {
		numberRolled = Random(1, numberOfSides);
		rolls.push_back(numberRolled);
	}
	
	typedef map<int, unsigned int> CounterMap;
	CounterMap numCounts;
	//Initialize to zero
	for (int i = 1; i <= numberOfSides; i++) {
		numCounts[i] = 0;
	}
	//Count number of occurences
	for (unsigned int i = 0; i < rolls.size(); ++i) {
		CounterMap::iterator myIter(numCounts.find(rolls.at(i)));
		if (myIter != numCounts.end()) {
			(*myIter).second++;
		}
		else {
			numCounts[rolls.at(i)] = 1;
		}
		
	}
	PrintMap(numCounts);
}

struct CSVRow {
public:
	string stateName;
	string perCapitaIncome;
	string population;
	string householdIncome;
	string numHouseholds;
};
vector<CSVRow> rows;
void getAllData(ifstream &inData) {
	string nameState;
	if (!inData.is_open()) {
		cout << "Could not open file." << endl;
	}
	int index;
	string state;
	string pop;
	string PCI;
	string HHI;
	string numHH;

	//Skip first line that is not needed
	string skipLine;
	getline(inData, skipLine, ',');
	getline(inData, skipLine, ',');
	getline(inData, skipLine, ',');
	getline(inData, skipLine, ',');
	getline(inData, skipLine, '\n');
	//Iterate through and get value for each variable
	for (index = 1; index <= 54; index++) {
		getline(inData, state, ',');
		getline(inData, PCI, ',');
		getline(inData, pop, ',');
		getline(inData, HHI, ',');
		getline(inData, numHH, '\n');
		//Parse data
		CSVRow currentRow;
		currentRow.stateName = state;
		currentRow.perCapitaIncome = PCI;
		currentRow.population = pop;
		currentRow.householdIncome = HHI;
		currentRow.numHouseholds = numHH;
		rows.push_back(currentRow);
	}
	//Sort
	sort(rows.begin(), rows.end(), [](const CSVRow &lhs, const CSVRow &rhs) { return (lhs.stateName < rhs.stateName); });
	//Print data
	for (unsigned int i = 1; i <= rows.size() - 1; i++) {
		cout << rows[i].stateName << endl;
		cout << "Population: " << rows[i].population << endl;
		cout << "Per Capita Income: " << rows[i].perCapitaIncome << endl;
		cout << "Median Household Income: " << rows[i].householdIncome << endl;
		cout << "Number of Households: " << rows[i].numHouseholds << endl;
}
	inData.close();
}

void PrintStateMap(map<string, CSVRow> myMap) {
	map<string, CSVRow>::iterator myIter;
	for (myIter = myMap.begin(); myIter != myMap.end(); myIter++) {
		cout << myIter->first << "Population: " << myIter->second.population << endl
			<< "Per Capita Income: " << myIter->second.perCapitaIncome << endl << "Median Household Income: " << myIter->second.householdIncome
			<< endl << "Number of Households: " << myIter->second.numHouseholds << endl;
	}
}
void getStateData(string nameOfState, vector<CSVRow> &passedVector) {
	
	string nameState;
	if (!inputStream.is_open()) {
		cout << "Could not open file." << endl;
	}
	int index;
	string state;
	string pop;
	string PCI;
	string HHI;
	string numHH;

	//Skip first line that is not needed
	string skipLine;
	getline(inputStream, skipLine, ',');
	getline(inputStream, skipLine, ',');
	getline(inputStream, skipLine, ',');
	getline(inputStream, skipLine, ',');
	getline(inputStream, skipLine, '\n');
	//Iterate through and get value for each variable
	for (index = 1; index <= 54; index++) {
		getline(inputStream, state, ',');
		getline(inputStream, PCI, ',');
		getline(inputStream, pop, ',');
		getline(inputStream, HHI, ',');
		getline(inputStream, numHH, '\n');
		//Parse data
		CSVRow currentRow;
		currentRow.stateName = state;
		currentRow.perCapitaIncome = PCI;
		currentRow.population = pop;
		currentRow.householdIncome = HHI;
		currentRow.numHouseholds = numHH;
		rows.push_back(currentRow);
	}
	//Sort
	sort(rows.begin(), rows.end(), [](const CSVRow &lhs, const CSVRow &rhs) { return (lhs.stateName < rhs.stateName); });

	map<string, CSVRow> mapofStates;
	vector<CSVRow> assessedVector = passedVector;
	CSVRow currentState;

	bool checkName = true;
	for (unsigned int i = 0; i < assessedVector.size(); i++) {
		if (assessedVector[i].stateName == nameOfState) {
			currentState = assessedVector[i];
			checkName = true;
			break;
		}
		else {
			checkName = false;
		}
	}
	if (checkName == false) {
		cout << "No match found for " << nameOfState;
	}
	else if (checkName == true) {
		mapofStates.insert(make_pair(nameOfState, currentState));
		PrintStateMap(mapofStates);
	}
}


int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		cout << "Number of times to roll the die: ";
		// user input
		int numRolls;
		cin >> numRolls;

		cout << "Number of sides on this die: ";
		// user input
		int numSides;
		cin >> numSides;
		cout << endl;
		// Roll Dice
		RollDice(numRolls, numSides);
		//system("pause");
	}
	else if (option == 2)
	{
		//Open the file
		string userState;
		int stateOption;
		// Load the states
		cout << "1. Print all states" << endl;
		cout << "2. Search for a state" << endl;
		cin >> stateOption;
		switch (stateOption) {
		case 1:
			getAllData(inputStream);
			break;
		case 2:
			cin >> userState;
			getStateData(userState, rows);
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	}
	//system("pause");
	return 0;
}
