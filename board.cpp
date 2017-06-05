#include "board.h"
#include <cassert>

Board::Board(int size){
    assert(size > 2);
    _board = new char*[ size ];
    for( int i = 0; i < size; i++ ){
        _board[i] = new char[ size ];
        for( int j = 0; j < size; j++ ){
            _board[i][j] = ' ';
        }
    }
}

char Board::getValue(int x, int y) const{
    assert(_board != nullptr);
    assert(x < _size && y < _size);
    return _board[x][y];
}

bool Board::setValue(int x, int y, char sign){
    assert(x < _size && y < _size);
    assert(sign == ' ' || sign == 'X' || sign == 'O');
    if( _board[x][y] == ' ' ){
        _board[x][y] = sign;
        return true;
    }
    return false;
}

int Board::size() const
{
    return _size;
}

void Board::reset()
{
    for( int i = 0; i < _size; i++ ){
        for( int j = 0; j < _size; j++ ){
            _board[i][j] = ' ';
        }
    }
}
