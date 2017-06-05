#include "randomplayer.h"
#include <cstdlib>
#include <ctime>

RandomPlayer::RandomPlayer(char symbol, std::wstring name)
    : AbstractPlayer(symbol, name)
{
    srand( time(0) );
}

bool RandomPlayer::getTurn(Board &board)
{
    int fieldsCount = board.size() * board.size();
    int tryMaxCount = fieldsCount * fieldsCount;
    int count = 0;
    int x,y;
    do {
        x = rand() % board.size();
        y = rand() % board.size();
        count++;
    } while( ! board.setValue(x,y, this->symbol() ) && count < tryMaxCount );
    if( count >= tryMaxCount ){
        return false;
    }
    return true;
}

