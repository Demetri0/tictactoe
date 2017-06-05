#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#include "board.h"
#include <string>

class AbstractPlayer
{
private:
    std::wstring _name;
    char _symbol = ' ';

public:
    AbstractPlayer(char symbol, std::wstring name = L"Unknown"){
        _symbol = symbol;
        _name = name;
    }
    char symbol() const {
        return _symbol;
    }
    virtual bool getTurn(Board& board) = 0;
};

#endif // ABSTRACTPLAYER_H
