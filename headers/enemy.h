#ifndef ENEMY_H
#define ENEMY_H
#include "ship.h"

class enemy : public ship
{
public:
    enemy();
    ~enemy();
    void rollEnemy (int);
    void rollBoss (int);
    int* enemyClass;
private:
    bool* isPlayer;
};

#endif // ENEMY_H
