#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Solver.h"
#include "GeneratorC.h"
#include "Verifier.h"

using namespace std;

int main(void)
{
	srand((unsigned int)time(NULL));
	Generator Gen;
	int startX = Gen.getStartRow();
	int startY = Gen.getStartCol();
	Gen.GeneratorPuzzle(startX, startY, START_NUM);
	//Gen.getEndNumber();
	Gen.ReduceZero();
	Gen.ShowPuzzle();
	Gen.ShowCompletePuzzle();
	//Gen.ShowHint();
	

	Solver sol(MAX_SIZE_MAP,MAX_SIZE_MAP);
	
	//sol.setPuzzlePtr(Gen.getPuzzle());
	sol.setSolPuzzle(Gen.getPuzzle());
	cout << sol.getMax() << endl;
	//cout << sol.getEnd().first << " " << sol.getEnd().second << endl;
	sol.ShowPuzzle();
	clock_t begin, end;
	cout << "first setWeightPuzzle" << endl;
	sol.setWeightPuzzle(Gen.getPuzzle(), sol.getWeiPuzzle1());
	cout << "second setWeightPuzzle" << endl;
	sol.setWeightPuzzle(sol.getWeiPuzzle1(), sol.getWeiPuzzle2());
	cout << "let's see the weightpuzzle" << endl;
	//sol.ShowWeightPuzzle();
	cout << "let's start" << endl;
	begin = clock();
	sol.InitiateW();
	end = clock();
	//sol.ShowPuzzle();
  
	cout << "Time: " << end - begin << "ms" << endl;
	cout << endl;

	Solver sol2(MAX_SIZE_MAP, MAX_SIZE_MAP);
	sol2.setSolPuzzle(Gen.getPuzzle());
	//sol2.ShowPuzzle();
	begin = clock();
	sol2.Initiate();
	end = clock();
	//sol2.ShowPuzzle();
	cout << endl << "Time: " << end - begin << "ms" << endl;

	Verifier ver;
	ver.findStartAndEnd(sol.getPuzzle(), MAX_SIZE_MAP, MAX_SIZE_MAP);
	ver.Verify();
	//sol.~Solver();
	sol2.~Solver();

	return 0;
}