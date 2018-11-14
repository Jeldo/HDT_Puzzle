# HDT_Puzzle

This hidato puzzle program has three following modules:
1. Generator
2. Solver (working on)
3. Verifier


Generator module:
1. Makes 5x5 to 15x15 sized hidato puzzle based on its original rules.
  a. Rules aren't as strict as original rules.
  b. Multiple solutions are <b>allowed.</b>
2. Pass puzzle table and its row/column size to Solver

Solver module:
1. Gets hint numbers and their positions by searching whole table.
2. Finds a solution using DFS recursively.
3. If it finds a solution, then pass its result to Verifier.

Verifier:
-TBD
