#pragma once
#include "CommonDef.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solver {
private:

	//남 남서 서 북서 북 북동 동 남동
	int puzzle_row, puzzle_col;
	int** puzzle;
	int max;
	INT_PAIR start;
	INT_PAIR end;
	vector<pair<int, pair<int, int> > > hint;
	bool isEnd;
	int zero_count;
	int** weight_puzzle;

public:

	Solver();
	void setSolPuzzle(int** gen_puzzle, const int& row_size, const int& col_size);
	void setWeightPuzzle(int** gen_puzzle, const int& row_size, const int& col_size, int& zero_count);
	//void ShowWeightPuzzle(); TO DO
	void ShowPuzzle();
	void ShowHint();
	void Solve(const int& x, const int& y, int step, int hint_idx, bool check);
	int getMax();
	INT_PAIR getStart();
	INT_PAIR getEnd();
	void Initiate();
};