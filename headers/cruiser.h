#ifndef CRUISER_H
#define CRUISER_H
#include "player.h"

class cruiser : public player {
private:
    bool* flagSpecialPowerOn;
    int* originalShields;
    int* originalMaxShields;
    int* originalPierce;
    int* originalAccuracy;
public:
    cruiser();
    ~cruiser();
    void specialPowerOn();
    void specialPowerOff();
};

#endif // CRUISER_H
