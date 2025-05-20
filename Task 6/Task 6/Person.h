#pragma once
#include "iostream"

using namespace std;

class Person
{
private:
    string name, lastName; //imi?, nazwisko
    int age; //wiek
public:
    //Definicje funkcji sk?adowych klasy Person
    Person() : name(""), lastName(""), age(0)
    {
        cout << "Person()\n";
    }
    Person(string _name, string _lastName, int _age) : name(_name), lastName(_lastName), age(_age)
    {
        cout << "Person(string _name, string _lastName, int _age)\n";
    }
    ~Person()
    {
        cout << "~Person()\n";
    }
    void setName(string _name)
    {
        name = _name;
    }
    void setLastName(string _lastName)
    {
        lastName = _lastName;
    }
    void setAge(int _age)
    {
        age = _age;
    }
    string getName() const
    {
        return name;
    }
    string getLastName() const
    {
        return lastName;
    }
    int getAge() const
    {
        return age;
    }
    void getInfo() const
    {
        cout << "Imi?: " << name << endl;
        cout << "Nazwisko: " << lastName << endl;
        cout << "Wiek: " << age << endl;
    }
};


