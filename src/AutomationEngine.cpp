#include "../include/AutomationEngine.h"
#include "../include/Light.h"
#include "../include/Fan.h"
#include "../include/AC.h"
#include "../include/DoorLock.h"
#include "../include/DeviceIds.h"
#include <iostream>
using namespace std;
AutomationEngine::AutomationEngine(
    Room &livingRoom,
    Room &bedroom,
    SecuritySystem &securitySystem)
    : livingRoom(livingRoom),
      bedroom(bedroom),
      securitySystem(securitySystem)
{
}
// cmera will always keep as it is , in any mode;
void AutomationEngine::goodNight()
{
    cout << "\n===== GOOD NIGHT MODE =====\n";
    DeviceManager &livingManager = livingRoom.getDeviceManager();
    DeviceManager &bedroomManager = bedroom.getDeviceManager();

    // Turn off living room devices
    livingManager.turnOffDevice(DeviceIds::LIGHT);
    livingManager.turnOffDevice(DeviceIds::FAN);
    livingManager.turnOffDevice(DeviceIds::AC);

    // Turn off bedroom devices
    bedroomManager.turnOffDevice(DeviceIds::LIGHT);

    // Lock main door

    SmartDevice *door = livingManager.findDevice(DeviceIds::MAIN_DOOR);

    if (door != nullptr)
    {
        // Try to convert this SmartDevice* into a DoorLock*.
        DoorLock *doorLock = dynamic_cast<DoorLock *>(door);
        if (doorLock != nullptr)
        {
            doorLock->lock();
        }
    }
    // Arm security;
    securitySystem.arm();
    cout << "Good Night mode activated."
         << endl;
}

void AutomationEngine::goodMorning()
{
    cout << "\n===== GOOD MORNING MODE =====\n";
    livingRoom.getDeviceManager().turnOnDevice(DeviceIds::FAN);
    livingRoom.getDeviceManager().turnOnDevice(DeviceIds::AC);
    SmartDevice *ac = bedroom.getDeviceManager().findDevice(DeviceIds::AC);
    if (ac != nullptr)
    {
        AC *airConditionor = dynamic_cast<AC *>(ac);
        if (airConditionor != nullptr)
        {
            airConditionor->setTemperature(24);
        }
    }
    SmartDevice *door = livingRoom.getDeviceManager().findDevice(DeviceIds::MAIN_DOOR);
    if (door != nullptr)
    {
        DoorLock *doorLock = dynamic_cast<DoorLock *>(door);
        if (doorLock != nullptr)
        {
            doorLock->unlock();
        }
    }
    securitySystem.disarm();
    cout << "Good Morning mode activated."
         << endl;
}

void AutomationEngine::leavingHome()
{
    cout << "\n===== LEAVING HOME MODE =====\n";
    livingRoom.getDeviceManager().turnOffDevice(DeviceIds::LIGHT);
    livingRoom.getDeviceManager().turnOffDevice(DeviceIds::FAN);
    livingRoom.getDeviceManager().turnOffDevice(DeviceIds::AC);
    bedroom.getDeviceManager().turnOffDevice(DeviceIds::LIGHT);
    bedroom.getDeviceManager().turnOffDevice(DeviceIds::FAN);
    bedroom.getDeviceManager().turnOffDevice(DeviceIds::AC);

    SmartDevice *door =
        livingRoom.getDeviceManager().findDevice(DeviceIds::MAIN_DOOR);

    if (door != nullptr)
    {

        DoorLock *doorLock =
            dynamic_cast<DoorLock *>(door);

        if (doorLock != nullptr)
        {

            doorLock->lock();
        }
    }

    securitySystem.arm();

    cout << "Leaving Home mode activated."
         << endl;
}

void AutomationEngine::movieMode()
{

    cout << "\n===== MOVIE MODE =====\n";

    SmartDevice *device =
        livingRoom.getDeviceManager().findDevice(DeviceIds::LIGHT);

    if (device != nullptr)
    {

        Light *light =
            dynamic_cast<Light *>(device);

        if (light != nullptr)
        {

            light->setBrightness(30);
        }
    }

    cout << "Movie mode activated."
         << endl;
}