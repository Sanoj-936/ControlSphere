#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

using namespace std;

class SmartDevice
{

private:
    int deviceId;
    string deviceName;
    bool isOn;

public:
    SmartDevice(int id, string name);

    virtual void turnOn();
    virtual void turnOff();

    void displayStatus();
    virtual string getDeviceType() const = 0;
    int getDeviceId();
    string getDeviceName();
    bool getPowerStatus();

    virtual ~SmartDevice() = default;
};

#endif