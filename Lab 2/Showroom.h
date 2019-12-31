#pragma once
#include <string>
#include "Vehicle.h"
using namespace std;

class Showroom {
private:
	string showroomName;
	Vehicle *arrayOfVehicles;
	unsigned int currentVehicles;
	unsigned int maxCapacity;
public:
	//Constructors
	Showroom();
	Showroom(string name, unsigned int size);
	//Copy-Constructor
	Showroom(const Showroom &source);
	//Assignment Operator
	Showroom& operator=(const Showroom &showroom);
	//Destructor
	~Showroom();
	//Member Functions
	void AddVehicle(const Vehicle *v);
	void ShowInventory() const;
	const Vehicle *GetVehicleList() const;
	unsigned int GetCapacity() const;
	unsigned int GetCount() const;
	const string GetName() const;
};