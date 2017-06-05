#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "abstractplayer.h"

class RandomPlayer : public AbstractPlayer
{
public:
    RandomPlayer(char symbol, std::wstring name = L"Random Player");

    // AbstractPlayer interface
public:
    bool getTurn(Board &board);
};

#endif // RANDOMPLAYER_H
