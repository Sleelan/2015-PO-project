#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "player.h"

class battleship : virtual public player {
private:
    int* originalShields;
    int* originalMaxShields;
    int* originalWeaponPower;
public:
    bool* flagSpecialPowerOn;
    battleship();
    virtual ~battleship();
    void specialPowerOn();
    void specialPowerOff();
};

#endif // BATTLESHIP_H
