#pragma once
#include <string>
using namespace std;

class Vehicle {
private:
	string vehicleMake;
	string vehicleModel;
	float vehiclePrice;
	float vehicleMileage;
	int yearMade;
public:
	//Constructors
	Vehicle();
	Vehicle(string makeofVehicle, string modelofVehicle, int year, float cost, float mileage);
	//Member functions
	void Display() const;
	string GetYearMakeModel() const;
	float GetPrice() const;
};