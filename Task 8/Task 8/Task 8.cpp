#include <iostream>
using namespace std;

class PublicDevice {
    string location;
    unsigned int id;
public:
    PublicDevice();
    PublicDevice(string location, unsigned int id);
    ~PublicDevice();
    void setLocation(string location);
    void setId(unsigned int id);
    string getLocation() const;
    unsigned int getId() const;
    virtual void getInfo() const;
};

class ATM : public PublicDevice {
    string bank;
protected:
    unsigned int cashState;
public:
    ATM();
    ATM(string location, unsigned int id, string bank, unsigned int cashState);
    ~ATM();
    void setBank(string bank);
    void setCashState(unsigned int cashState);
    string getBank() const;
    unsigned int getCashState() const;
    unsigned int getCash();
    unsigned int getCash(unsigned int cash);
    virtual void getInfo() const override;
};

class CDM : public ATM {
public:
    CDM();
    CDM(string location, unsigned int id, string bank, unsigned int cashState);
    ~CDM();
    unsigned int depositCash();
    unsigned int depositCash(unsigned int cash);
};

int main() {
    cout << "--- TEST 1: PublicDevice() ---\n";
    PublicDevice* dev1 = new PublicDevice();
    dev1->setLocation("TestCity1");
    dev1->setId(10);
    cout << "Location: " << dev1->getLocation() << ", ID: " << dev1->getId() << endl;
    dev1->getInfo();
    cout << endl;

    cout << "\n--- TEST 2: PublicDevice(string, unsigned int) ---\n";
    PublicDevice* dev2 = new PublicDevice("TestCity2", 34);
    cout << "Location: " << dev2->getLocation() << ", ID: " << dev2->getId() << endl;
    dev2->getInfo();
    cout << endl;

    cout << "\n--- TEST 3: ATM() ---\n";
    ATM* atm1 = new ATM();
    atm1->setLocation("ATM City");
    atm1->setId(45);
    atm1->setBank("BankX");
    atm1->setCashState(76000);
    cout << "Location: " << atm1->getLocation()
        << ", ID: " << atm1->getId()
        << ", Bank: " << atm1->getBank()
        << ", CashState: " << atm1->getCashState() << endl;
    cout << "getCash(): " << atm1->getCash() << endl;
    cout << "getCash(1000): " << atm1->getCash(1000) << endl;
    atm1->getInfo();
    cout << endl;

    cout << "\n--- TEST 4: ATM(string, unsigned int, string, unsigned int) ---\n";
    ATM* atm2 = new ATM("ATM City 2", 57, "BankY", 4780);
    atm2->getInfo();
    cout << endl;

    cout << "\n--- TEST 5: CDM() ---\n";
    CDM* cdm1 = new CDM();
    cdm1->setLocation("CDM City");
    cdm1->setId(67);
    cdm1->setBank("BankZ");
    cdm1->setCashState(50700);
    cout << "Deposit 50: " << cdm1->depositCash() << endl;
    cout << "Deposit 7430: " << cdm1->depositCash(7430) << endl;
    cdm1->getInfo();
    cout << endl;

    cout << "\n--- TEST 6: CDM(string, unsigned int, string, unsigned int) ---\n";
    CDM* cdm2 = new CDM("CDM City 2", 78, "BankA", 10000);
    cout << "Deposit 50: " << cdm2->depositCash() << endl;
    cout << "Deposit 15000 (powinno nie zadzia?a?): " << cdm2->depositCash(15000) << endl;
    cdm2->getInfo();
    cout << endl;

    cout << "\n--- TEST POLIMORFIZMU ---\n";
    const int SIZE = 6;
    PublicDevice* devices[SIZE];
    devices[0] = dev1;
    devices[1] = dev2;
    devices[2] = atm1;
    devices[3] = atm2;
    devices[4] = cdm1;
    devices[5] = cdm2;

    for (int i = 0; i < SIZE; ++i) {
        cout << "PublicDevice[" << i << "]: ";
        devices[i]->getInfo();
        cout << endl;
    }

    cout << "\n--- ZWALNIANIE PAMI?CI ---\n";
    for (int i = 0; i < SIZE; ++i) {
        delete devices[i];
    }

    return 0;
}

PublicDevice::PublicDevice() : location("unknown"), id(0) {
    cout << "PublicDevice()\n";
}

PublicDevice::PublicDevice(string location, unsigned int id) : location(location), id(id) {
    cout << "PublicDevice(string location, unsigned int id)\n";
}

PublicDevice::~PublicDevice() {
    location = "";
    id = 0;
    cout << "~PublicDevice()\n";
}

void PublicDevice::setLocation(string location) {
    this->location = location;
}

void PublicDevice::setId(unsigned int id) {
    this->id = id;
}

string PublicDevice::getLocation() const {
    return location;
}

unsigned int PublicDevice::getId() const {
    return id;
}

void PublicDevice::getInfo() const {
    cout << id << ", " << location;
}

ATM::ATM() : PublicDevice(), bank("unknown"), cashState(0) {
    cout << "ATM()\n";
}

ATM::ATM(string location, unsigned int id, string bank, unsigned int cashState)
    : PublicDevice(location, id), bank(bank), cashState(cashState) {
    cout << "ATM(string location, unsigned int id, string bank, unsigned int cashState)\n";
}

ATM::~ATM() {
    bank = "";
    cashState = 0;
    cout << "~ATM()\n";
}

void ATM::setBank(string bank) {
    this->bank = bank;
}

void ATM::setCashState(unsigned int cashState) {
    this->cashState = cashState;
}

string ATM::getBank() const {
    return bank;
}

unsigned int ATM::getCashState() const {
    return cashState;
}

unsigned int ATM::getCash() {
    if (cashState >= 50) {
        cashState -= 50;
        return 50;
    }
    return 0;
}

unsigned int ATM::getCash(unsigned int cash) {
    if (cash <= cashState && cash <= 10000) {
        cashState -= cash;
        return cash;
    }
    return 0;
}

void ATM::getInfo() const {
    PublicDevice::getInfo();
    cout << ", " << bank << ", " << cashState;
}

CDM::CDM() : ATM() {
    cout << "CDM()\n";
}

CDM::CDM(string location, unsigned int id, string bank, unsigned int cashState)
    : ATM(location, id, bank, cashState) {
    cout << "CDM(string location, unsigned int id, string bank, unsigned int cashState)\n";
}

CDM::~CDM() {
    cout << "~CDM()\n";
}

unsigned int CDM::depositCash() {
    if (cashState <= 99950) {
        cashState += 50;
        return 50;
    }
    return 0;
}

unsigned int CDM::depositCash(unsigned int cash) {
    if (cash <= 100000 - cashState && cash <= 10000) {
        cashState += cash;
        return cash;
    }
    return 0;
}
