#ifndef PLAYER_H
#define PLAYER_H
#include "ship.h"

extern int playerClass;
class player : public ship
{
protected:
    bool* isPlayer;
public:
    int* shipClass;
    void setClass(int);
    player();
    virtual ~player();
};

#endif // PLAYER_H
