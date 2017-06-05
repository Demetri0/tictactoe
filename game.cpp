#include "game.h"
#include <cassert>
#include "consoledrawer.h"

#include "randomplayer.h"
#include "localplayer.h"

Game::Game()
    : _board(3)
{
    _player1 = new LocalPlayer('X', L"User 1");
    _player2 = new RandomPlayer('O', L"Rand 1");
}

Board &Game::board()
{
    return _board;
}

bool Game::isVictory(char *symbol) const
{
    // test rows
    for (int row = 0; row < _board.size(); ++row) {
        char last = _board.getValue(row, 0);
        for (int col = 1; col < _board.size(); ++col) {
            if( _board.getValue(row,col) != last ){
                break;
            } else if ( _board.size() == (col+1) ){
                if( symbol != nullptr ){
                    *symbol = last;
                    return true;
                }
            }
        }
    }

    // test cols
    for (int col = 0; col < _board.size(); ++col) {
        char last = _board.getValue(0, col);
        for (int row = 1; row < _board.size(); ++row) {
            if( _board.getValue(row,col) != last ){
                break;
            } else if ( _board.size() == (row+1) ){
                if( symbol != nullptr ){
                    *symbol = last;
                    return true;
                }
            }
        }
    }

    // test main diagonal
    char last = _board.getValue(0,0);
    for (int row_col = 1; row_col < _board.size(); ++row_col) {
        if( _board.getValue(row_col, row_col) != last ){
            break;
        } else if ( _board.size() == (row_col+1) ){
            if( symbol != nullptr ){
                *symbol = last;
                return true;
            }
        }
    }

    // test additional diagonal
    int n = _board.size()-1;
    char last = _board.getValue(0, n);
    for (int row = 0; row < _board.size(); ++row) {
        if( _board.getValue(row, n-row) != last ){
            break;
        } else if ( _board.size() == (row+1) ){
            if( symbol != nullptr ){
                *symbol = last;
                return true;
            }
        }
    }
}

bool Game::isFinish() const
{
    /// \todo test finish
    /// isVin == true or draw
    /// field is full
    for (int i = 0; i < _board.size(); ++i) {
        for (int j = 0; j < _board.size(); ++j) {
            if( _board.getValue(i,j) == ' ' ){
                return false;
            }
        }
    }
    return true;
}

int Game::run()
{
    assert( _player1 != nullptr && _player2 != nullptr );

    this->board().reset();

    while( ! this->isFinish() ){
        ConsoleDrawer::draw( this->board() );
        _player1->getTurn( this->board() );
        _player2->getTurn( this->board() );
    }

    return 0;
}

