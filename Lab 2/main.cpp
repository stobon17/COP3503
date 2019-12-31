#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"
#include <iostream>
#include <limits>
#include <memory>
#include <iomanip>
using namespace std;

void TestOne(Vehicle *v);
void TestTwo(Vehicle *v);

int main()
{
	// Initialize some data. It's hard-coded here, but this data could come from a file, database, etc
	Vehicle vehicles[] =
	{
		Vehicle("Ford", "Mustang", 1973, 9500, 113000), 
		Vehicle("Mazda", "CX-5", 2017, 24150, 5900),
		Vehicle("Dodge", "Charger", 2016, 18955, 9018),
		Vehicle("Telsa", "Model S", 2018, 74500, 31),
		Vehicle("Toyota", "Prius", 2015, 17819, 22987),
		Vehicle("Nissan", "Leaf", 2016, 12999, 16889),
		Vehicle("Chevrolet", "Volt", 2015, 16994, 12558),
	};

   int testNum;
   cin >> testNum;
   
   if (testNum == 1)
      TestOne(vehicles);
   else if (testNum == 2)
      TestTwo(vehicles);

	return 0;
}

void TestOne(Vehicle *vehicles)
{
   // Showrooms to store the vehicles
	Showroom showroom("Primary Showroom", 3);
	showroom.AddVehicle(&vehicles[0]);
	showroom.AddVehicle(&vehicles[1]);
	//showroom.AddVehicle(&vehicles[2]);
	
	Showroom secondary("Fuel-Efficient Showroom", 4);
	secondary.AddVehicle(&vehicles[3]);
	secondary.AddVehicle(&vehicles[4]);
	secondary.AddVehicle(&vehicles[5]);
	secondary.AddVehicle(&vehicles[6]);

	// A "parent" object to store the Showrooms
	Dealership dealership("COP3503 Vehicle Emporium", 2);
	dealership.AddShowroom(&showroom);
	dealership.AddShowroom(&secondary);

	dealership.ShowInventory();
}

void TestTwo(Vehicle *vehicles)
{
	// Showrooms to store the vehicles
	Showroom showroom("Primary Showroom", 3);
	showroom.AddVehicle(&vehicles[0]);
	showroom.AddVehicle(&vehicles[1]);
	
	Showroom secondary("Fuel-Efficient Showroom", 4);

	secondary.AddVehicle(&vehicles[4]);
	secondary.AddVehicle(&vehicles[5]);
	
	Showroom third("Fuel-Efficient Showroom", 4);
	third.AddVehicle(&vehicles[3]);
	// A "parent" object to store the Showrooms
	Dealership dealership("COP3503 Vehicle Emporium", 3);
	dealership.AddShowroom(&showroom);
	dealership.AddShowroom(&secondary);
	dealership.AddShowroom(&third);

   cout << "Using just the GetAveragePrice() function\n\n";

	cout << "Average price of the cars in the dealership: $" << std::fixed << std::setprecision(2);
	cout << dealership.GetAveragePrice();
}