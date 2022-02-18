#pragma once
#include "Grid.h"
#include "Cell.h"
#include <vector>

class Solver
{
private:
	std::vector <Cell> emptyCellsVector;
	void getEmptyCells(Grid* grid);
public:
	void solve(Grid* grid);
	
};