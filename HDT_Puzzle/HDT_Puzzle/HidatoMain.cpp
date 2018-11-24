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
	clock_t begin, end;
	begin = clock();

	//잘 전달하고 있는가 확인 필요
	sol.setWeightPuzzle(Gen.getPuzzle(), sol.getWeiPuzzle1());
	sol.setWeightPuzzle(sol.getWeiPuzzle1(), sol.getWeiPuzzle2());
	//sol.ShowWeightPuzzle();

	sol.Initiate();
	end = clock();
	sol.ShowPuzzle();
	cout << endl << "Time: " << end - begin << "ms" << endl;


	return 0;
}