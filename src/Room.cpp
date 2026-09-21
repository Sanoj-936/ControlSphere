#include "../include/Room.h"
#include "../include/DeviceIds.h"
#include <iostream>
#include <memory>
using namespace std;
Room::Room(int id, string name)
{
    roomId = id;
    roomName = name;

    deviceManager.addDevice(
        make_unique<Light>(
            DeviceIds::LIGHT,
            name + " Light"));

    deviceManager.addDevice(
        make_unique<Fan>(
            DeviceIds::FAN,
            name + " Fan"));

    deviceManager.addDevice(
        make_unique<AC>(
            DeviceIds::AC,
            name + " AC"));

    deviceManager.addDevice(
        make_unique<Camera>(
            DeviceIds::CAMERA,
            name +
                " Camera"));

    deviceManager.addDevice(
        make_unique<DoorLock>(
            DeviceIds::MAIN_DOOR,
            name + " Door Lock"));
    deviceManager.turnOnDevice(DeviceIds::CAMERA);
}
int Room::getRoomId()
{
    return roomId;
}
string Room::getRoomName()
{
    return roomName;
}
DeviceManager &Room ::getDeviceManager()
{
    return deviceManager;
}
void Room::displayRoom()
{
    cout << "\n===== ROOM =====" << endl;

    cout << "Room ID: "
         << roomId << endl;

    cout << "Room Name: "
         << roomName << endl;

    deviceManager.listDevices();
}