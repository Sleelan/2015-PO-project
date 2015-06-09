#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
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
public:
    bool* flagIsDead;
    int getShields();
    int getMaxShields();
    int getHealth();
    int getMaxHealth ();
    int getWeaponPower ();
    int getAccuracy() ;
    int getPierce ();
    int getEnginesLevel ();
    int getArmorLevel ();
    void setShields(int);
    void setMaxShields(int);
    void setHealth(int);
    void setMaxHealth (int);
    void setWeaponPower (int);
    void setAccuracy(int) ;
    void setPierce (int);
    void setEnginesLevel (int);
    void setArmorLevel (int);
    bool checkHit(ship, ship);
    void hitShields(ship, ship);
    void hitShip(ship, ship);
    ship();
    virtual ~ship();
    ship &operator = (const ship&);
    ship &operator + (const ship&)const;
    ship &operator - (const ship&)const;
    ship &operator * (const ship&)const;
    ship &operator / (const ship&)const;
};

#endif // SHIP_H
