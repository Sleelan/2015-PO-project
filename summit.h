#ifndef SUMMIT_H
#define SUMMIT_H
#include "battleship.h"
#include "cruiser.h"
#include "destroyer.h"

class summit : public cruiser, public battleship, public destroyer
{
public:
    summit();
    ~summit();
    void createClass(int); //meant to be called once, defines initial values of ship's statistics
};

#endif // SUMMIT_H
