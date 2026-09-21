#ifndef FAN_H
#define FAN_H

#include "SmartDevice.h"

class Fan : public SmartDevice
{

private:
    int speed;

public:
    Fan(int id, string name);

    void setSpeed(int speed);
    void getSpeed();
    void turnOn() override;
    void turnOff() override;
    string getDeviceType() const override;
};

#endif