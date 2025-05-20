#pragma once
#include "Person.h"
#include "iostream"

using namespace std;


class OfficeWorker
{
private:
    Person personalData; //Dane osobowe pracownika: imię, nazwisko, wiek
    int hours; //Liczba przepracowanych godzin
    double rate; //Stawka godzinowa
    static int numOfficeWorkers;
    const int id = numOfficeWorkers;

public:
    OfficeWorker() : hours(0), rate(0.0), id(++numOfficeWorkers)
    {
        personalData.setName("");
        personalData.setLastName("");
        personalData.setAge(0);
        cout << "OfficeWorker()\n";
    }
    OfficeWorker(string _name, string _lastName, int _age) : id(++numOfficeWorkers)
    {
        personalData.setName(_name);
        personalData.setLastName(_lastName);
        personalData.setAge(_age);
        cout << "OfficeWorker(string _name, string _lastName, int _age)\n";
    }
    OfficeWorker(string _name, string _lastName, int _age, int _hours, double _rate) : hours(_hours), rate(_rate), id(++numOfficeWorkers)
    {
        personalData.setName(_name);
        personalData.setLastName(_lastName);
        personalData.setAge(_age);
        cout << "OfficeWorker(string _name, string _lastName, int _age, int _hours, double _rate)\n";
    }
    OfficeWorker(Person _personalData, int _hours, double _rate) : personalData(_personalData), hours(_hours), rate(_rate), id(++numOfficeWorkers)
    {
        cout << "OfficeWorker(Person _personalData, int _hours, double _rate)\n";
    }
    ~OfficeWorker()
    {
        cout << "~OfficeWorker()\n";
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
    void setPersonalData(string _name, string _lastName, int _age)
    {
        personalData.setName(_name);
        personalData.setLastName(_lastName);
        personalData.setAge(_age);
    }
    void setHours(int _hours)
    {
        hours = _hours;
    }
    void setRate(double _rate)
    {
        rate = _rate;
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
    int getHours() const
    {
        return hours;
    }
    double getRate() const
    {
        return rate;
    }
    double getMonthSalary() const
    {
        return hours * rate;
    }
    void getInfo() const
    {
        personalData.getInfo();
        cout << "Liczba godzin: " << hours << endl;
        cout << "Stawka godzinowa: " << rate << endl;
    }
    static int getNumOfficeWorkers() {
        return numOfficeWorkers;
    }

    int getId() {
        return id;
    }
};

