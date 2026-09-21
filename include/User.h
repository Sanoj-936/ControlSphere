#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
#include "Role.h"

using namespace std;
class User
{
private:
    string email; // unique , so no need for unique Id
    string password;
    string name;
    Role role;
    bool loggedIn;

public:
    User(
        string email,
        string password,
        string name,
        Role role);
    string getEmail() const;
    string getName() const;
    Role getRole() const;
    bool checkPassword(const string &password) const;
    bool isLoggedIn() const;
    void login();
    void logout();
    bool isAdmin() const;
};
#endif