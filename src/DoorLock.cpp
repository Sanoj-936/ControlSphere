#include "../include/DoorLock.h"
#include <iostream>

using namespace std;

DoorLock::DoorLock(int id, string name)
    : SmartDevice(id, name)
{

    locked = true;
}

void DoorLock::lock()
{

    locked = true;

    cout << "Door locked." << endl;
}

void DoorLock::unlock()
{

    locked = false;

    cout << "Door unlocked." << endl;
}

void DoorLock::turnOn()
{

    SmartDevice::turnOn();

    lock();
}

void DoorLock::turnOff()
{

    unlock();

    SmartDevice::turnOff();
}
string DoorLock::getDeviceType() const
{
    return "DoorLock";
}