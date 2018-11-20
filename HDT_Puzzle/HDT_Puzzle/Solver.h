#pragma once
#include "CommonDef.h"
#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Solver {
private:

   //남 남서 서 북서 북 북동 동 남동
   int puzzle_row, puzzle_col;
   int** puzzle;
   int max = 0;
   VEC_PAIR hint;
   STK_PAIR path;
   INT_PAIR start;
   INT_PAIR end;
   ifstream fin;
   stack<int> s_step;
   stack<int**> s_table;
   stack<INT_PAIR> back;
   vector<pair<int, pair<int, int> > > hint_temp;
   bool isEnd = false;

public:

   Solver();

   void getPuzzle();
   void ShowPuzzle();
   void ShowHint();
   void Solve(const int& x, const int& y, int step, int hint_idx, bool check);
   //void Solve(int** puzzle, const int& x, const int& y, int& step, int& hint_idx);
   int getMax();
   INT_PAIR getStart();
   INT_PAIR getEnd();
   void Initiate();
};