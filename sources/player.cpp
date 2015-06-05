#include "player.h"

player::player()
{
    isPlayer = new bool;
    *isPlayer = true;
    shipClass = new int;
}
player::~player()
{
    delete isPlayer;
    delete shipClass;
}
void player::setClass(int a)
{
    *this->shipClass = a;
}

