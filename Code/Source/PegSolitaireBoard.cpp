#include "PegSolitaireBoard.h"
#include <iostream>

PegSolitaireBoard::PegSolitaireBoard() {
    rows = 7;
    cols = 7;
    table = {
        {2, 2, 1, 1, 1, 2, 2},
        {2, 2, 1, 1, 1, 2, 2},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {2, 2, 1, 1, 1, 2, 2},
        {2, 2, 1, 1, 1, 2, 2}
    };
}

void PegSolitaireBoard::reset() {
    table = {
         {2, 2, 1, 1, 1, 2, 2},
         {2, 2, 1, 1, 1, 2, 2},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 0, 1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {2, 2, 1, 1, 1, 2, 2},
         {2, 2, 1, 1, 1, 2, 2}
    };
}

bool PegSolitaireBoard::move(int row, int col, int dir) {
    if (table[row][col] != 1) {
        return false;
    }

    if (dir == 0 && col - 2 >= 0 && table[row][col - 1] == 1 && table[row][col - 2] == 0) {
        table[row][col] = table[row][col - 1] = 0;
        table[row][col - 2] = 1;
        return true;
    }

    if (dir == 1 && col + 2 < cols && table[row][col + 1] == 1 && table[row][col + 2] == 0) {
        table[row][col] = table[row][col + 1] = 0;
        table[row][col + 2] = 1;
        return true;
    }

    if (dir == 2 && row - 2 >= 0 && table[row - 1][col] == 1 && table[row - 2][col] == 0) {
        table[row][col] = table[row - 1][col] = 0;
        table[row - 2][col] = 1;
        return true;
    }

    if (dir == 3 && row + 2 < rows && table[row + 1][col] == 1 && table[row + 2][col] == 0) {
        table[row][col] = table[row + 1][col] = 0;
        table[row + 2][col] = 1;
        return true;
    }

    return false;

}

void PegSolitaireBoard::unmove(int row, int col, int dir) {
    if (dir == 0) {
        table[row][col] = table[row][col - 1] = 1;
        table[row][col - 2] = 0;
    }
    else if (dir == 1) {
        table[row][col] = table[row][col + 1] = 1;
        table[row][col + 2] = 0;
    }
    else if (dir == 2) {
        table[row][col] = table[row - 1][col] = 1;
        table[row - 2][col] = 0;
    }
    else if (dir == 3) {
        table[row][col] = table[row + 1][col] = 1;
        table[row + 2][col] = 0;
    }


}

void PegSolitaireBoard::pretty_print() {
    std::cout << "   ";
    for (int col_ind = 0; col_ind < cols; col_ind++) {
        std::cout << " " << col_ind << " ";
    }
    std::cout << std::endl;
    std::cout << "   ______________________";//upper
    std::cout << std::endl;

    for (int row_ind = 0; row_ind < rows; row_ind++) {
        for (int col_ind = 0; col_ind < cols; col_ind++) {
            if (col_ind == 0) {
                std::cout << row_ind << " |";
            }

            switch (table[row_ind][col_ind]) {
            case 2:
                std::cout << " x ";
                break;
            case 0:
                std::cout << "   ";
                break;
            case 1:
                std::cout << " i ";
                break;
            }

            if (col_ind == cols - 1) {
                std::cout << "|" << std::endl;
            }
        }
    }
    std::cout << "  -----------------------";//down

}


