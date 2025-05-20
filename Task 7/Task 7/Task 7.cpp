#include <iostream>
#include "FitnessBand.h"
#include "Smartwatch.h"
using namespace std;

int main()
{
    FitnessBand band1;
    band1.monitor_activity();
    band1.monitor_activity();
    cout << "Liczba kroków: " << band1.get_step_count() << " " << endl;
    cout << "Pełna informacja:\n";
    band1.getInfo();
    cout << "Resetowanie licznika ...\n";
    band1.reset();
    cout << "Eksploracja z opaską " << band1.getModel() << " na poziomie 5000 kroków ...\n";
    for (int i = 1; i <= 5000; ++i)
        band1.monitor_activity();
    cout << "Pełna informacja:\n";
    band1.getInfo();

    cout << endl;
    Smartwatch watch1;
    watch1.monitor_activity();
    watch1.monitor_activity();
    watch1.monitor_activity();
    cout << "Liczba kroków: " << watch1.get_step_count() << endl;
    cout << "Dystans: " << watch1.get_distance_m() << " m" << endl;
    cout << "Pełna informacja:\n";
    watch1.getInfo();
    cout << "Resetowanie liczników ...\n";
    watch1.reset();
    cout << "Eksploracja ze smartwatchem " << watch1.getModel() << " na poziomie 8000 kroków ...\n";
    for (int i = 1; i <= 8000; ++i)
        watch1.monitor_activity();
    cout << "Pełna informacja:\n";
    watch1.getInfo();
    cout << endl;
    FitnessBand band2("Mi Band 9");
    band2.monitor_activity();
    band2.monitor_activity();
    cout << "Liczba kroków: " << band2.get_step_count() << " " << endl;
    cout << "Pełna informacja:\n";
    band2.getInfo();
    cout << "Resetowanie licznika ...\n";
    band2.reset();
    cout << "Eksploracja z opaską " << band2.getModel() << " na poziomie 9000 kroków ...\n";
    for (int i = 1; i <= 9000; ++i)
        band2.monitor_activity();
    cout << "Pełna informacja:\n";
    band2.getInfo();

    cout << endl;
    Smartwatch watch2("Watch Series 10");
    watch2.monitor_activity();
    watch2.monitor_activity();
    watch2.monitor_activity();
    cout << "Liczba kroków: " << watch2.get_step_count() << endl;
    cout << "Dystans: " << watch2.get_distance_m() << " m" << endl;
    cout << "Pełna informacja:\n";
    watch2.getInfo();
    cout << "Resetowanie liczników ...\n";
    watch2.reset();
    cout << "Eksploracja ze smartwatchem " << watch2.getModel() << " na poziomie 10000 kroków ...\n";
    for (int i = 1; i <= 10000; ++i)
        watch2.monitor_activity();
    cout << "Pełna informacja:\n";
    watch2.getInfo();
    cout << "Ładowanie urządzenia " << watch2.getModel() << " w ciągu 15 minut ...\n";
    watch2.charge(15);
    cout << "Poziom baterii: " << watch2.get_battery_level() << "%\n";

    cout << endl;
    Smartwatch watch3("Galaxy Watch 7", 75);
    watch3.monitor_activity();
    watch3.monitor_activity();
    watch3.monitor_activity();
    cout << "Liczba kroków: " << watch3.get_step_count() << endl;
    cout << "Dystans: " << watch3.get_distance_m() << " m" << endl;
    cout << "Pełna informacja:\n";
    watch3.getInfo();
    cout << "Resetowanie liczników ...\n";
    watch3.reset();
    cout << "Eksploracja ze smartwatchem " << watch3.getModel() << " na poziomie 70000 kroków ...\n";
    for (int i = 1; i <= 70000; ++i)
        watch3.monitor_activity();
    cout << "Pełna informacja:\n";
    watch3.getInfo();
    cout << "Ładowanie urządzenia " << watch3.getModel() << " w ciągu 30 minut ...\n";
    watch3.charge(30);
    cout << "Poziom baterii: " << watch3.get_battery_level() << "%\n";
    cout << "Eksploracja ze smartwatchem " << watch3.getModel() << " na poziomie 50000 kroków ...\n";
    for (int i = 1; i <= 50000; ++i)
        watch3.monitor_activity();
    cout << "Pełna informacja:\n";
    watch3.getInfo();
    cout << "Ładowanie urządzenia " << watch3.getModel() << " w ciągu 120 minut ...\n";
    watch3.charge(120);
    cout << "Poziom baterii: " << watch3.get_battery_level() << "%\n";

    return 0;
}