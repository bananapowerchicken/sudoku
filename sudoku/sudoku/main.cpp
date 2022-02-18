#include <iostream>
#include "Cell.h"
#include "Square.h"
#include "Solver.h"
#include "Grid.h"
#include <time.h>
#include <algorithm>
#include <vector>

int main()
{
	srand(time(NULL));// for truly randomizing

	Grid grid;
	grid.show();
	//grid.shakeGrid(1);
	Solver solver;
	solver.solve(&grid);
	solver.showCurrentMatrix();

	return 0;
}