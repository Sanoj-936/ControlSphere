#include "../include/SmartDevice.h"
#include <iostream>

using namespace std;

SmartDevice::SmartDevice(int id, string name)
{
    deviceId = id;
    deviceName = name;
    isOn = false;
}

void SmartDevice::turnOn()
{
    isOn = true;
    cout << deviceName << " is turned ON." << endl;
}

void SmartDevice::turnOff()
{
    isOn = false;
    cout << deviceName << " is turned OFF." << endl;
}

void SmartDevice::displayStatus()
{
    cout << "Device ID: " << deviceId << endl;
    cout << "Device Name: " << deviceName << endl;
    cout << "Status: " << (isOn ? "ON" : "OFF") << endl;
}

int SmartDevice::getDeviceId()
{
    return deviceId;
}

string SmartDevice::getDeviceName()
{
    return deviceName;
}

bool SmartDevice::getPowerStatus()
{
    return isOn;
}