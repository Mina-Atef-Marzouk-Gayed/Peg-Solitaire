#include <iostream>
#include <vector>
#include <tuple>
#include "PegSolitaireBoard.h";
#include "PegSolitaireSolver.h"
int main() {
    bool interactive = false;
    bool relax = false;
    PegSolitaireBoard board;
    PegSolitaireSolver solver(board, relax);
    auto solution = solver.solve();

    solver.print_solution(interactive);

    std::cout << "FINISHED ";
}