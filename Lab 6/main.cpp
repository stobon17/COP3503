#include <algorithm>
#include <limits>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Inventory {
	string name;
	int value;
	float weight;
	//Constructor
	Inventory(string &&p_name, int p_value, float p_weight) {
		name = p_name;
		value = p_value;
		weight = p_weight;
	}
};

struct Hero {
	string name;
	int strength;
	int intelligence;
	int agility;
	int currentHP;
	int maxHP;
	float armor;
	float magicalArmor;
	vector<Inventory*> heroInventories;
	//Constructor
	Hero(string &&p_name, int p_strength, int p_intelligence, int p_agility, int p_currentHP, int p_maxHP, float p_armor, float p_magicalArmor, vector<Inventory*> &p_heroInventories) {
		name = p_name;
		strength = p_strength;
		intelligence = p_intelligence;
		agility = p_agility;
		currentHP = p_currentHP;
		maxHP = p_maxHP;
		armor = p_armor;
		magicalArmor = p_magicalArmor;
		heroInventories = p_heroInventories;
	}

	int GetInventoryValue() const {
		int totalVal = 0;
		for (const Inventory *assessedInventory : heroInventories) {
			totalVal = totalVal + assessedInventory->value;
		}
		return totalVal;
	}
};

void PrintHeroData(const Hero &d_hero) {
	cout << "Name: " << d_hero.name << endl;
	cout << "Str: " << d_hero.strength << endl;
	cout << "Int: " << d_hero.intelligence << endl;
	cout << "Agi: " << d_hero.agility << endl;
	cout << "HP: " << d_hero.currentHP << " / " << d_hero.maxHP << endl;
	cout << "Armor: " << d_hero.armor * 100 << "%" << endl;
	float magicalArmorVal = d_hero.magicalArmor * 100;
	cout << "Magic armor: " << magicalArmorVal << "%" << endl;
	cout << "Inventory: " << endl;

	if (d_hero.heroInventories.size() > 0) {
		for (const Inventory* assessedInventory : d_hero.heroInventories) {
			cout << assessedInventory->name << ", ";
			cout << assessedInventory->value << ", ";
			cout << assessedInventory->weight << endl;
		}
	}
	else {
		cout << "Inventory empty." << endl;
	}
	cout << endl;
}

void LoadHeroFile(vector<Hero*> &p_heros, const string &p_file) {
	ifstream fileStream(p_file, ifstream::binary);
	if (fileStream) {
		int numChars;
		fileStream.read((char *)&numChars, 4);

		for (int i = 0; i < numChars; ++i) {
			int lengthName;
			fileStream.read((char *)&lengthName, 4);

			char *name = new char[lengthName];
			fileStream.read(name, lengthName);

			short strength;
			fileStream.read((char *)&strength, 2);

			short intelligence;
			fileStream.read((char *)&intelligence, 2);

			short agility;
			fileStream.read((char *)&agility, 2);

			int currentHP;
			fileStream.read((char *)&currentHP, 4);
			int maxHP;
			fileStream.read((char *)&maxHP, 4);

			float armor;
			fileStream.read((char *)&armor, 4);

			float magicalArmor;
			fileStream.read((char *)&magicalArmor, 4);

			int numInventory;
			fileStream.read((char *)&numInventory, 4);
			
			vector<Inventory*> assessedInventory;
			for (int j = 0; j < numInventory; ++j) {
				int assessedInventoryNameLength;
				fileStream.read((char *)&assessedInventoryNameLength, 4);

				char *assessedInventoryName = new char[assessedInventoryNameLength];
				fileStream.read(assessedInventoryName, assessedInventoryNameLength);

				int assessedInventoryVal;
				fileStream.read((char *)&assessedInventoryVal, 4);

				float assessedInventoryWeight;
				fileStream.read((char *)&assessedInventoryWeight, 4);

				assessedInventory.push_back(new Inventory(assessedInventoryName, assessedInventoryVal, assessedInventoryWeight));
			}
			p_heros.push_back(new Hero(name, strength, intelligence, agility, currentHP, maxHP, armor, magicalArmor, assessedInventory));
		}
		fileStream.close();
	}
}

void PrintAllHeroData(vector<Hero*> p_heros) {
	for (const Hero* assessedHero : p_heros) {
		PrintHeroData(*assessedHero);
	}
}

void PrintHeroWithMostItems(vector<Hero*> p_heros) {
	unsigned int maxInventorySize = 0; //size_t
	const Hero *heroWithMostItems = p_heros.front();
	for (const Hero* assessedHero : p_heros) {
		if (maxInventorySize < assessedHero->heroInventories.size()) {
			maxInventorySize = assessedHero->heroInventories.size();
			heroWithMostItems = assessedHero;
		}
	}
	PrintHeroData(*heroWithMostItems);
}

void PrintStrongestHero(vector<Hero*> p_heros) {
	int highestStrength = 0;
	const Hero *heroWithHighestStrength = p_heros.front();
	for (const Hero* assessedHero : p_heros) {
		if (highestStrength < assessedHero->strength) {
			highestStrength = assessedHero->strength;
			heroWithHighestStrength = assessedHero;
		}
	}
	PrintHeroData(*heroWithHighestStrength);
}

void PrintHeroWithSuperiorIntelligence(vector<Hero*> p_heros) {
	vector<Hero*> smartHeros;
	for (Hero* assessedHero : p_heros) {
		if (assessedHero->intelligence > 18) {
			smartHeros.push_back(assessedHero);
		}
	}
	for (const Hero* assessedHero : smartHeros) {
		PrintHeroData(*assessedHero);
	}
}

void Print2ClumsiestHeros(vector<Hero*> p_heros) {
	sort(p_heros.begin(), p_heros.end(), [](const Hero* lhs, const Hero* rhs) {  //Got idea from stack overflow https://stackoverflow.com/questions/5174115/sorting-a-vector-of-objects-by-a-property-of-the-object
		return lhs->agility < rhs->agility;
	});

	if (p_heros.size() >= 2) {
		cout << "Clumsiest hero:" << endl;
		PrintHeroData(*p_heros[0]);
		cout << "Second clumsiest hero: " << endl;
		PrintHeroData(*p_heros[1]);
	}
	else {
		for (const Hero* hero : p_heros) {
			PrintHeroData(*hero);
		}
	}
}

void PrintHeroWithMostValInventory(vector<Hero*>& p_heros) {
	int highestInventoryVal = 0;
	const Hero* heroWithMostValuableInventory = p_heros.front();
	for (const Hero* assessedHero : p_heros) {
		if (highestInventoryVal < assessedHero->GetInventoryValue()) {
			highestInventoryVal = assessedHero->GetInventoryValue();
			heroWithMostValuableInventory = assessedHero;
		}
	}
	PrintHeroData(*heroWithMostValuableInventory);
}


int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. fantasyheroes.dat" << endl;
	cout << "2. superheroes.dat" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	vector<Hero*> heroes;

	if (option == 1) {
		LoadHeroFile(heroes, "fantasyheroes.dat");
	}
	else if (option == 2) {
		LoadHeroFile(heroes, "superheroes.dat");
	}
	else if (option == 3) {
		LoadHeroFile(heroes, "fantasyheroes.dat");
		LoadHeroFile(heroes, "superheroes.dat");
	}
	else if (cin.fail()) {
		cout << "Invalid input.";
	}
	else {
		cout << "Invalid input.";
	}

	cout << "1. Print all heroes" << endl;
	cout << "2. Hero with the most items" << endl;
	cout << "3. Strongest hero" << endl;
	cout << "4. Heroes with greater than 18 intelligence" << endl;
	cout << "5. 2 clumsiest heroes" << endl;
	cout << "6. Hero with the most valuable stuff" << endl << endl;

	std::cin >> option;

	/* Work your magic here */
	switch (option) {
	case 1:
		PrintAllHeroData(heroes);
		break;
	case 2:
		PrintHeroWithMostItems(heroes);
		break;
	case 3:
		PrintStrongestHero(heroes);
		break;
	case 4:
		PrintHeroWithSuperiorIntelligence(heroes);
		break;
	case 5:
		Print2ClumsiestHeros(heroes);
		break;
	case 6:
		PrintHeroWithMostValInventory(heroes);
		break;
	}
	return 0;
}