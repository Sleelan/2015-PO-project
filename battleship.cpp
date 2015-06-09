#include "battleship.h"

battleship::battleship()
{
    *this->health = 80;
    *this->maxHealth = 80;
    *this->shields = 4;
    *this->maxShields = 4;
    *this->weaponPower = 8;
    *this->accuracy = 4;
    *this->pierce = 0;
    *this->enginesLevel = 2;
    *this->armorLevel = 3;
    flagSpecialPowerOn = new bool;
    *flagSpecialPowerOn = false;
    originalShields = new int;
    originalMaxShields = new int;
    originalWeaponPower = new int;
}
battleship::~battleship()
{
    delete originalShields;
    delete originalMaxShields;
    delete originalWeaponPower;
    delete flagSpecialPowerOn;
}

void battleship::specialPowerOn()
{
    *this->originalShields = *this->shields;
    *this->originalMaxShields = *this->maxShields;
    *this->originalWeaponPower = *this->weaponPower;
    *this->shields = *this->shields * 2;
    *this->maxShields = *this->maxShields * 2;
    *this->weaponPower = (int)(*this->weaponPower * 0.5);
    *flagSpecialPowerOn = true;
}

void battleship::specialPowerOff()
{
    *this->shields = *this->shields / 2;
    *this->maxShields = *this->originalMaxShields;
    *this->weaponPower = *this->originalWeaponPower;
    *flagSpecialPowerOn = false;
}
