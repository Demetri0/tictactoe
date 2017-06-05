#ifndef CONSOLEDRAWER_H
#define CONSOLEDRAWER_H

#include "board.h"
#include <iostream>

class ConsoleDrawer /* : AbstractDrawer */
{
private:
    ConsoleDrawer( /*stdout*/ );
public:
    static void draw(const Board& board);
};

#endif // CONSOLEDRAWER_H
