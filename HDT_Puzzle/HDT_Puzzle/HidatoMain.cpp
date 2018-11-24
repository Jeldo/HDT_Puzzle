#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Solver.h"
#include "GeneratorC.h"

using namespace std;

int main(void)
{
	srand((unsigned int)time(NULL));
	Generator Gen;
	int startX = Gen.getStartRow();
	int startY = Gen.getStartCol();
	Gen.GeneratorPuzzle(startX, startY, START_NUM);
	//Gen.getEndNumber();
	//Gen.ShowPuzzle();
	//Gen.ShowCompletePuzzle();
	//Gen.ShowHint();

	Solver sol(MAX_SIZE_MAP, MAX_SIZE_MAP);
	sol.setSolPuzzle(Gen.getPuzzle()); // row, col size 변수 선언해야함
	cout << sol.getMax() << endl;
	//cout << sol.getEnd().first << " " << sol.getEnd().second << endl;
	sol.ShowPuzzle();
	cout << "start" << endl;
	clock_t begin, end;
	begin = clock();
	cout << "first setWeightPuzzle" << endl;
	//잘 전달하고 있는가 확인 필요
	sol.setWeightPuzzle(Gen.getPuzzle(), sol.getWeiPuzzle1());
	cout << "second setWeightPuzzle" << endl;
	sol.setWeightPuzzle(sol.getWeiPuzzle1(), sol.getWeiPuzzle2());
	cout << "let's see the weightpuzzle" << endl;
	sol.ShowWeightPuzzle();
	cout << "let's start" << endl;
	sol.Initiate();
	end = clock();
	cout << "finally" << endl;
	sol.ShowPuzzle();
	cout << endl << "Time: " << end - begin << "ms" << endl;


	return 0;
}