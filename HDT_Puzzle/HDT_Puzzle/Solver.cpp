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
			if (input != -1 && input != 0)// table�Է��� -1, 0 �ƴϸ� hint�� �Ǵ��ϰ� ��ġ ����,start&end�� ����
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
		//cout << (*it).first << " :::: " << (*it).second.first << " " << (*it).second.second << endl;
	}
}

void Solver::Solve(const int& x, const int& y, int step, int hint_idx, bool check)
{
	if (isEnd)
	{
		return;
	}
	if (step == puzzle[end.first][end.second])
	{
		cout << "SUCCESS" << endl;
		//cout << end.first << " " << end.second << endl;
		isEnd = true;
		return;
	}
	if (step == puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second] && (x != hint_temp[hint_idx].second.first || y != hint_temp[hint_idx].second.second))
	{
		return;
	}
	//���� step�� ���� hint_idx�� ���� ������ puzzle�� ��ǥ�� �ִ� step���� ������
	//���� ��ǥ�� hint_idx�� ���� ������ puzzle�� '��ǥ'�� �ٸ� �� ����
	puzzle[x][y] = step;
	//cout << "step: " << step << " , visiting: " << "(" << x << "," << y << ") ::" << puzzle[x][y] << "---------------------------------------------------" << endl;
	for (int i = 0; i < 9; ++i)
	{
		//���� ������ �� ���ڸ� ä��鼭 �Դ� ���� �ٽ� 0���� ����� �κ�.
		if (i == 8 && !check) { 
			puzzle[x][y] = 0;
			return;
		}
		//���� ���� �Դ� ���� �ٽ� �ǵ��ƿ����� �ϴµ� ��Ʈ�ڸ��� 0���� �ٲ��� �ʰ� ���ڸ� �״�� ���δ� ���.
		else if (i == 8 && check) { 
			return;
		}
		//�� ĭ�� �� �������� Ž���� �ϴµ� hidato puzzle���� �Ѿ�� ���. �ƹ��ϵ� ���ϰ� �����Ѵ�.
		else if (x + dRow[i] > 15 || x + dRow[i] < 0 || y + dCol[i] >15 || y + dCol[i] < 0) {
			//cout << "***continue***" << endl;
			continue;
		}
		//�� ĭ �����Ϸ��� �κ��� 0�̸鼭, ���� ��Ʈ�� ���ں��� �۴ٸ� �� ĭ �����Ѵ�. ��ͷ� ȣ��.
		else if (puzzle[x + dRow[i]][y + dCol[i]] == 0 && step + 1 < puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second])// 0�� ������ ���
		{
			Solve(x + dRow[i], y + dCol[i], step + 1, hint_idx, false);
		}
		//��Ʈ�� ������ ���� ���. ��Ʈ ��ǥ�� ��ġ�ϸ鼭, ��Ʈ ���ڵ� ��ġ�ϸ� �����Ѵ�.
		else if ((x + dRow[i] == hint_temp[hint_idx].second.first && y + dCol[i] == hint_temp[hint_idx].second.second) && (step + 1) == puzzle[hint_temp[hint_idx].second.first][hint_temp[hint_idx].second.second]) 
		{
			Solve(x + dRow[i], y + dCol[i], step + 1, hint_idx + 1, true);
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