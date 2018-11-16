#include "Solver.h"


Solver::Solver()
{
	fin.open("puzzle.txt");
	fin >> puzzle_row >> puzzle_col;
	table = new int*[puzzle_row];
	for (int i = 0; i < puzzle_row; ++i)
	{
		table[i] = new int[puzzle_col];
		for (int j = 0; j < puzzle_col; ++j)
		{
			int input;
			fin >> input;
			table[i][j] = input;
			if (input != -1 && input != 0)// table입력이 -1, 0 아니면 hint로 판단하고 위치 저장,start&end는 아직
			{
				hint.push_back(INT_PAIR(i, j));
			}
			if (input > max)
			{
				max = input;
				end.first = i, end.second = j;
			}
		}
	}
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
			printf("%3d", table[i][j]);
		}
		cout << endl;
	}
}

void Solver::ShowHint()
{
	vector<INT_PAIR>::iterator it;
	for (it = hint.begin(); it != hint.end(); ++it)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}
}

void Solver::Solve(int** puzzle, const int& x, const int& y, int& step, int& hint_idx, int cnt)
{
	puzzle[x][y] = step;
	path.push(INT_PAIR(x, y));
	++step;
	bool goBack = true;

	if (step == puzzle[end.first][end.second])
	{
		//END!
	}
	for (int i = 0; i < 8; ++i)
	{
		if (puzzle[x][y] == 0 && step < puzzle[hint[hint_idx].first][hint[hint_idx].second])// 0을 만났을 경우
		{
			cnt++;
			Solve(puzzle, x + dx[i], y + dy[i], step, hint_idx, cnt);
			goBack = false;
		}
		else if (step == puzzle[hint[hint_idx].first][hint[hint_idx].second]) // hint를 제 때에 만났을 경우
		{
			cnt = 0;
			Solve(puzzle, x + dx[i], y + dy[i], step, hint_idx, cnt);
			goBack = false;
		}
	}
	
	if (goBack) {
		while (cnt--) {

		}
		Solve(puzzle, x)
	}
	//만나지 못한 경우, 이전 힌트 단계까지 돌려놔야함.백트랙킹
	

}

int Solver::getMax()
{
	return max;
}

INT_PAIR Solver::getEnd()
{
	return INT_PAIR(end);
}
