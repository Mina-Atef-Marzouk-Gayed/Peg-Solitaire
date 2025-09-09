#ifndef PEG_SOLITAIRE_SOLVER_H
#define PEG_SOLITAIRE_SOLVER_H

#include "PegSolitaireBoard.h"
#include <vector>
#include<tuple>

class PegSolitaireSolver {
public:
    PegSolitaireBoard board;
    bool relax;
    int max_moves;
    int center_row, center_column;
    std::vector<std::tuple<int, int, int>> solution;

    bool _back_track(int move);

public:
    PegSolitaireSolver(PegSolitaireBoard board, bool relax = false);
    std::vector<std::tuple<int, int, int>> solve();
    void print_solution(bool interactive = false);
};

#endif // PEG_SOLITAIRE_SOLVER_H
