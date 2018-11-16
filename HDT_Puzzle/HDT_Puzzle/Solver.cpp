#include "Solver.h"


Solver::Solver()
{
	fin.open("puzzle.txt");
	fin >> puzzle_row >> puzzle_col;
	puzzle = new int*[puzzle_row];
	for (int i = 0; i < puzzle_row; ++i)
	{
		puzzle[i] = new int[puzzle_col];
		for (int j = 0; j < puzzle_col; ++j)
		{
			int input;
			fin >> input;
			puzzle[i][j] = input;
			if (input != -1 && input != 0)// table입력이 -1, 0 아니면 hint로 판단하고 위치 저장,start&end는 아직
			{
				//hint.push_back(INT_PAIR(i, j));
				hint_temp.push_back(make_pair(puzzle[i][j], INT_PAIR(i, j)));
			}
			if (input == 1)
			{
				start.first = i, start.second = j;
			}
			if (input > max)
			{
				max = input;
				end.first = i, end.second = j;
			}
		}
	}
	sort(hint_temp.begin(), hint_temp.end());
}

void Solver::getPuzzle()
{
}

void Solver::ShowPuzzle()
{
	for (int i = 0; i < puzzle_row; ++i)
	{
		for (int j = 0; j < puzzle_col; ++j)
		{
			printf("%3d", puzzle[i][j]);
		}
		cout << endl;
	}
}

void Solver::ShowHint()
{
	vector<pair<int, pair<int, int>>>::iterator it;
	for (it = hint_temp.begin(); it != hint_temp.end(); ++it)
	{
		//cout << puzzle[(*it).first][(*it).second]<<" :::: "<<(*it).first << " " << (*it).second << endl;
		cout << (*it).first << " :::: " << (*it).second.first << " " << (*it).second.second << endl;
	}
}

void Solver::Solve(const int& x, const int& y, int step, int hint_idx)
{
	if (step == puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second] && (x != hint_temp[hint_idx].second.first || y != hint_temp[hint_idx].second.second))
	{
		return;
	}
	puzzle[x][y] = step;
	cout << "step: " << step << " , visiting: " << "(" << x << "," << y << ") ::" << puzzle[x][y] << "---------------------------------------------------" << endl;
	if (step == puzzle[end.first][end.second])
	{
		cout << "SUCCESS" << endl;
		return;
	}

	for (int i = 0; i < 9; ++i)
	{

		if (i == 8) {
			puzzle[x][y] = 0;
			return;
		}
		else if (x + dRow[i] > 15 || x + dRow[i] < 0 || y + dCol[i] >15 || y + dCol[i] < 0) {
			cout << "***continue***" << endl;
			continue;
		}
		else if (puzzle[x + dRow[i]][y + dCol[i]] == 0 && step + 1 < puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second])// 0을 만났을 경우
		{
			Solve(x + dRow[i], y + dCol[i], step + 1, hint_idx);
		}
		else if ((x + dRow[i] == hint_temp[hint_idx].second.first && y + dCol[i] == hint_temp[hint_idx].second.second) && (step + 1) == puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second]) // hint를 제 때에 만났을 경우
		{
			Solve(x + dRow[i], y + dCol[i], step + 1, hint_idx + 1);
		}
		else if (i == 7) {
			puzzle[x][y] = 0;
			return;
		}

		cout << "i= " << i << " : step= " << step << " : hint_idx= " << hint_idx << endl;
		cout << puzzle[x][y] << " : " << puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second] << " : look= " << puzzle[x + dRow[i]][y + dCol[i]] << " : lookX= " << x + dRow[i] << " : lookY= " << y + dCol[i] << endl;

	}
}

int Solver::getMax()
{
	return max;
}

INT_PAIR Solver::getStart()
{
	return INT_PAIR(start);
}

INT_PAIR Solver::getEnd()
{
	return INT_PAIR(end);
}

void Solver::Initiate()
{
	Solve(start.first, start.second, 0, 0);
}