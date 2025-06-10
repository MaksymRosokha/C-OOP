#pragma once
#include "Vehicle.h"
class Truck : public Vehicle
{
public:
	Truck(int maxFuel, string numberPlate) : Vehicle(maxFuel, numberPlate) {
		cout << "- Truck was created -" << endl;
	}
	~Truck() {
		cout << "- Truck was deleted -" << endl;
	}
	virtual void repaire() {
		if (Vehicle::getState()) {
			cout << "The truck is repaired" << endl;
			return;
		}
		Vehicle::repaire();
		cout << "The truck was repaired" << endl;
	}
	virtual void beep() {
		cout << "~ ~ Beeeeep beeeeep! ~ ~" << endl;
	}
	virtual void getInfo() {
		cout << "* * * The truck info: * * *" << endl;
		cout << "Plate number: " << Vehicle::getNumberPlate() << endl;
		cout << "Mark: " << Vehicle::getMark() << endl;
		cout << "Color: " << Vehicle::getColor() << endl;
		cout << "Is repaired: " << Vehicle::getState() << endl;
		cout << "Fuel amount: " << Vehicle::getFuelAmount() << endl;
		cout << "Max fuel amount: " << Vehicle::getMaxFuelAmount() << endl;
	}
};

