#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include "abstractplayer.h"

class LocalPlayer : public AbstractPlayer
{
public:
    LocalPlayer(char symbol, std::wstring name = L"Local Player");

    // AbstractPlayer interface
public:
    bool getTurn(Board &board);
};

#endif // LOCALPLAYER_H
