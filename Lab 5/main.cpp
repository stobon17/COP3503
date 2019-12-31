#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

struct Lego {
	int number;
	string theme;
	string name;
	int miniFigs;
	int parts;
	float price;
	//Constructor
	Lego(const int p_number, string p_theme, string p_name, const int p_miniFigs, const int p_parts, const float p_price) {
		number = p_number;
		theme = move(p_theme);
		name = move(p_name);
		miniFigs = p_miniFigs;
		parts = p_parts;
		price = p_price;
	}
	//Copy Constructor
	Lego(const Lego &d) {
		number = d.number;
		theme = d.theme;
		name = d.name;
		miniFigs = d.miniFigs;
		parts = d.parts;
		price = d.price;
	}
	//Assignment Operator
	Lego& operator=(const Lego &d) {
		Lego temp(d);
		*this = move(temp);
		return *this;
	}
	//Destructor
	~Lego() = default;
	//Member Functions
	void PrintAttributes() {
		cout << "Name: " << name << endl;
		cout << "Number: " << number << endl;
		cout << "Theme: " << theme << endl;
		cout << "Price: $" << price << endl;
		cout << "Minifigures: " << miniFigs << endl;
		cout << "Piece count: " << parts << endl << endl;
	}

	void PrintShort() {
		cout << number << " " << name << " $" << price << " " << endl;
	}
};

void LoadLegoFromSingleFile(vector<Lego*> &legos, const string &fromFile) {
	int firstLine = 0;

	ifstream file(fromFile);
	string line;

	while (getline(file, line)) {
		if (firstLine == 0) {
			firstLine++;
			continue;
		}
		vector<string> parameters;
		vector<char> chars;
		for (unsigned int i = 0; i < line.size(); ++i) {
			if (line[i] == ',') {
				const string chars_str(chars.begin(), chars.end());
				parameters.push_back(chars_str);
				chars.clear();
			}
			else {
				chars.push_back(line[i]);
			}
		}

		const string chars_str(chars.begin(), chars.end());
		parameters.push_back(chars_str);
		chars.clear();

		const int number = parameters[0].empty() ? 0 : stoi(parameters[0]);
		const string theme = parameters[1];
		const string name = parameters[2];
		const int minifigs = parameters[3].empty() ? 0 : stoi(parameters[3]);
		const int pieces = parameters[4].empty() ? 0 : stoi(parameters[4]);
		float price = 0.0f;
		try {
			price = stof(parameters[5]);
		}
		catch (exception error) {}

		Lego *refreshedLego = new Lego(number, theme, name, minifigs, pieces, price);
		legos.push_back(refreshedLego);
	}
	file.close();
}

void LoadMultipleFiles(vector<Lego*> &legos, const vector<string> &fromFile) {
	for (const string &file : fromFile) {
		LoadLegoFromSingleFile(legos, file);
	}
}

void GetMostExpensive(vector<Lego*> legos) {
	Lego *mostExpensiveLego = legos.front();
	int highestPrice = 0;
	for (Lego* lego : legos) {
		if (highestPrice < lego->price) {
			highestPrice = lego->price;
			mostExpensiveLego = lego;
		}
	}

	cout << "Total number of sets: " << legos.size() << endl << endl;
	cout << "The most expensive set is:" << endl;
	mostExpensiveLego->PrintAttributes();
}

void GetLargestPieceCount(vector<Lego*> legos) {
	Lego *mostPieceLego = legos.front();
	int maxPiece = 0;
	for (Lego* lego : legos) {
		if (maxPiece < lego->parts) {
			maxPiece = lego->parts;
			mostPieceLego = lego;
		}
	}

	cout << "Total number of sets: " << legos.size() << endl << endl;
	cout << "The set with the highest parts count:" << endl;
	mostPieceLego->PrintAttributes();
}

void GetByName(vector<Lego*> legos, const string &string) {
	vector<Lego*> results;
	for (Lego* lego : legos) {
		if (lego->name.find(string) != string::npos) {
			results.push_back(lego);
		}
	}
	cout << "Total number of sets: " << legos.size() << endl << endl;
	if (results.size() != 0) {
		cout << "Sets matching \"" << string << "\":" << endl;
		for (Lego* lego : results)
			lego->PrintShort();
		cout << endl;
	}
	else {
		cout << "No sets found matching that search term" << endl;
	}
}

void GetByTheme(vector<Lego*> legos, const string &string) {
	vector<Lego*> results;
	for (Lego* lego : legos) {
		if (lego->theme.find(string) != string::npos) {
			results.push_back(lego);
		}
	}

	cout << "Total number of sets: " << legos.size() << endl << endl;
	if (results.size() != 0) {
		cout << "Sets matching \"" << string << "\":" << endl;
		for (Lego* lego : results) {
			lego->PrintShort();
		}
		cout << endl;
	}
	else {
		cout << "No sets found matching that search term" << endl;
	}
}

void GetPartCountInformation(vector<Lego*> legos) {
	int maxPartCount = 0;
	int minPartCount = INT_MAX;
	int totalPartCount = 0;
	Lego *maxLego = legos.front();
	Lego *minLego = legos.front();
	int nonZeroParts = 0;

	for (Lego* lego : legos) {
		if (lego->parts > 0) {
			if (maxPartCount < lego->parts) {
				maxPartCount = lego->parts;
				maxLego = lego;
			}
			if (minPartCount > lego->parts) {
				minPartCount = lego->parts;
				minLego = lego;
			}
		totalPartCount += lego->parts;
		nonZeroParts += 1;
		}
	}
	cout << "Total number of sets: " << legos.size() << endl << endl;
	cout << "Average part count for " << nonZeroParts << " sets: " << totalPartCount / nonZeroParts << endl << endl;
	cout << "Set with the smallest part count:" << endl;
	minLego->PrintAttributes();
	cout << "Set with the largest part count:" << endl;
	maxLego->PrintAttributes();
}

void GetPriceInformation(vector<Lego*> legos) {
	int maxPrice = 0;
	int minPrice = INT_MAX;
	float totalPrice = 0;
	Lego *maxLego = legos.front();
	Lego *minLego = legos.front();
	int nonZeroPrices = 0;

	for (Lego* lego : legos) {
		if (lego->price > 0) {
			if (maxPrice < lego->price) {
				maxPrice = lego->price;
				maxLego = lego;
			}
			if (minPrice > lego->price) {
				minPrice = lego->price;
				minLego = lego;
			}
		totalPrice += lego->price;
		nonZeroPrices += 1;
		}
	}
	cout << "Total number of sets: " << legos.size() << endl << endl;

	if (nonZeroPrices != 0) {
		cout << "Average price for " << nonZeroPrices << " sets: $" << totalPrice / nonZeroPrices << endl << endl;
		cout << "Least expensive set:" << endl;
		minLego->PrintAttributes();
		cout << "Most expensive set:" << endl;
		maxLego->PrintAttributes();
	}
	else
		cout << "Error in price" << endl;
}

void GetMiniFigureInformation(vector<Lego*> legos) {
	int maxMiniFigs = 0;
	int minMiniFigs = INT_MAX;
	int totalMiniFigs = 0;
	Lego *maxLego = legos.front();
	Lego *minLego = legos.front();
	int nonZeroMiniFigs = 0;

	for (Lego* lego : legos) {
		if (lego->miniFigs > 0) {
			if (maxMiniFigs < lego->miniFigs) {
				maxMiniFigs = lego->miniFigs;
				maxLego = lego;
			}
			if (minMiniFigs > lego->miniFigs) {
				minMiniFigs = lego->miniFigs;
				minLego = lego;
			}
			totalMiniFigs += lego->miniFigs;
			nonZeroMiniFigs += 1;
		}
	}
	cout << "Total number of sets: " << legos.size() << endl << endl;
	cout << "Average number of minifigures: " << totalMiniFigs / nonZeroMiniFigs << endl << endl;
	cout << "Set with the most minifigures:" << endl;
	maxLego->PrintAttributes();
	cout << "Set with the fewest minifigures:" << endl;
	minLego->PrintAttributes();
}

void GetOneOfEverythingInformation(vector<Lego*> legos) {
	float totalCost = 0;
	int totalCountNumber = 0;
	int totalMiniFigs = 0;

	for (Lego* lego : legos) {
		totalCost += lego->price;
		totalCountNumber += lego->parts;
		totalMiniFigs += lego->miniFigs;
	}
	cout << "Total number of sets: " << legos.size() << endl << endl;
	cout << "If you bought one of everything..." << endl;
	cout << "It would cost: $" << totalCost << endl;
	cout << "You would have " << totalCountNumber << " pieces in your collection" << endl;
	cout << "You would have an army of " << totalMiniFigs << " minifigures!" << endl;
}

int main() {
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	std::cin >> option;

	/*======= Load data from file(s) =======*/
	vector<Lego*> legos;
	vector<string> fileNames = { "lego1.csv", "lego2.csv", "lego3.csv" };

	switch (option) {
	case 1:
		LoadLegoFromSingleFile(legos, fileNames[0]);
		break;
	case 2:
		LoadLegoFromSingleFile(legos, fileNames[1]);
		break;
	case 3:
		LoadLegoFromSingleFile(legos, fileNames[2]);
		break;
	case 4:
		LoadMultipleFiles(legos, fileNames);
		break;
	}

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Based on the choice, execute the appropriate task and show the results =======*/
	switch (choice) {
	case 1:
		GetMostExpensive(legos);
		break;
	case 2:
		GetLargestPieceCount(legos);
		break;
	case 3: {
		string passedString;
		getline(cin, passedString);
		GetByName(legos, passedString);
		break;
	}
	case 4: {
		string passedString;
		getline(cin, passedString);
		GetByTheme(legos, passedString);
		break;
	}
	case 5:
		GetPartCountInformation(legos);
		break;
	case 6:
		GetPriceInformation(legos);
		break;
	case 7:
		GetMiniFigureInformation(legos);
		break;
	case 8:
		GetOneOfEverythingInformation(legos);
		break;
	case 0:
		break;
	}
	return 0;
}