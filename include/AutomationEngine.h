#ifndef AUTOMATIONENGINE_H
#define AUTOMATIONENGINE_H
#include "Room.h"
#include "SecuritySystem.h"
class AutomationEngine
{
private:
    /*
    Room& livingRoom;
    This means AutomationEngine doesn't own the room.
    It simply works with an existing room.
    That's another example of composition through references.
    */
    Room &livingRoom; 
    Room &bedroom;
    SecuritySystem &securitySystem;

public:
    AutomationEngine(Room &livingRoom,
                     Room &bedroom,
                     SecuritySystem &securitySystem);

    void goodNight();
    void goodMorning();
    void leavingHome();
    void movieMode();
};
#endif