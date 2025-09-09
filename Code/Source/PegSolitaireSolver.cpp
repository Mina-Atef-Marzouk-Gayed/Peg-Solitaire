#include "PegSolitaireSolver.h"
#include "PegSolitaireSolver.h"
#include <iostream>
#include <algorithm>
#include<tuple>

bool PegSolitaireSolver::_back_track(int move) {
    if (move == max_moves) {
        if (this->relax || this->board.table[center_row][center_column] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
 

    for (int r = 0; r < board.table.size(); r++) {
        for (int c = 0; c < board.table[0].size(); c++) {
            for (int d = 0; d < 4; d++) {
                if (board.move(r, c, d)) {
                    if (_back_track(move + 1)) {
                        solution.push_back(std::make_tuple(r, c, d));
                        return true;
                    }
                    board.unmove(r, c, d);
                }
            }
        }
    }

    return false;

}

PegSolitaireSolver::PegSolitaireSolver(PegSolitaireBoard board, bool relax)
    : board(board), relax(relax) {
    int num_pegs = 0;
    for (const auto& row : board.table) {
        for (int elem : row) {
            if (elem == 1) {
                num_pegs++;
            }
        }
    }

    max_moves = num_pegs - 1;
    center_row = board.table.size() / 2;
    center_column = board.table[0].size() / 2;

}

std::vector<std::tuple<int, int, int>> PegSolitaireSolver::solve() {
    solution.clear();
    board.reset();
    _back_track(0);
    std::reverse(solution.begin(), solution.end());
    return solution;
}

void PegSolitaireSolver::print_solution(bool interactive) {
    board.reset();

    if (interactive) {
        std::cout << "\033[2J";
    }

    std::cout << "\nStarting board\n\n";
    board.pretty_print();

    std::string dir_map[] = { "left", "right", "up", "down" };
    for (const auto& step : solution) {
        int r, c, d;
        std::tie(r, c, d) = step;

        if (interactive) {
            std::cout << "\nPress enter for next move";
            std::cin.get();
            std::cout << "\033[2J";
        }

        std::cout << "\nMoved row " << r << " column " << c << " " << dir_map[d] << "\n\n";

        board.move(r, c, d);
        board.pretty_print();
    }
}

