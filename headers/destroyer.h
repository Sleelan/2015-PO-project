#ifndef DESTROYER_H
#define DESTROYER_H
#include "player.h"

class destroyer : public player {
private:
    bool* flagSpecialPowerOn;
    int* originalEnginesLevel;
    int* originalAccuracy;
public:
    destroyer();
    ~destroyer();
    void specialPowerOn();
    void specialPowerOff();
};
#endif // DESTROYER_H
