#include "consoledrawer.h"

ConsoleDrawer::ConsoleDrawer()
{

}

void ConsoleDrawer::draw(const Board &board)
{
    std::cout << std::endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            std::cout << "[" << board.getValue(i,j) << "]";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

