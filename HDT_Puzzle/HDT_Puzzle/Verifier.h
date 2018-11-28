#pragma once
#include "CommonDef.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Verifier {
private:
	int puzzle_row, puzzle_col;
	int** puzzle;
	int max;
	INT_PAIR start;
	INT_PAIR end;
	bool isCorrect;
public:
    Verifier();
    void findStartAndEnd(int** sol_puzzle, const int& row_size, const int& col_size);
    void verifyPuzzle(const int& x, const int& y, int step);
    void Verify();
    INT_PAIR getStart();
	INT_PAIR getEnd();
    
};