#include <iostream>
#include "Solver.h"

using namespace std;

int main(void)
{
	Solver sol;
	sol.ShowPuzzle();
	sol.ShowHint();
	cout << sol.getMax() << endl;
	cout << sol.getEnd().first << " " << sol.getEnd().second << endl;
	sol.Solve(sol.getStart().first, sol.getStart().second, 1, 1, false);
	return 0;
}