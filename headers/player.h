#ifndef PLAYER_H
#define PLAYER_H
#include "ship.h"

class player : public ship
{
protected:
    bool* isPlayer;
    int* shipClass;
public:
    void setClass(int);
    player();
    virtual ~player();
};

#endif // PLAYER_H
