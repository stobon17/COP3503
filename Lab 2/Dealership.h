#pragma once
#include "Showroom.h"
#include <iostream>
using namespace std;
class Dealership {
private:
	Showroom *arrayShowrooms;
	string nameofDealership;
	unsigned int maxSize;
	unsigned int currentShowrooms;
public:
	//Constructor
	Dealership(string dealershipName, unsigned int maxSize);

	//Copy Constructor
	Dealership(const Dealership &dealership);
	
	//Assignment Operator
	Dealership& operator=(const Dealership &dealership);
	
	//Destructor
	~Dealership();

	//Member Functions
	void AddShowroom(const Showroom *showroom);
	void ShowInventory() const;
	float GetAveragePrice() const;

};