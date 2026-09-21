#ifndef AUTHENTICATIONSYSTEM_H
#define AUTHENTICATIONSYSTEM_H
#include <string>
#include <unordered_map>
#include "User.h"
using namespace std;
class AuthenticationSystem
{
private:
    // email->User;
    unordered_map<string, User> users;
    User *currentUser;
    void initializeAdmin();

public:
    AuthenticationSystem();
    bool createUser(
        const string &email,
        const string &password,
        const string &name,
        Role role);
    bool login(const string &email, const string &password);
    void logout();
    User *getCurrentUser() const;
    bool isLoggedIn() const;
    bool userExists(const string &email) const;
    bool deleteUser(const string &email);
    // bool modifyUser(const string &email, const string &newPassword);
    void listUsers() const;
    bool isAdmin() const;
    void userStatus(const string &email) const;
};
#endif