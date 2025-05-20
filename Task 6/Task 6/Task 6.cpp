#include <iostream>
#include "Person.h"
#include "OfficeWorker.h"
#include "Manager.h"

using namespace std;

int main()
{
    cout << "Aktualizacja bazy pracowników ...\n";
    Manager man1("Katarzyna", "Katarzynowska", 38, 12000, 1451.5);
    man1.getInfo();
    cout << "Pensja miesięczna: " << man1.getMonthSalary() << endl;
    man1.getTeamInfo(); //Lista pracowników w zespole kierowanym przez Menedżera man1
    cout << "Aktualna liczba pracowników:\n";
    cout << "Managers: " << Manager::getNumManagers() << ", OfficeWorkers: " << OfficeWorker::getNumOfficeWorkers() << endl;
    cout << "\nAktualizacja bazy pracowników ...\n";
    Person p1("Grzegorz", "Grzegorzewski", 48);
    Manager man2(p1, 15250, 2178.5);
    man2.getInfo();
    cout << "Pensja miesięczna: " << man2.getMonthSalary() << endl;
    man2.getTeamInfo(); //Lista pracowników w zespole kierowanym przez Menedżera man2
    cout << "Aktualna liczba pracowników:\n";
    cout << "Managers: " << Manager::getNumManagers() << ", OfficeWorkers: " << OfficeWorker::getNumOfficeWorkers() << endl;
    cout << "\nAktualizacja bazy pracowników ...\n";
    OfficeWorker ow1("Tomasz", "Tomaszewski", 26, 175, 24.5);
    man1.addEmployee(ow1); //Dodanie pracownika typu OfficeWorker do zespołu Menedżera man1
    OfficeWorker ow2("Maja", "Majewska", 32, 170, 26.5);
    man2.addEmployee(ow2); //Dodanie pracownika typu OfficeWorker do zespołu Menedżera man2
    man1.getInfo();
    cout << "Pensja miesięczna: " << man1.getMonthSalary() << endl;
    man1.getTeamInfo(); //Lista pracowników w zespole kierowanym przez Menedżera man1
    man2.getInfo();
    cout << "Pensja miesięczna: " << man2.getMonthSalary() << endl;
    man2.getTeamInfo(); //Lista pracowników w zespole kierowanym przez Menedżera man2
    cout << "Aktualna liczba pracowników:\n";
    cout << "Managers: " << Manager::getNumManagers() << ", OfficeWorkers: " << OfficeWorker::getNumOfficeWorkers() << endl;
    cout << "\nAktualizacja bazy pracowników ...\n";
    OfficeWorker ow3("Beata", "Beatowska", 31, 180, 25.0);
    man1.addEmployee(ow3); //Dodanie pracownika typu OfficeWorker do zespołu Menedżera man1
    OfficeWorker ow4("Paweł", "Pawłowski", 41, 165, 27.0);
    man2.addEmployee(ow4); //Dodanie pracownika typu OfficeWorker do zespołu Menedżera man2
    man1.getInfo();
    cout << "Pensja miesięczna: " << man1.getMonthSalary() << endl;
    man1.getTeamInfo(); //Lista pracowników w zespole kierowanym przez Menedżera man1
    man2.getInfo();
    cout << "Pensja miesięczna: " << man2.getMonthSalary() << endl;
    man2.getTeamInfo(); //Lista pracowników w zespole kierowanym przez Menedżera man2
    cout << "Aktualna liczba pracowników:\n";
    cout << "Managers: " << Manager::getNumManagers() << ", OfficeWorkers: " << OfficeWorker::getNumOfficeWorkers() << endl;

    return 0;
}