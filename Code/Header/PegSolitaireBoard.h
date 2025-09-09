#ifndef PEG_SOLITAIRE_BOARD_H
#define PEG_SOLITAIRE_BOARD_H

#include <vector>

class PegSolitaireBoard {
public:
    std::vector<std::vector<int>> table;
    int rows, cols;
public:
    PegSolitaireBoard();
    void reset();
    bool move(int row, int col, int dir);
    void unmove(int row, int col, int dir);
    void pretty_print();
};

#endif