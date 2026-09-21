#ifndef ROLE_H
#define ROLE_H
enum class Role
{

    ADMIN,
    USER
};
#endif

/*
Instead of using strings like:

"admin"
"user"

we use a strongly typed enum:

Role::ADMIN
Role::USER

This prevents accidental values such as:
"admn"
"Admin"
"ADMIN123"
*/