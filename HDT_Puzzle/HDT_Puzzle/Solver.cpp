#include "Solver.h"


Solver::Solver()
	:max(0), isEnd(false)
{}

void Solver::setPuzzlePtr(int** gen_puzzle) // Don't use this.
{
	this->puzzle = gen_puzzle;
}

void Solver::setSolPuzzle(int** gen_puzzle, const int& row_size, const int& col_size)
{
	puzzle_row = row_size;
	puzzle_col = col_size;
	puzzle = new int*[puzzle_row];
	for (int i = 0; i < puzzle_row; ++i)
	{
		puzzle[i] = new int[puzzle_col];
		for (int j = 0; j < puzzle_col; ++j)
		{
			puzzle[i][j] = gen_puzzle[i][j];
			if (gen_puzzle[i][j] != -1 && gen_puzzle[i][j] != 0)// table입력이 -1, 0 아니면 hint로 판단하고 위치 저장,start&end는 아직
			{
				hint.push_back(make_pair(puzzle[i][j], INT_PAIR(i, j)));
			}
			if (gen_puzzle[i][j] == 1)
			{
				start.first = i, start.second = j;
			}
			if (gen_puzzle[i][j] > max)
			{
				max = gen_puzzle[i][j];
				end.first = i, end.second = j;
			}
		}
	}
	sort(hint.begin(), hint.end());
}

int** Solver::getPuzzle()
{
	return puzzle;
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
	vector<pair<int, pair<int, int> > >::iterator it;
	for (it = hint.begin(); it != hint.end(); ++it)
	{
		//cout << puzzle[(*it).first][(*it).second]<<" :::: "<<(*it).first << " " << (*it).second << endl;
		//cout << (*it).first << " :::: " << (*it).second.first << " " << (*it).second.second << endl;
	}
}

void Solver::Solve(const int& x, const int& y, int step, int hint_idx, bool check)
{
	//After finding one solve, all Solve will stop.
	if (isEnd)
	{
		return;
	}
	// Success. It checks whether step is same end.
	if (step == puzzle[end.first][end.second])
	{
		cout << "SUCCESS" << endl;
		isEnd = true;
		return;
	}
	// It will cut unnecessary searching. If step is same
	if (step == puzzle[hint[hint_idx].second.first][hint[hint_idx].second.second] && (x != hint[hint_idx].second.first || y != hint[hint_idx].second.second))
	{
		return;
	}
	puzzle[x][y] = step;
	//cout << "step: " << step << " , visiting: " << "(" << x << "," << y << ") ::" << puzzle[x][y] << "---------------------------------------------------" << endl;

	for (int i = 0; i < 9 && !isEnd; ++i)
	{
		//길이 막혔을 때 숫자를 채우면서 왔던 길을 다시 0으로 만드는 부분.
		if (i == 8 && !check) {
			puzzle[x][y] = 0;
			return;
		}
		//길이 막혀서 왔던 길을 다시 되돌아오려고 하는데 힌트자리라서 0으로 바꾸지 않고 숫자를 그대로 놔두는 경우.
		else if (i == 8 && check) {
			return;
		}
		//한 칸을 더 가기위해 탐색을 하는데 hidato puzzle판을 넘어가는 경우. 아무일도 안하고 진행한다.
		else if (x + dirRow[i] > MAX_SIZE_MAP - 1 || x + dirRow[i] < 0 || y + dirCol[i] >MAX_SIZE_MAP - 1 || y + dirCol[i] < 0) {
			//cout << "***continue***" << endl;
			continue;
		}
		//한 칸 진행하려는 부분이 0이면서, 다음 힌트인 숫자보다 작다면 한 칸 진행한다. 재귀로 호출.
		else if (puzzle[x + dirRow[i]][y + dirCol[i]] == 0 && step + 1 < puzzle[hint[hint_idx].second.first][hint[hint_idx].second.second])// 0을 만났을 경우
		{
			Solve(x + dirRow[i], y + dirCol[i], step + 1, hint_idx, false);
		}
		//힌트를 제때에 만난 경우. 힌트 좌표와 일치하면서, 힌트 숫자도 일치하면 진행한다.
		else if ((x + dirRow[i] == hint[hint_idx].second.first && y + dirCol[i] == hint[hint_idx].second.second) && (step + 1) == puzzle[hint[hint_idx].second.first][hint[hint_idx].second.second])
		{
			Solve(x + dirRow[i], y + dirCol[i], step + 1, hint_idx + 1, true);
		}

		/*cout << "i= " << i << " : step= " << step << " : hint_idx= " << hint_idx << endl;
		cout << puzzle[x][y] << " : " << puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second] << " : look= " << puzzle[x + dRow[i]][y + dCol[i]] << " : lookX= " << x + dRow[i] << " : lookY= " << y + dCol[i] << endl;
  */
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
	Solve(start.first, start.second, 1, 1, false);
}