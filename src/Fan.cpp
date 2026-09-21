#include "../include/Fan.h"
#include <iostream>
using namespace std;
Fan::Fan(int id, string name) : SmartDevice(id, name)
{
    speed = 1;
}
void Fan::getSpeed()
{
    cout << "Fan speed: "
         << speed << endl;
}
void Fan::setSpeed(int speed)
{
    if (speed < 1 || speed > 3)
    {
        cout << "Fan speed must be between 1 and 3." << endl;
        return;
    }
    this->speed = speed;
    cout << "Fan speed set to "
         << speed << endl;
}
void Fan::turnOn()
{
    SmartDevice::turnOn();
    cout << "Fan speed: "
         << speed << endl;
}
void Fan::turnOff()
{

    SmartDevice::turnOff();
}

string Fan::getDeviceType() const
{
    return "Fan";
}
