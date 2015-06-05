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
    damagedEngines = new int;
    damagedWeapons = new int;
    damagedOptics = new int;
    breachedHull = new int;
    damagedShields = new int;
    flagIsDead = new bool;
    flagIsDead = false;
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
    delete damagedEngines;
    delete damagedWeapons;
    delete damagedOptics;
    delete breachedHull;
    delete damagedShields;
    delete flagIsDead;
}
bool ship::checkHit(ship* attacker, ship* defender)
{
    int hitModifier;
    hitModifier = (defender->enginesLevel  - attacker->accuracy) * 10;
    int result = rand() % 100 + 1;
    if (result >= hitModifier + 20)
        return true;
    else
        return false;
}
void ship::hitShields(ship* attacker, ship* defender, int target)
{
    defender->shields -= 1 + (*attacker->pierce / 2);
    if (defender->shields < 0)
    {
        attacker->hitShip(this, defender, target);
        defender->shields = 0;
    }
}
void ship::hitShip(ship* attacker, ship* defender, int target)
{
    defender->health -= *attacker->weaponPower - (defender->armorLevel - attacker->pierce);
    if (defender->health <= 0)
        *defender->flagIsDead = true;
    int diceroll = rand() % 100 + 1;
    if (diceroll - (defender->armorLevel - attacker->pierce) >= 35)  //Rolling for crit
    {
        if (target = 1)
            *defender->damagedEngines = turnNumber + 4;
        else if (target = 2)
            *defender->damagedWeapons = turnNumber + 4;
        else if (target = 3)
            *defender->damagedOptics = turnNumber + 4;
        else if (target = 4)
            *defender->breachedHull = turnNumber + 4;
        else if (target = 5)
            *defender->damagedShields = turnNumber + 4;
    }
}

