#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "gameplayFunctions.h"

class ship {
protected:
    int* health;
    int* maxHealth;
    int* shields;
    int* maxShields;
    int* weaponPower;
    int* accuracy;
    int* pierce;
    int* enginesLevel;
    int* armorLevel;
    int* damagedEngines;
    int* damagedWeapons;
    int* damagedOptics;
    int* breachedHull;
    int* damagedShields;
    bool* flagIsDead;
public:
    bool checkHit(ship*, ship*);
    void hitShields(ship*, ship*, int);
    void hitShip(ship*, ship*, int);
    ship();
    virtual ~ship();
};

#endif // SHIP_H
