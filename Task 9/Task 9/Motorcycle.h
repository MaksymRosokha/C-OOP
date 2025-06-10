#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle(int maxFuel, string numberPlate) : Vehicle(maxFuel, numberPlate) {
		cout << "- Motorcycle was created -" << endl;
	}
	~Motorcycle() {
		cout << "- Motorcycle was deleted -" << endl;
	}
	virtual void repaire() {
		if (Vehicle::getState()) {
			cout << "The motorcycle is repaired" << endl;
			return;
		}
		Vehicle::repaire();
		cout << "The motorcycle was repaired" << endl;
	}
	virtual void beep() {
		cout << "~ ~ Bip bip! ~ ~" << endl;
	}
	virtual void getInfo() {
		cout << "* * * The motorcycle info: * * *" << endl;
		cout << "Plate number: " << Vehicle::getNumberPlate() << endl;
		cout << "Mark: " << Vehicle::getMark() << endl;
		cout << "Color: " << Vehicle::getColor() << endl;
		cout << "Is repaired: " << Vehicle::getState() << endl;
		cout << "Fuel amount: " << Vehicle::getFuelAmount() << endl;
		cout << "Max fuel amount: " << Vehicle::getMaxFuelAmount() << endl;
	}
};

