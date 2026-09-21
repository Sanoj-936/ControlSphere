#include "../include/Light.h"
#include <iostream>

using namespace std;

Light::Light(int id, string name)
    : SmartDevice(id, name)
{

    brightness = 50;
}

void Light::setBrightness(int level)
{

    if (level < 0 || level > 100)
    {
        cout << "Brightness must be between 0 and 100." << endl;
        return;
    }

    brightness = level;

    if (brightness == 0)
    {
        turnOff();
        return;
    }

    cout << "Brightness set to "
         << brightness << "%." << endl;
}

void Light::turnOn()
{

    SmartDevice::turnOn();

    cout << "Light brightness: "
         << brightness << "%" << endl;
}

void Light::turnOff()
{

    SmartDevice::turnOff();
}
void Light::getBrightness()
{
    cout << "Light brightness: "
         << brightness << "%" << endl;
}
string Light::getDeviceType() const
{
    return "Light";
}