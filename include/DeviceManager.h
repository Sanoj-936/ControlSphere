#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H
#include <vector>
#include <memory>
#include "SmartDevice.h"
using namespace std;
class DeviceManager
{
private:
    vector<unique_ptr<SmartDevice>> devices;

public:
    void addDevice(unique_ptr<SmartDevice> device);
    void removeDevice(int deviceId);
    SmartDevice *findDevice(int deviceId);
    void listDevices();
    void turnOnDevice(int deviceId);
    void turnOffDevice(int deviceId);
};

#endif