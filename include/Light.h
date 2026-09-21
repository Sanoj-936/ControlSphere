#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"

class Light : public SmartDevice
{

private:
    int brightness;

public:
    Light(int id, string name);

    void setBrightness(int level);
    void turnOn() override;
    void turnOff() override;
    void getBrightness();
    string getDeviceType() const override;
};

#endif