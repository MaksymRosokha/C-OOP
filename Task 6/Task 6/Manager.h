#pragma once
#include <vector>
#include "OfficeWorker.h"

class Manager
{
private:
	vector<OfficeWorker> teamInfo;
	static int numManagers;
	const int id = numManagers;
	Person personalData;//Dane osobowe
	double baseSalary, bonus; //Pensja podstawowa, premia
	
public:

    Manager() : baseSalary(0.0), bonus(0.0), id(++numManagers)
    {
        personalData.setName("");
        personalData.setLastName("");
        personalData.setAge(0);
        cout << "Manager()\n";
    }
    Manager(string _name, string _lastName, int _age, double _baseSalary, double _bonus) : baseSalary(_baseSalary), bonus(_bonus), id(++numManagers)
    {
        personalData.setName(_name);
        personalData.setLastName(_lastName);
        personalData.setAge(_age);
        cout << "Manager(string _name, string _lastName, int _age, double _baseSalary, double _bonus)\n";
    }
    Manager(Person _personalData, double _baseSalary, double _bonus) : personalData(_personalData), baseSalary(_baseSalary), bonus(_bonus), id(++numManagers)
    {
        cout << "Manager(Person _personalData, double _baseSalary, double _bonus)\n";
    }
    ~Manager()
    {
        cout << "~Manager()\n";
    }
    void setName(string _name)
    {
        personalData.setName(_name);
    }
    void setLastName(string _lastName)
    {
        personalData.setLastName(_lastName);
    }
    void setAge(int _age)
    {
        personalData.setAge(_age);
    }
    void setPersonalData(Person _personalData)
    {
        personalData = _personalData;
    }
    void setBaseSalary(double _baseSalary)
    {
        baseSalary = _baseSalary;
    }
    void setBonus(double _bonus)
    {
        bonus = _bonus;
    }
    string getName() const
    {
        return personalData.getName();
    }
    string getLastName() const
    {
        return personalData.getLastName();
    }
    int getAge() const
    {
        return personalData.getAge();
    }
    Person getPersonalData() const
    {
        return personalData;
    }
    double getMonthSalary() const
    {
        return baseSalary + bonus;
    }
    void getInfo() const
    {
        personalData.getInfo();
        cout << "Pensja podstawowa: " << baseSalary << endl;
        cout << "Premia: " << bonus << endl;
    }

	static int getNumManagers() {
		return numManagers;
	}

	vector<OfficeWorker> getTeamInfo() {
		return teamInfo;
	}

	int getId() {
		return id;
	}

    void addEmployee(OfficeWorker ow) {
        teamInfo.push_back(ow);
    }
};



