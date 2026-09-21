#ifndef ROOM_H
#define ROOM_H
#include <string>
#include "DeviceManager.h"
#include "Fan.h"
#include "Light.h"
#include "AC.h"
#include "Camera.h"
#include "DoorLock.h"
using namespace std;
class Room
{
private:
    int roomId;
    string roomName;
    DeviceManager deviceManager;

public:
    Room(int id, string name);
    int getRoomId();
    string getRoomName();
    DeviceManager &getDeviceManager();
    void displayRoom();
};
#endif
