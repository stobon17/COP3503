#include "Vehicle.h"
#include <iostream>
using namespace std;

//Default Constructor
Vehicle::Vehicle() {
	this->vehicleMake = "N/A";
	this->vehicleModel = "N/A";
	this->yearMade = 0;
	this->vehiclePrice = 0;
	this->vehicleMileage = 0;
}

//Constructor
Vehicle::Vehicle(string makeofVehicle, string modelofVehicle, int year, float cost, float mileage) {
	this->vehicleMake = makeofVehicle;
	this->vehicleModel = modelofVehicle;
	this->yearMade = year;
	this->vehiclePrice = cost;
	this->vehicleMileage = mileage;
}

//Member Functions
void Vehicle::Display() const {
	cout << yearMade << " \t" << vehicleMake << " " << vehicleModel << " \t$"
		<< vehiclePrice << "\t" << vehicleMileage << endl;
}
string Vehicle::GetYearMakeModel() const {
	string returnedString = yearMade + "\t" + vehicleMake + "\t" + vehicleModel;
	return returnedString;
}
float Vehicle::GetPrice() const {
	return vehiclePrice;
}