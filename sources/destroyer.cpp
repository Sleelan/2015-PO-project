#include "destroyer.h"

destroyer::destroyer()
{
    *this->health = 40;
    *this->maxHealth = 40;
    *this->shields = 2;
    *this->maxShields = 2;
    *this->weaponPower = 4;
    *this->accuracy = 6;
    *this->pierce = 0;
    *this->enginesLevel = 6;
    *this->armorLevel = 0;
    flagSpecialPowerOn = new bool;
    *flagSpecialPowerOn = false;
    originalEnginesLevel = new int;
    originalAccuracy = new int;
}
destroyer::~destroyer()
{
    delete originalEnginesLevel;
    delete originalAccuracy;
    delete flagSpecialPowerOn;
}

void destroyer::specialPowerOn()
{
    *this->originalEnginesLevel = *this->enginesLevel;
    *this->originalAccuracy = *this->accuracy;
    *this->enginesLevel = *this->enginesLevel * 2;
    *this->accuracy = *this->accuracy / 2;
    *flagSpecialPowerOn = true;
}

void destroyer::specialPowerOff()
{
    *this->enginesLevel = *this->originalEnginesLevel;
    *this->accuracy = *this->originalAccuracy;
    *flagSpecialPowerOn = false;
}
