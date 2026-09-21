
#ifndef USERMENU_H
#define USERMENU_H

#include "AuthenticationSystem.h"
#include "Room.h"
#include "SecuritySystem.h"
#include "AutomationEngine.h"
#include "DeviceManager.h"
class UserMenu
{

private:
    AuthenticationSystem &auth;

    Room &livingRoom;
    Room &bedroom;
    SecuritySystem &securitySystem;

    AutomationEngine &automation;

    void automationMenu();

public:
    UserMenu(
        AuthenticationSystem &auth,
        Room &livingRoom,
        Room &bedroom,
        SecuritySystem &securitySystem,
        AutomationEngine &automation);

    void show();
    void controlDevice();
};

#endif
