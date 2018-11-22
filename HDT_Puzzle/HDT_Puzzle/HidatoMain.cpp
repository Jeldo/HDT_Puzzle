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
	Gen.ShowPuzzle();

	Solver sol;
	//sol.setPuzzlePtr(Gen.getPuzzle());
	sol.setSolPuzzle(Gen.getPuzzle(), 15, 15); // row, col size 변수 선언해야함
	cout << sol.getMax() << endl;
	cout << sol.getEnd().first << " " << sol.getEnd().second << endl;
	sol.ShowPuzzle();
	sol.Initiate();
	sol.ShowPuzzle();
	return 0;
}