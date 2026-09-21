

// complete project

#include <iostream>

#include "include/AuthenticationSystem.h"
#include "include/AdminMenu.h"
#include "include/UserMenu.h"

#include "include/Room.h"
#include "include/SecuritySystem.h"
#include "include/AutomationEngine.h"
#include "include/DeviceManager.h"
using namespace std;

int main()
{

    // ======================================
    //
    // WELCOME TO SMART HOME SYSTEM
    //
    // ======================================

    // ======================================
    // DEVICE MANAGER
    // ======================================

    // ======================================
    // SMART HOME OBJECTS
    // ======================================

    Room livingRoom(1, "Living Room");

    Room bedroom(2, "Bedroom");

    SecuritySystem securitySystem;

    AutomationEngine automation(
        livingRoom,
        bedroom,
        securitySystem);

    // ======================================
    // AUTHENTICATION SYSTEM
    // ======================================

    AuthenticationSystem auth;

    // ======================================
    // MENUS
    // ======================================

    AdminMenu adminMenu(
        auth,
        livingRoom,
        bedroom,
        securitySystem,
        automation);

    UserMenu userMenu(
        auth,
        livingRoom,
        bedroom,
        securitySystem,
        automation);

    // ======================================
    // MAIN APPLICATION LOOP
    // ======================================

    int choice;

    while (true)
    {

        cout << "\n";
        cout << "========================================\n";
        cout << "              CONTROLSPHERE             \n";
        cout << "      Smart Home Automation System      \n";
        cout << "========================================\n";

        cout << "1. Login\n";
        cout << "2. Exit\n";

        cout << "\nEnter choice: ";

        cin >> choice;

        // ==================================
        // LOGIN
        // ==================================

        if (choice == 1)
        {

            string email;
            string password;

            cout << "\nEmail: ";

            cin >> email;

            cout << "Password: ";

            cin >> password;

            // Try login

            if (auth.login(email, password))
            {

                // ==========================
                // ADMIN
                // ==========================

                if (auth.isAdmin())
                {

                    adminMenu.show();
                }

                // ==========================
                // NORMAL USER
                // ==========================

                else
                {

                    userMenu.show();
                }
            }
        }

        else if (choice == 2)
        {

            cout << "\nExiting ControlSphere...\n";

            break;
        }

        // ==================================
        // INVALID OPTION
        // ==================================

        else
        {

            cout << "\nInvalid choice.\n";
            break;
        }
    }

    return 0;
}
