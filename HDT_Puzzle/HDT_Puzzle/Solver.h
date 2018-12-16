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
	int hint_count;
	INT_PAIR start;
	INT_PAIR end;
	vector<pair<int, pair<int, int> > > hint;
	bool isEnd;
	int zero_count;
	float** wei_puzzle1;
	float** wei_puzzle2;
	float** weight_puzzle;
	

public:

	Solver(int row, int col);
	~Solver();
	void setSolPuzzle(int** gen_puzzle);
	void setWeightPuzzle(int** gen_puzzle,float** wei_puzzle1);
	void setWeightPuzzle(float** wei_puzzle1,float** wei_puzzle2);
	void solveWeightpuzzle(const int& x, const int& y, int step, int hint_idx);
	void ShowPuzzle();
	void ShowWeightPuzzle();
	void Solve(const int& x, const int& y, int step, int hint_idx, bool isHint);
	int getMax();
	int getHintCount();
	INT_PAIR getStart();
	INT_PAIR getEnd();
	float** getWeiPuzzle1();
	float** getWeiPuzzle2();
	int** getPuzzle();
	void Initiate();
	void InitiateW();
};