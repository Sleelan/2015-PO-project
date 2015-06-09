#include "ship.h"

ship::ship()
{
    health = new int;
    maxHealth = new int;
    shields = new int;
    maxShields = new int;
    weaponPower = new int;
    accuracy = new int;
    pierce = new int;
    enginesLevel = new int;
    armorLevel = new int;
    flagIsDead = new bool;
    *flagIsDead = false;
}
ship::~ship()
{
    delete health;
    delete maxHealth;
    delete shields;
    delete maxShields;
    delete weaponPower;
    delete accuracy;
    delete pierce;
    delete enginesLevel;
    delete armorLevel;
    delete flagIsDead;
}
bool ship::checkHit(ship attacker, ship defender)
{
    int hitModifier;
    hitModifier = (*defender.enginesLevel  - *attacker.accuracy) * 10;
    int result = rand() % 100 + 1;
    if (result >= hitModifier + 20)
        return true;
    else
        return false;
}
void ship::hitShields(ship attacker, ship defender)
{
    *defender.shields -= 1 + (*attacker.pierce / 2);
    if (*defender.shields < 0)
    {
        attacker.hitShip(*this, defender);
        *defender.shields = 0;
    }
}
void ship::hitShip(ship attacker, ship defender)
{
    *defender.health -= *attacker.weaponPower - (*defender.armorLevel - *attacker.pierce);
    //if (*defender.health <= 0)
       // *defender.flagIsDead = true;
}
int ship::getShields ()
{
    return *(this->shields);
}
int ship::getMaxShields ()
{
    return *(this->maxShields);
}
int ship::getHealth ()
{
    return *(this->health);
}
int ship::getMaxHealth ()
{
    return *(this->maxHealth);
}
int ship::getWeaponPower()
{
    return *(this->weaponPower);
}
int ship::getAccuracy()
{
    return *(this->accuracy);
}
int ship::getPierce()
{
    return *(this->pierce);
}
int ship::getEnginesLevel()
{
    return *(this->enginesLevel);
}
int ship::getArmorLevel()
{
    return *(this->armorLevel);
}
void ship::setShields(int a)
{
    *this->shields = a;
}
void ship::setMaxShields(int a)
{
    *this->maxShields = a;
}

void ship::setHealth(int a)
{
    *this->health = a;
}
void ship::setMaxHealth(int a)
{
    *this->maxHealth = a;
}
void ship::setWeaponPower(int a)
{
    *this->weaponPower = a;
}
void ship::setAccuracy(int a)
{
    *this->accuracy = a;
}
void ship::setPierce(int a)
{
    *this->pierce = a;
}
void ship::setEnginesLevel(int a)
{
    *this->enginesLevel = a;
}
void ship::setArmorLevel(int a)
{
    *this->armorLevel = a;
}
ship &ship::operator = (const ship& a)
{
    *health = *a.health;
    *maxHealth = *a.maxHealth;
    *shields = *a.shields;
    *maxShields = *a.maxShields;
    *weaponPower = *a.weaponPower;
    *accuracy = *a.accuracy;
    *pierce = *a.pierce;
    *armorLevel = *a.armorLevel;
    *enginesLevel = *a.enginesLevel;
    *flagIsDead = *a.flagIsDead;
    return *this;
}
ship &ship::operator + (const ship& a)const
{
    ship* result;
    result = new ship;
    *result->health = *this->health + *a.health;
    *result->maxHealth = *this->maxHealth + *a.maxHealth;
    *result->shields = *this->shields + *a.shields;
    *result->maxShields = *this->maxShields + *a.maxShields;
    *result->weaponPower = *this->weaponPower + *a.weaponPower;
    *result->accuracy = *this->accuracy + *a.accuracy;
    *result->pierce = *this->pierce + *a.pierce;
    *result->armorLevel = *this->armorLevel + *a.armorLevel;
    *result->enginesLevel = *this->enginesLevel + *a.enginesLevel;
    return *result;
}

ship &ship::operator - (const ship& a)const
{
    ship* result;
    result = new ship;
    *result->health = *this->health - *a.health;
    *result->maxHealth = *this->maxHealth - *a.maxHealth;
    *result->shields = *this->shields - *a.shields;
    *result->maxShields = *this->maxShields - *a.maxShields;
    *result->weaponPower = *this->weaponPower - *a.weaponPower;
    *result->accuracy = *this->accuracy - *a.accuracy;
    *result->pierce = *this->pierce - *a.pierce;
    *result->armorLevel = *this->armorLevel - *a.armorLevel;
    *result->enginesLevel = *this->enginesLevel - *a.enginesLevel;
    return *result;
}
ship &ship::operator * (const ship& a)const
{
    ship* result;
    result = new ship;
    *result->health = *this->health * *a.health;
    *result->maxHealth = *this->maxHealth * *a.maxHealth;
    *result->shields = *this->shields * *a.shields;
    *result->maxShields = *this->maxShields * *a.maxShields;
    *result->weaponPower = *this->weaponPower * *a.weaponPower;
    *result->accuracy = *this->accuracy * *a.accuracy;
    *result->pierce = *this->pierce * *a.pierce;
    *result->armorLevel = *this->armorLevel * *a.armorLevel;
    *result->enginesLevel = *this->enginesLevel * *a.enginesLevel;
    return *result;
}
ship &ship::operator / (const ship& a)const
{
    ship* result;
    result = new ship;
    *result->health = *this->health / *a.health;
    *result->maxHealth = *this->maxHealth / *a.maxHealth;
    *result->shields = *this->shields / *a.shields;
    *result->maxShields = *this->maxShields / *a.maxShields;
    *result->weaponPower = *this->weaponPower / *a.weaponPower;
    *result->accuracy = *this->accuracy / *a.accuracy;
    *result->pierce = *this->pierce / *a.pierce;
    *result->armorLevel = *this->armorLevel / *a.armorLevel;
    *result->enginesLevel = *this->enginesLevel / *a.enginesLevel;
    return *result;
}
