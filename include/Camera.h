#ifndef CAMERA_H
#define CAMERA_H
#include "SmartDevice.h"
class Camera : public SmartDevice
{
private:
    bool recording;

public:
    Camera(int id, string name);
    void startRecording();
    void stopRecording();
    void turnOn() override;
    void turnOff() override;
    string getDeviceType() const override;
};

#endif