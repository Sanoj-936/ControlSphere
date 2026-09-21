#ifndef AC_H
#define AC_H
#include "SmartDevice.h"
class AC : public SmartDevice
{
private:
    int temperature;

public:
    AC(int id, string name);
    void turnOn() override;
    void turnOff() override;
    void setTemperature(int temperature);
    void getTemperature();
    string getDeviceType() const override;
};

#endif