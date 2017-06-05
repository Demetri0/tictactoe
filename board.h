#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
	char** _board = nullptr;
	int _size = 3;

public:
	Board(int size = 3);
    char getValue(int x, int y) const;
    bool setValue(int x, int y, char sign);

    int size() const;

    void reset();
};

#endif // BOARD_H
