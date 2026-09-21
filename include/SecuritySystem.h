#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H
class SecuritySystem
{
private:
    bool armed;

public:
    SecuritySystem();
    void arm();
    void disarm();
    bool isArmed() const;
    void status();
};
#endif