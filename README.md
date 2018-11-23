# HDT_Puzzle

This hidato puzzle program has three following modules:
1. Generator
2. Solver
3. Verifier (currently working on this)


Generator module:
1. Makes 5x5 to 15x15 sized hidato puzzle based on its original rules.
  <br/>a. Rules aren't as strict as original rules.
  <br/>b. Multiple solutions are **allowed.**
2. Passes puzzle table and its row/column size to Solver

Solver module:
1. Gets hint numbers and their positions by searching whole table.
2. Finds a solution using DFS recursively.
3. If it finds a solution, then passes its result to Verifier.

Verifier:
1. Gets solved puzzle table from Solver.
2. Finds initial number to final number by searching adjacent numbers recursively.
-TBD



Reference
</br>
https://en.wikipedia.org/wiki/Hidato
