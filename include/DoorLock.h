#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"

class DoorLock : public SmartDevice
{

private:
    bool locked;

public:
    DoorLock(int id, string name);

    void lock();
    void unlock();

    void turnOn() override;
    void turnOff() override;
    string getDeviceType() const override;
};

#endif