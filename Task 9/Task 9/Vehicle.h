#pragma once
#include <iostream>

using namespace std;

class Vehicle
{
private:
	int fuelAmount = 0;
	const int maxFuelAmount;
	bool isRepaired = false;
	string numberPlate;
	string color;
	string mark;

public:
	Vehicle(int maxFuel, string numberPlate) : maxFuelAmount(maxFuel) {
		cout << "- Vehicle was created -" << endl;
		this->numberPlate = numberPlate;
	}
	~Vehicle() {
		cout << "- Vehicle was deleted -" << endl;
	}
	void setFuelAmount(int fuelAmount) {
		if (this->fuelAmount + fuelAmount <= this->maxFuelAmount) {
			this->fuelAmount += fuelAmount;
		}
		else {
			this->fuelAmount = this->maxFuelAmount;
		}
	}
	int getFuelAmount() {
		return this->fuelAmount;
	}
	int getMaxFuelAmount() {
		return this->maxFuelAmount;
	}
	void setState(bool state) {
		this->isRepaired = state;
	}
	bool getState() {
		return this->isRepaired;
	}
	void setNumberPlate(string numberPlate) {
		this->numberPlate = numberPlate;
	}
	string getNumberPlate() {
		return this->numberPlate;
	}
	void setColor(string color) {
		this->color = color;
	}
	string getColor() {
		return this->color;
	}
	void setMark(string mark) {
		this->mark = mark;
	}
	string getMark() {
		return this->mark;
	}
	virtual void repaire() {
		this->isRepaired = true;
	}
	virtual void beep() {
		cout << "~ ~ Beep beep! ~ ~" << endl;
	}
	virtual void getInfo() = 0;
};

