#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "AuthenticationSystem.h"
#include "Room.h"
#include "SecuritySystem.h"
#include "AutomationEngine.h"
#include "DeviceManager.h"
class AdminMenu
{
private:
    // use existing things not own created so use refernce;
    AuthenticationSystem &auth;
    Room &livingRoom;
    Room &bedroom;
    SecuritySystem &securitySystem;
    AutomationEngine &automation;
    void automationMenu();
    void userManagementMenu();

public:
    AdminMenu(
        AuthenticationSystem &auth,
        Room &livingRoom,
        Room &bedroom,
        SecuritySystem &securitySystem,
        AutomationEngine &automation);

    void show();
    void createNewUser();
    void deleteUser();
    void isUserExits();
    void controlDevice();

};
#endif