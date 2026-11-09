HighLife Simulation

A C implementation of the HighLife cellular automaton, a variant of Conway's Game of Life.

Game Rules (B36/S23)

HighLife uses the B36/S23 ruleset. Each cell can be either alive or dead, and its next state depends on the number of living cells among its eight neighbors.

Birth (B36)
-- A dead cell becomes alive if it has exactly 3 or 6 living neighbors.
-- Otherwise, it remains dead.

Survival (S23)
-- A living cell survives if it has exactly 2 or 3 living neighbors.
-- Otherwise, it dies.

Simulation Rules
-- Board Size: 30 x 30 cells.
-- Generations: 70 generations, plus the initial generation (0).
-- Neighbors: Each cell has eight neighboring positions, including diagonals.
-- Wrapping: The board wraps around at its edges. Cells on opposite edges are considered neighbors.
-- Simultaneous Updates: All cells are updated based on the previous generation.

Cell Aging
-- . : Dead cell
-- o : Newly born cell (age 0)
-- O : Living cell (age 1)
-- @ : Living cell (age 2 or older)

A newly born cell starts at age 0. Each time a cell survives another generation, its age increases by 1.

Starting Pattern
-- The simulation begins with a replicator pattern consisting of 12 living cells.
-- Under the HighLife rules, this pattern produces new copies along the diagonal every 12 generations.

Implementation
-- Language: C (C23)
-- Data Structures: Structures and multidimensional arrays
-- Core Concepts: Nested loops, neighbor counting, modular arithmetic, and generation-based simulation
