#include "cruiser.h"

cruiser::cruiser()
{
    *this->health = 60;
    *this->maxHealth = 60;
    *this->shields = 3;
    *this->maxShields = 3;
    *this->weaponPower = 6;
    *this->accuracy = 8;
    *this->pierce = 1;
    *this->enginesLevel = 4;
    *this->armorLevel = 0;
    flagSpecialPowerOn = new bool;
    *flagSpecialPowerOn = false;
    originalShields = new int;
    originalMaxShields = new int;
    originalPierce = new int;
    originalAccuracy = new int;
}
cruiser::~cruiser()
{
    delete originalShields;
    delete originalMaxShields;
    delete originalPierce;
    delete originalAccuracy;
    delete flagSpecialPowerOn;
}

void cruiser::specialPowerOn()
{
    *this->originalShields = *this->shields;
    *this->originalMaxShields = *this->maxShields;
    *this->originalPierce = *this->pierce;
    *this->originalAccuracy = *this->accuracy;
    *this->shields = *this->shields / 2;
    *this->maxShields = *this->maxShields / 2;
    *this->pierce = (int)(*this->pierce * 2);
    *this->accuracy = *this->accuracy * 2;
    *flagSpecialPowerOn = true;
}

void cruiser::specialPowerOff()
{
    *this->shields = *this->shields * 2;
    *this->maxShields = *this->originalMaxShields;
    *this->pierce = *this->originalPierce;
    *this->accuracy = *this->originalAccuracy;
    *flagSpecialPowerOn = false;
}
