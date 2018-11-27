#include "Verifier.h"

Verifier::Verifier()
	:max(0), isCorrect(false)
{}

void Verifier::findStartAndEnd(int** gen_puzzle, const int& row_size, const int& col_size)
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
}

void Verifier::verifyPuzzle(const int& x, const int& y, int step)
{
	if (step == puzzle[end.first][end.second])
	{
		cout << "correct!" << endl;
		isCorrect = true;
		return;
	}
    
    puzzle[x][y] = step;
    int lookX, lookY;

    for (int i = 0; i < 9; ++i) // 8방향탐색을 위한 8가지 경우와 8방향탐색이 실패했을 1가지 경우를 합해서 9가지 경우를 탐색한다.
	{
		lookX = x + dRow[i]; lookY = y + dCol[i];
		if(lookX < 0 || lookX >= MAX_SIZE_MAP || lookY < 0 || lookY >= MAX_SIZE_MAP){
			continue;
		}
        if (i == 8) // 8방향 중  어느 곳으로도 갈수 없다.
        {
            cout << "discorrect" << endl;
		    return;
        }

        else if (puzzle[lookX][lookY] == 0) // 채워지지 않은 부분이 존재한다.
        {
            cout << "discorrect" << endl;
		    return;
        }

        else if (puzzle[lookX][lookY] == step + 1)
        {
            verifyPuzzle(lookX, lookY, step + 1);
            break;
        }
    }
}

void Verifier::Verifey()
{
    verifyPuzzle(start.first, start.second, 1);
}

INT_PAIR Verifier::getStart()
{
	return INT_PAIR(start);
}

INT_PAIR Verifier::getEnd()
{
	return INT_PAIR(end);
}
