#include "localplayer.h"

#include <iostream>

LocalPlayer::LocalPlayer(char symbol, std::wstring name)
    : AbstractPlayer(symbol, name)
{

}

bool LocalPlayer::getTurn(Board &board)
{
    int x,y;
    do {
        std::cout << "Enter your move (Row space Column): ";
        std::cin >> x >> y;
    } while( ! board.setValue( x,y, this->symbol() ) );

    return true;
}

