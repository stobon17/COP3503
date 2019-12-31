#include "Showroom.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

//Default Constructor
Showroom::Showroom() {
	this->showroomName = "Name";
	this->maxCapacity = 0;
	this->currentVehicles = 0;
	arrayOfVehicles = new Vehicle[maxCapacity];
}
//Constructor
Showroom::Showroom(string name, unsigned int size) {
	this->showroomName = name;
	this->maxCapacity = size;
	this->currentVehicles = 0;
	arrayOfVehicles = new Vehicle[maxCapacity];
}
//Copy-Constructor
Showroom::Showroom(const Showroom &source) {
	this->showroomName = source.showroomName;
	this->maxCapacity = source.maxCapacity;
	this->currentVehicles = source.currentVehicles;

	arrayOfVehicles = new Vehicle[maxCapacity];
	for (unsigned int i = 0; i < currentVehicles; i++) {
		this->arrayOfVehicles[i] = source.arrayOfVehicles[i];
	}
}
//Assignment Operator
Showroom& Showroom::operator=(const Showroom &source) {
	if (this != &source) {
		delete[] arrayOfVehicles;
		this->showroomName = source.showroomName;
		this->maxCapacity = source.maxCapacity;
		this->currentVehicles = source.currentVehicles;

		arrayOfVehicles = new Vehicle[maxCapacity];
		for (unsigned int i = 0; i < currentVehicles; i++) {
			this->arrayOfVehicles[i] = source.arrayOfVehicles[i];
		}
	}
	return *this;
}
//Destructor
Showroom::~Showroom() {
	delete[] arrayOfVehicles;
}
//Member functions
void Showroom::AddVehicle(const Vehicle *v) {
	arrayOfVehicles[currentVehicles] = *v;
	currentVehicles++;
}
void Showroom::ShowInventory() const {
	cout << "Vehicles in " << showroomName << endl;
	for (unsigned int i = 0; i < currentVehicles; i++) {
		Vehicle newVehicle = arrayOfVehicles[i];
		newVehicle.Display();
	}
	cout << "\n";
}
const Vehicle* Showroom::GetVehicleList() const {
	return arrayOfVehicles;
}
unsigned int Showroom::GetCapacity() const {
	return maxCapacity;
}
unsigned int Showroom::GetCount() const {
	return currentVehicles;
}
const string Showroom::GetName() const {
	return showroomName;
}