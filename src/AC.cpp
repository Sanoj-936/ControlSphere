#include "../include/AC.h"
#include <iostream>
using namespace std;
AC::AC(int id, string name) : SmartDevice(id, name)
{
    temperature = 24;
}
void AC::getTemperature()
{
    cout << "AC temperature: "
         << temperature << " C" << endl;
}
void AC::setTemperature(int temperature)
{
    if (temperature < 16 || temperature > 30)
    {
        cout << "Temperature must be between 16 and 30 Celsius." << endl;
        return;
    }

    this->temperature = temperature;

    cout << "AC temperature set to "
         << temperature << " C." << endl;
}
void AC::turnOn()
{
    SmartDevice::turnOn();
    cout << "AC temperature: "
         << temperature << " C" << endl;
}
void AC::turnOff()
{

    SmartDevice::turnOff();
}
string AC::getDeviceType() const
{
    return "AC";
}