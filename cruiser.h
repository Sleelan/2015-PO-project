#ifndef CRUISER_H
#define CRUISER_H
#include "player.h"

class cruiser : virtual public player {
private:
    int* originalShields;
    int* originalMaxShields;
    int* originalPierce;
    int* originalAccuracy;
public:
    bool* flagSpecialPowerOn;
    cruiser();
    virtual ~cruiser();
    void specialPowerOn();
    void specialPowerOff();
};

#endif // CRUISER_H
