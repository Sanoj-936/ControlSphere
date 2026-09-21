#include "../include/AuthenticationSystem.h"
#include <iostream>

using namespace std;
AuthenticationSystem::AuthenticationSystem()
    : currentUser(nullptr)
{

    initializeAdmin();
}
void AuthenticationSystem::initializeAdmin()
{

    string adminEmail = "admin@smarthome.com";

    string adminPassword = "admin123";

    string adminName = "System Admin";

    users.emplace(
        adminEmail,
        User(
            adminEmail,
            adminPassword,
            adminName,
            Role::ADMIN));
}
bool AuthenticationSystem::createUser(
    const string &email,
    const string &password,
    const string &name,
    Role role)
{

    // Security check

    if (!isAdmin())
    {

        cout << "\nAccess denied."
             << endl;

        cout << "Only ADMIN can create accounts."
             << endl;

        return false;
    }

    // Check duplicate email

    if (users.find(email) != users.end())
    {

        cout << "\nAccount already exists for "
             << email
             << "." << endl;

        return false;
    }
    users.emplace(
        email,
        User(
            email,
            password,
            name,
            role));

    cout << "\nAccount created successfully by ADMIN."
         << endl;

    return true;
}
bool AuthenticationSystem::isAdmin() const
{

    if (currentUser == nullptr)
    {

        return false;
    }

    return currentUser->isAdmin();
}
bool AuthenticationSystem::login(
    const string &email,
    const string &password)
{

    auto it = users.find(email);

    if (it == users.end())
    {

        cout << "\nAccount not found."
             << endl;

        return false;
    }

    User &user = it->second;

    if (!user.checkPassword(password))
    {

        cout << "\nIncorrect password."
             << endl;

        return false;
    }

    if (user.isLoggedIn())
    {

        cout << "\nUser is already logged in."
             << endl;

        currentUser = &user;

        return true;
    }

    user.login();

    currentUser = &user;

    cout << "\nLogin successful!"
         << endl;

    cout << "Welcome, "
         << user.getName()
         << "!" << endl;

    return true;
}
void AuthenticationSystem::logout()

{

    if (currentUser == nullptr)
    {

        cout << "\nNo user is currently logged in."
             << endl;

        return;
    }

    cout << "\n"
         << currentUser->getName()
         << " logged out successfully."
         << endl;

    currentUser->logout();

    currentUser = nullptr;
}

bool AuthenticationSystem::deleteUser(
    const string &email)
{

    if (!isAdmin())
    {

        cout << "Access denied. Admin only."
             << endl;

        return false;
    }
    if ((email == "admin@smarthome.com") && (currentUser->getEmail() != "admin@smarthome.com"))
    {
        cout << "You CAN NOT delete Superident-Admin" << endl;
        return false;
    }
    auto it = users.find(email);

    if (it == users.end())
    {

        cout << "User not found."
             << endl;

        return false;
    }
    // admin can not deleted itself
    if (currentUser == &it->second)
    {

        cout << "You cannot delete the currently logged-in account."
             << endl;

        return false;
    }

    users.erase(it);

    cout << "User deleted successfully."
         << endl;

    return true;
}
bool AuthenticationSystem::userExists(
    const string &email) const
{
    return users.find(email) != users.end();
}
void AuthenticationSystem::userStatus(const string &email) const
{
    auto it = users.find(email);
    if (it != users.end())
    {
        cout << "USER EXISTS." << endl;
        User user = it->second;
        cout << "Name: " << user.getName() << endl;
        if (user.getRole() == Role::ADMIN)
        {
            cout << "Role: " << "Admin" << endl;
        }
        else
        {
            cout << "Role: " << "User" << endl;
        }
    }
    else
    {
        cout << "USER NOT EXISTS." << endl;
    }
}
bool AuthenticationSystem::isLoggedIn() const
{

    return currentUser != nullptr;
}

User *AuthenticationSystem::getCurrentUser() const
{

    return currentUser;
}
void AuthenticationSystem::listUsers() const
{
    if (!isAdmin())
    {

        cout << "Access denied. Admin only."
             << endl;

        return;
    }
    cout << "\n===== REGISTERED USERS =====\n";

    for (const auto u : users)
    {
        User user = u.second;
        cout << "Name: "
             << user.getName()
             << endl;

        cout << "Email: "
             << user.getEmail()
             << endl;

        cout << "Role: ";

        if (user.getRole() == Role::ADMIN)
        {
            cout << "ADMIN";
        }
        else
        {
            cout << "USER";
        }

        cout << endl;

        cout << "---------------------------\n";
    }
}