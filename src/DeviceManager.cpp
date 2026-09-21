#include "../include/DeviceManager.h"
#include <iostream>

using namespace std;

void DeviceManager::addDevice(unique_ptr<SmartDevice> device)
{
    // Check if device already exists
    if (findDevice(device->getDeviceId()) != nullptr)
    {
        cout << "Device with ID "
             << device->getDeviceId()
             << " already exists." << endl;

        return;
    }

    cout << device->getDeviceName()
         << " added successfully." << endl;

    devices.push_back(move(device));
}

void DeviceManager::removeDevice(int deviceId)
{
    for (int i = 0; i < devices.size(); i++)
    {
        if (devices[i]->getDeviceId() == deviceId)
        {
            cout << devices[i]->getDeviceName()
                 << " removed successfully." << endl;

            devices.erase(devices.begin() + i);

            return;
        }
    }

    cout << "Device not found." << endl;
}

SmartDevice *DeviceManager::findDevice(int deviceId)
{
    for (int i = 0; i < devices.size(); i++)
    {
        if (devices[i]->getDeviceId() == deviceId)
        {
            return devices[i].get();
        }
    }

    return nullptr;
}

void DeviceManager::listDevices()
{
    if (devices.empty())
    {
        cout << "No devices available." << endl;
        return;
    }

    cout << "\n===== DEVICES =====" << endl;

    for (int i = 0; i < devices.size(); i++)
    {
        devices[i]->displayStatus();

        cout << "-------------------" << endl;
    }
}

void DeviceManager::turnOnDevice(int deviceId)
{
    SmartDevice *device = findDevice(deviceId);

    if (device == nullptr)
    {
        cout << "Device not found." << endl;
        return;
    }

    device->turnOn();
}

void DeviceManager::turnOffDevice(int deviceId)
{
    SmartDevice *device = findDevice(deviceId);

    if (device == nullptr)
    {
        cout << "Device not found." << endl;
        return;
    }

    device->turnOff();
}