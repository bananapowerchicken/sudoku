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

	Grid grid; // create grid with zero-cells now
	grid.show();
	//grid.shakeGrid(1);

	Solver solver;
	solver.solve(&grid);
	solver.showCurrentMatrix(); // making sure that matrix to solve is copied properly
	solver.getEmptyCells(&grid); // filling empty cells vector
	solver.calculatePossibleValues(); // going through empty cells vector and minimizing possible values for each element

	return 0;
}