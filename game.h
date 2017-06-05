#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "abstractplayer.h"

class Game
{
private:
    Board _board;
    AbstractPlayer* _player1 = nullptr;
    AbstractPlayer* _player2 = nullptr;

public:
    Game();
    Board& board();

    bool isVictory(char* symbol = nullptr) const;
    bool isFinish() const;

    int run();
};

#endif // GAME_H
