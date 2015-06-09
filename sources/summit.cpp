#include "summit.h"

summit::summit()
{

}
summit::~summit()
{

}
void summit::createClass(int a)
{
    if (a==1)
    {
        //battleship();
        *this->health = 80;
        *this->maxHealth = 80;
        *this->shields = 4;
        *this->maxShields = 4;
        *this->weaponPower = 8;
        *this->accuracy = 4;
        *this->pierce = 0;
        *this->enginesLevel = 2;
        *this->armorLevel = 3;
    }
    else if (a==2)
    {
        //cruiser();
        *this->health = 60;
        *this->maxHealth = 60;
        *this->shields = 3;
        *this->maxShields = 3;
        *this->weaponPower = 6;
        *this->accuracy = 8;
        *this->pierce = 1;
        *this->enginesLevel = 4;
        *this->armorLevel = 0;
    }
    else
    {
        //destroyer();
        *this->health = 40;
        *this->maxHealth = 40;
        *this->shields = 2;
        *this->maxShields = 2;
        *this->weaponPower = 4;
        *this->accuracy = 6;
        *this->pierce = 0;
        *this->enginesLevel = 6;
        *this->armorLevel = 0;
    }
    setClass(a);
}
