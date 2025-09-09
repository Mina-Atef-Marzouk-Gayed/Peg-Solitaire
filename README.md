# Peg Solitaire Solver (C++)

A C++ implementation of the classic **Peg Solitaire** puzzle using a **recursive backtracking algorithm**. The goal is to remove pegs by jumping them over each other into empty holes, leaving a single peg—ideally in the center.

---
## How It Works

1. The board is a **7x7 grid** with pegs and an empty center.
2. The solver tries **all possible moves**: left, right, up, and down.
3. Moves are applied using `move()` and undone with `unmove()` if they don’t work.
4. The program keeps track of successful moves and prints them step by step.
5. Optional **interactive mode** pauses between moves for easier visualization.

---

## Project Structure

### Headers
- `PegSolitaireBoard.h` – Board setup, move/unmove, printing  
- `PegSolitaireSolver.h` – Solver logic  

### Source
- `peg_solitaire.cpp` – Main program  
- `peg_solitaireBoard.cpp` – Implementation of board  
- `peg_solitaireSolver.cpp` – Implementation of solver  

### Output & Documentation
[![Peg Run](Peg%20Run.png)](Peg%20Run.png)
</br>
– Example output of the program  
- [move & unmove.pdf](move%20&%20unmove.pdf) – Explanation of move/unmove functions  
- [PegSolitaire.pdf](PegSolitaire.pdf) – Full project documentation (Overleaf)  

---
## Contributors

- Mina Atef  
- Mina Adel  
- Hassan Zekerallah


