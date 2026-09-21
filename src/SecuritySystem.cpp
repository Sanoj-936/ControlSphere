#include "../include/SecuritySystem.h"
#include <iostream>
using namespace std;

SecuritySystem::SecuritySystem()
{
    armed = false;
}
void SecuritySystem::arm()
{
    if (armed)
    {

        cout << "Security system is already armed."
             << endl;

        return;
    }

    armed = true;

    cout << "Security system ARMED."
         << endl;
}

void SecuritySystem::disarm()
{

    if (!armed)
    {

        cout << "Security system is already disarmed."
             << endl;

        return;
    }

    armed = false;

    cout << "Security system DISARMED."
         << endl;
}
bool SecuritySystem::isArmed() const
{
    return armed;
}
void SecuritySystem::status()
{

    cout << "Security Status: "
         << (armed ? "ARMED" : "DISARMED")
         << endl;
}
