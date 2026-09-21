#include "../include/User.h"
#include <iostream>
using namespace std;
User::User(
    string email,
    string password,
    string name,
    Role role)
    : email(email),
      password(password),
      name(name),
      role(role),
      loggedIn(false)
{
}
string User::getEmail() const
{

    return email;
}
string User::getName() const
{
    return name;
}
Role User::getRole() const
{
    return role;
}
bool User::checkPassword(
    const string &inputPassword) const
{
    return password == inputPassword;
}
bool User::isLoggedIn() const
{

    return loggedIn;
}

void User::login()
{

    loggedIn = true;
}

void User::logout()
{

    loggedIn = false;
}
bool User::isAdmin() const
{
    return role == Role::ADMIN;
}

