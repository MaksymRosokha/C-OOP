#pragma once
#include <iostream>

using namespace std;

class FitnessBand
{
private:
	string model = "Noname";
protected:
	int step_count = 0;
public:
	FitnessBand() {
		cout << "FitnessBand()" << endl;
	}
	FitnessBand(string model) {
		cout << "FitnessBand(string model)" << endl;
		setModel(model);
	}
	~FitnessBand() {
		cout << "~FitnessBand()" << endl;
	}
	void monitor_activity() {
		this->step_count++;
	}
	void reset() {
		this->step_count = 0;
	}
	void getInfo() {
		cout << "Model: " << getModel() << endl;
		cout << "Liczba kroków: " << get_step_count() << endl;
	}
	string getModel() {
		return this->model;
	}
	int get_step_count() {
		return this->step_count;
	}
	void setModel(string model) {
		this->model = model;
	}
	void set_step_count(int steps) {
		this->step_count = steps;
	}
};

