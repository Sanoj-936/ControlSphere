#include "../include/AdminMenu.h"
#include <iostream>
using namespace std;
AdminMenu::AdminMenu(
    AuthenticationSystem &auth,
    Room &livingRoom,
    Room &bedroom,
    SecuritySystem &securitySystem,
    AutomationEngine &automation)
    : auth(auth),
      livingRoom(livingRoom),
      bedroom(bedroom),
      securitySystem(securitySystem),
      automation(automation) {}

void AdminMenu::show()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "=================================\n";
        cout << "         ADMIN DASHBOARD\n";
        cout << "=================================\n";

        cout << "1. Control & View Devices\n";
        cout << "2. Automation\n";
        cout << "3. Security Status\n";
        cout << "4. Manage Users\n";
        cout << "5. Logout\n";

        cout << "\nEnter choice: ";

        cin >> choice;

        // Handle non-numeric input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "\nInvalid input. Please enter a number.\n";

            continue;
        }

        switch (choice)
        {
        case 1:

            controlDevice();

            break;

        case 2:

            automationMenu();

            break;

        case 3:

            securitySystem.status();

            break;

        case 4:

            userManagementMenu();

            break;

        case 5:

            auth.logout();

            break;

        default:

            cout << "\nInvalid choice. Please enter 1-5.\n";
        }

    } while (auth.isLoggedIn());
}
void AdminMenu::automationMenu()
{

    int choice;

    cout << "\n";
    cout << "========== AUTOMATION ==========\n";

    cout << "1. Good Morning\n";
    cout << "2. Good Night\n";
    cout << "3. Leaving Home\n";
    cout << "4. Movie Mode\n";
    cout << "5. Back\n";

    cout << "\nEnter choice: ";

    cin >> choice;

    switch (choice)
    {

    case 1:

        automation.goodMorning();

        break;

    case 2:

        automation.goodNight();

        break;

    case 3:

        automation.leavingHome();

        break;

    case 4:

        automation.movieMode();

        break;

    case 5:

        return;

    default:

        cout << "Invalid choice.\n";
    }
}
void AdminMenu::userManagementMenu()
{

    int choice;

    do
    {

        cout << "\n";
        cout << "========== USER MANAGEMENT ==========\n";

        cout << "1. List Users\n";
        cout << "2. Create User\n";
        cout << "3. Delete User\n";
        cout << "4. User Exist?\n";
        cout << "5. Back\n";

        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice)
        {

        case 1:

            auth.listUsers();

            break;

        case 2:
            createNewUser();

            break;
        case 3:
            deleteUser();

            break;
        case 4:
            isUserExits();
            break;
        case 5:

            return;

        default:

            cout << "Invalid choice.\n";
            return;
        }

    } while (true);
}

void AdminMenu::createNewUser()
{

    string name;
    string email;
    string password;

    int roleChoice;

    cout << "\nName: ";
    cin >> name;

    cout << "Email: ";
    cin >> email;

    cout << "Password: ";
    cin >> password;

    cout << "\nSelect Role:\n";
    cout << "1. USER\n";
    cout << "2. ADMIN\n";

    cout << "Choice: ";
    cin >> roleChoice;

    Role role;

    if (roleChoice == 1)
    {

        role = Role::USER;
    }
    else if (roleChoice == 2)
    {

        role = Role::ADMIN;
    }
    else
    {

        cout << "Invalid role.\n";

        return;
    }

    auth.createUser(
        email,
        password,
        name,
        role);
}
void AdminMenu::deleteUser()
{

    string email;

    cout << "\nUser email: ";

    cin >> email;

    auth.deleteUser(email);
}
void AdminMenu::isUserExits()
{
    string email;

    cout << "\nUser email: ";

    cin >> email;

    auth.userStatus(email);
}

void AdminMenu::controlDevice()
{
    int roomChoice;
    int deviceChoice;
    int actionChoice;

    cout << "\n===== DEVICE CONTROL =====\n";

    cout << "1. Living Room\n";
    cout << "2. Bedroom\n";
    cout << "3. Back\n";

    cout << "\nSelect Room: ";
    cin >> roomChoice;
    if (roomChoice == 3)
        return;

    if (roomChoice != 1 && roomChoice != 2)
    {
        cout << "Invalid room." << endl;
        return;
    }
    // =========================
    // DISPLAY SELECTED ROOM
    // =========================

    if (roomChoice == 1)
    {
        livingRoom.displayRoom();
    }
    else
    {
        bedroom.displayRoom();
    }

    cout << endl;
    cout << "\n===== DEVICES SELECTION =====\n";

    cout << "1. Light\n";
    cout << "2. Fan\n";
    cout << "3. AC\n";
    cout << "4. Camera\n";
    cout << "5. Door Lock\n";
    cout << "6. Back\n";

    cout << "\nSelect Device: ";
    cin >> deviceChoice;

    if (deviceChoice == 6)
        return;

    // =========================
    // LIGHT
    // =========================

    if (deviceChoice == 1)
    {
        Light *light = nullptr;

        if (roomChoice == 1)
        {
            light = dynamic_cast<Light *>(
                livingRoom.getDeviceManager().findDevice(1));
        }
        else if (roomChoice == 2)
        {
            light = dynamic_cast<Light *>(
                bedroom.getDeviceManager().findDevice(1));
        }

        if (light == nullptr)
        {
            cout << "Light not found." << endl;
            return;
        }

        cout << "\n===== LIGHT =====\n";

        cout << "1. Turn ON\n";
        cout << "2. Turn OFF\n";
        cout << "3. Set Brightness\n";
        cout << "4. Back\n";

        cout << "\nEnter choice: ";
        cin >> actionChoice;

        if (actionChoice == 1)
        {
            light->turnOn();
        }
        else if (actionChoice == 2)
        {
            light->turnOff();
        }
        else if (actionChoice == 3)
        {
            int brightness;

            cout << "Enter brightness (0-100): ";
            cin >> brightness;

            light->setBrightness(brightness);
        }

        return;
    }
    // =========================
    // FAN
    // =========================

    if (deviceChoice == 2)
    {
        Fan *fan = nullptr;

        if (roomChoice == 1)
        {
            fan = dynamic_cast<Fan *>(
                livingRoom.getDeviceManager().findDevice(2));
        }
        else if (roomChoice == 2)
        {
            fan = dynamic_cast<Fan *>(
                bedroom.getDeviceManager().findDevice(2));
        }

        if (fan == nullptr)
        {
            cout << "Fan not found." << endl;
            return;
        }

        cout << "\n===== FAN =====\n";

        cout << "1. Turn ON\n";
        cout << "2. Turn OFF\n";
        cout << "3. Set Speed\n";
        cout << "4. Back\n";

        cout << "\nEnter choice: ";
        cin >> actionChoice;

        if (actionChoice == 1)
        {
            fan->turnOn();
        }
        else if (actionChoice == 2)
        {
            fan->turnOff();
        }
        else if (actionChoice == 3)
        {
            int speed;

            cout << "Enter speed (1-5): ";
            cin >> speed;

            fan->setSpeed(speed);
        }
        else if (actionChoice == 4)
        {
            return;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        return;
    }

    // =========================
    // AC
    // =========================

    if (deviceChoice == 3)
    {
        AC *ac = nullptr;

        if (roomChoice == 1)
        {
            ac = dynamic_cast<AC *>(
                livingRoom.getDeviceManager().findDevice(3));
        }
        else if (roomChoice == 2)
        {
            ac = dynamic_cast<AC *>(
                bedroom.getDeviceManager().findDevice(3));
        }

        if (ac == nullptr)
        {
            cout << "AC not found." << endl;
            return;
        }

        cout << "\n===== AC CONTROL =====\n";

        cout << "1. Turn ON\n";
        cout << "2. Turn OFF\n";
        cout << "3. Set Temperature\n";
        cout << "4. Back\n";

        cout << "\nEnter choice: ";
        cin >> actionChoice;

        if (actionChoice == 1)
        {
            ac->turnOn();
        }
        else if (actionChoice == 2)
        {
            ac->turnOff();
        }
        else if (actionChoice == 3)
        {
            int temperature;

            cout << "Enter temperature: ";
            cin >> temperature;

            ac->setTemperature(temperature);
        }
        else if (actionChoice == 4)
        {
            return;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        return;
    }
    // =========================
    // CAMERA
    // =========================

    if (deviceChoice == 4)
    {
        Camera *camera = nullptr;

        if (roomChoice == 1)
        {
            camera = dynamic_cast<Camera *>(
                livingRoom.getDeviceManager().findDevice(4));
        }
        else if (roomChoice == 2)
        {
            camera = dynamic_cast<Camera *>(
                bedroom.getDeviceManager().findDevice(4));
        }

        if (camera == nullptr)
        {
            cout << "Camera not found." << endl;
            return;
        }

        cout << "\n===== CAMERA CONTROL =====\n";

        cout << "1. Turn ON\n";
        cout << "2. Turn OFF\n";
        cout << "3. Start Recording\n";
        cout << "4. Stop Recording\n";
        cout << "5. Back\n";

        cout << "\nEnter choice: ";
        cin >> actionChoice;

        if (actionChoice == 1)
        {
            camera->turnOn();
        }
        else if (actionChoice == 2)
        {
            camera->turnOff();
        }
        else if (actionChoice == 3)
        {
            camera->startRecording();
        }
        else if (actionChoice == 4)
        {
            camera->stopRecording();
        }
        else if (actionChoice == 5)
        {
            return;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        return;
    }
    // =========================
    // DOOR LOCK
    // =========================

    if (deviceChoice == 5)
    {
        DoorLock *doorLock = nullptr;

        if (roomChoice == 1)
        {
            doorLock = dynamic_cast<DoorLock *>(
                livingRoom.getDeviceManager().findDevice(5));
        }
        else if (roomChoice == 2)
        {
            doorLock = dynamic_cast<DoorLock *>(
                bedroom.getDeviceManager().findDevice(5));
        }

        if (doorLock == nullptr)
        {
            cout << "Door Lock not found." << endl;
            return;
        }

        cout << "\n===== DOOR LOCK CONTROL =====\n";

        cout << "1. Lock\n";
        cout << "2. Unlock\n";
        cout << "3. Back\n";

        cout << "\nEnter choice: ";
        cin >> actionChoice;

        if (actionChoice == 1)
        {
            doorLock->lock();
        }
        else if (actionChoice == 2)
        {
            doorLock->unlock();
        }
        else if (actionChoice == 3)
        {
            return;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        return;
    }
    cout << "Invalid device." << endl;
}