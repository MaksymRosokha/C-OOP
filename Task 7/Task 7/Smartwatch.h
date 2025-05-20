#pragma once
#include <iostream>
#include "FitnessBand.h"

using namespace std;

class Smartwatch : FitnessBand
{
private:
	float distance_m = 0.0;
	int battery_level = 0;

public:
	Smartwatch() {
		cout << "Smartwatch()" << endl;
		charge(100);
	}
	Smartwatch(string model) {
		cout << "Smartwatch(string model)" << endl;
		setModel(model);
		charge(100);
	}
	Smartwatch(string model, int battery_level) {
		cout << "Smartwatch(string model, int battery_level)" << endl;
		setModel(model);
		charge(battery_level);
	}
	~Smartwatch() {
		cout << "~Smartwatch()" << endl;
	}
	void monitor_activity() {
		if (this->battery_level != 0) {
			this->step_count++;
			this->distance_m += 0.65;
			if (this->step_count % 1000 == 0) {
				this->battery_level--;
			}
		}
	}
	void reset() {
		this->step_count = 0;
		this->distance_m = 0;
	}
	void charge(int minutes) {
		this->battery_level += minutes;
		if (this->battery_level > 100) {
			this->battery_level = 100;
		}
	}
	void getInfo() {
		cout << "Model: " << getModel() << endl;
		cout << "Liczba kroków: " << get_step_count() << endl;
		cout << "Dystans: " << get_distance_m() << " m" << endl;
		cout << "Poziom barerii: " << get_battery_level() << "%" << endl;
	}
	string getModel() {
		return FitnessBand::getModel();
	}
	int get_step_count() {
		return this->step_count;
	}
	void setModel(string model) {
		FitnessBand::setModel(model);
	}
	void set_step_count(int steps) {
		this->step_count = steps;
	}
	float get_distance_m() {
		return this->distance_m;
	}
	void set_distance_m(float distance_m) {
		this->distance_m = distance_m;
	}
	int get_battery_level() {
		return this->battery_level;
	}
};

