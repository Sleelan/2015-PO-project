#ifndef DESTROYER_H
#define DESTROYER_H
#include "player.h"

class destroyer : virtual public player {
private:
    int* originalEnginesLevel;
    int* originalAccuracy;
public:
    bool* flagSpecialPowerOn;
    destroyer();
    virtual ~destroyer();
    void specialPowerOn();
    void specialPowerOff();
};
#endif // DESTROYER_H
