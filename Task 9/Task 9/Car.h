#pragma once
#include "Vehicle.h"
class Car : public Vehicle
{
public:
	Car(int maxFuel, string numberPlate) : Vehicle(maxFuel, numberPlate){
		cout << "- Car was created -" << endl;
	}
	~Car() {
		cout << "- Car was deleted -" << endl;
	}
	virtual void repaire() {
		if (Vehicle::getState()) {
			cout << "The car is repaired" << endl;
			return;
		}
		Vehicle::repaire();
		cout << "The car was repaired" << endl;
	}
	virtual void getInfo() {
		cout << "* * * The car info: * * *" << endl;
		cout << "Plate number: " << Vehicle::getNumberPlate() << endl;
		cout << "Mark: " << Vehicle::getMark() << endl;
		cout << "Color: " << Vehicle::getColor() << endl;
		cout << "Is repaired: " << Vehicle::getState() << endl;
		cout << "Fuel amount: " << Vehicle::getFuelAmount() << endl;
		cout << "Max fuel amount: " << Vehicle::getMaxFuelAmount() << endl;
	}
};

