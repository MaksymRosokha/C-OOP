#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"


using namespace std;

int main()
{
    cout << "- - - Vehicle inspection station - - -" << endl;

    Car* car = new Car(50, "AA1234BB");
    Truck* truck = new Truck(150, "TR8888XH");
    Motorcycle* moto = new Motorcycle(15, "MC5555YZ");
    const int amount = 3;
    Vehicle* vehicles[amount];
    vehicles[0] = car;
    vehicles[1] = truck;
    vehicles[2] = moto;

    car->setColor("Red");
    car->setMark("Toyota");
    car->setFuelAmount(30);
    car->setState(false);

    truck->setColor("Blue");
    truck->setMark("Volvo");
    truck->setFuelAmount(140);
    truck->setState(true);

    moto->setColor("Black");
    moto->setMark("Yamaha");
    moto->setFuelAmount(10);
    moto->setState(false);

    for (int i = 0; i < amount; i++) {
        vehicles[i]->repaire();
    }
    for (int i = 0; i < amount; i++) {
        vehicles[i]->beep();
    }
    for (int i = 0; i < amount; i++) {
        vehicles[i]->getInfo();
    }

    for (auto v : vehicles) {
        if (dynamic_cast<Car*>(v)) {
            cout << v->getNumberPlate() << ": this is a Car." << endl;
        }
        else if (dynamic_cast<Truck*>(v)) {
            cout << v->getNumberPlate() << ": this is a Truck." << endl;
        }
        else if (dynamic_cast<Motorcycle*>(v)) {
            cout << v->getNumberPlate() << ": this is a Motorcycle." << endl;
        }
        else {
            cout << v->getNumberPlate() << "Unknown vehicle" << endl;
        }
    }

    return 0;
}