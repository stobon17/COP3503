#include "Dealership.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor
Dealership::Dealership(string dealershipName, unsigned int maxSize)
{
	this->nameofDealership = dealershipName;
	this->maxSize = maxSize;
	this->currentShowrooms = 0;
	arrayShowrooms = new Showroom[maxSize];
}
//Copy-Constructor
Dealership::Dealership(const Dealership &dealership)
{
	this->nameofDealership = dealership.nameofDealership;
	this->maxSize = dealership.maxSize;
	this->currentShowrooms = dealership.currentShowrooms;

	arrayShowrooms = new Showroom[maxSize];
	for (unsigned int i = 0; i < currentShowrooms; i++)
	{
		this->arrayShowrooms[i] = dealership.arrayShowrooms[i];
	}
}
//Assignment Operator
Dealership& Dealership::operator=(const Dealership &dealership)
{
	if (this != &dealership)
	{
		delete arrayShowrooms;
		this->nameofDealership = dealership.nameofDealership;
		this->maxSize = dealership.maxSize;
		this->currentShowrooms = dealership.currentShowrooms;

		arrayShowrooms = new Showroom[maxSize];
		for (unsigned int i = 0; i < currentShowrooms; i++)
		{
			this->arrayShowrooms[i] = dealership.arrayShowrooms[i];
		}
	}
	return *this;
}
//Destructor
Dealership::~Dealership() {
	delete[] arrayShowrooms;
}
//Member functions
void Dealership::AddShowroom(const Showroom *showroom) {
	arrayShowrooms[currentShowrooms] = *showroom;
	currentShowrooms++;
}
void Dealership::ShowInventory() const {
	cout << "Inventory of " << nameofDealership << endl;
	for (unsigned int i = 0; i < maxSize; i++) {
		Showroom showroom = arrayShowrooms[i];
		showroom.ShowInventory();
	}
	cout << "Average car price: $" << std::fixed << std::setprecision(2);
	cout << GetAveragePrice() << endl;
}
float Dealership::GetAveragePrice() const {
	int value = 0;
	float total = 0;
	for (unsigned int i = 0; i < currentShowrooms; i++) {
		const Showroom showroom = arrayShowrooms[i];
		for (unsigned int j = 0; j < showroom.GetCount(); j++) {
			total += showroom.GetVehicleList()[j].GetPrice();
			value++;
		}
	}
	return total / static_cast<float>(value);
}