#include "../include/Camera.h"
#include <iostream>

Camera::Camera(int id, string name) : SmartDevice(id, name)
{
    recording = false;
}
void Camera::startRecording()
{
    // first check device is on or off then proccede;
    if (!getPowerStatus())
    {
        cout << "Camera is OFF. Turn it ON first." << endl;
        return;
    }

    recording = true;

    cout << "Camera started recording." << endl;
}
void Camera::stopRecording()
{

    recording = false;

    cout << "Camera stopped recording." << endl;
}
void Camera::turnOn()
{

    SmartDevice::turnOn();

    cout << "Camera is ready." << endl;
}

void Camera::turnOff()
{

    stopRecording();

    SmartDevice::turnOff();
}
string Camera::getDeviceType() const
{
    return "Camera";
}