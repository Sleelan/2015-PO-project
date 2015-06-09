#include "enemy.h"

enemy::enemy()
{
    enemyClass = new int;
    isPlayer = new bool;
    *isPlayer = false;
}
enemy::~enemy()
{
    delete isPlayer;
}
void enemy::rollEnemy(int initialSector)
{
    int sector = initialSector - 1;
    int diceroll;
    diceroll = rand () % 100 + 1;
        if (diceroll < 40) //Heavy fighter
        {
            *this->health = 15  + 2* sector;
            *this->maxHealth = 15 + 2* sector;
            *this->shields = 1 + (int)(sector/2);
            *this->maxShields = 1 + (int)(sector/2);
            *this->weaponPower = 2 + (int)(sector/2);
            *this->accuracy = 6 + sector;
            *this->pierce = 0 + (int)(sector/6);
            *this->enginesLevel = 6 + sector;
            *this->armorLevel = 0 + (int)(sector/4);
        }
        if (diceroll >= 40 && diceroll < 70) //Destroyer
        {
            *this->health = 20 + 2* sector;
            *this->maxHealth = 20 + 2* sector;
            *this->shields = 2 + (int)(sector/2);
            *this->maxShields = 2 + (int)(sector/2);
            *this->weaponPower = 4 + sector;
            *this->accuracy = 4 + (int)(sector/3);
            *this->pierce = 0 + (int)(sector/5);
            *this->enginesLevel = 4 + (int)(sector/2);
            *this->armorLevel = 0 + (int)(sector/2);
        }
        if (diceroll >= 70 && diceroll < 85) //Bomber
        {
            *this->health = 40 + 4* sector;
            *this->maxHealth = 40 + 4* sector;
            *this->shields = 3 + sector;
            *this->maxShields = 3 + sector;
            *this->weaponPower = 8 + sector;
            *this->accuracy = 4 + (int)(sector/4);
            *this->pierce = 0 + (int)(sector/4);
            *this->enginesLevel = 2 + (int)(sector/6);
            *this->armorLevel = 2 + (int)(sector/2);
        }
        if (diceroll >=85) //Cruiser
        {
            *this->health = 35 + 2* sector;
            *this->maxHealth = 35 + 2* sector;
            *this->shields = 3 + (int)(sector/2);
            *this->maxShields = 3 + (int)(sector/2);
            *this->weaponPower = 6 + sector;
            *this->accuracy = 8 + sector;
            *this->pierce = 1 + (int)(sector/2);
            *this->enginesLevel = 4+ (int)(sector/4);
            *this->armorLevel = 0 + (int)(sector/6);
        }
        *flagIsDead = false;
}

void enemy::rollBoss (int initialSector)
{
    int sector = initialSector - 1;
    int diceroll;
    diceroll = rand () % 100 + 1;
    *this->health = 60  + 5 * sector;
    *this->maxHealth = 60 + 5 * sector;
    *this->shields = 6 + 2 * sector;
    *this->maxShields = 6 + 2* sector;
    *this->weaponPower = 6 + 3* sector;
    *this->accuracy = 6 + 3* sector;
    *this->pierce = 1 + sector;
    *this->enginesLevel = 6 + sector;
    *this->armorLevel = 2 + sector;
    *flagIsDead = false;
}
