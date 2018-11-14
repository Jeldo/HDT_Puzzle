#pragma once
#include "CommonDef.h"
#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

class Solver {
private:

	//³² ³²¼­ ¼­ ºÏ¼­ ºÏ ºÏµ¿ µ¿ ³²µ¿
	int puzzle_row, puzzle_col;
	int** table;
	int max = 0;
	VEC_PAIR hint;
	STK_PAIR path;
	INT_PAIR end;
	ifstream fin;
	stack<int> s_step;
	stack<int**> s_table;

public:

	Solver();
	void getPuzzle();
	void ShowPuzzle();
	void ShowHint();
	//void Solve(int** puzzle, const int& x, const int& y, int& step, const VEC_PAIR& hint, int& hint_idx, STK_PAIR& path);
	void Solve(int** puzzle, const int& x, const int& y, int& step, int& hint_idx);
	int getMax();
	INT_PAIR getEnd();
};
