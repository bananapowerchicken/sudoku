#pragma once
#include "Grid.h"
#include "Cell.h"
#include <vector>
#include <vector>

class Solver
{
private:
	static const int m_rows = 9; // firstly hardcoded
	static const int m_cols = 9; // need to be static since it must be the same
	// for every instance of this class - it is needed to compilate
	int m_matrix[m_rows][m_cols];
	std::vector <Cell> emptyCellsVector;
	std::vector <Cell> new_emptyCellsVector; // shorter
	void fillMatrix(Grid* grid);

public:
	void solve(Grid* grid);
	void showCurrentMatrix();
	void getEmptyCells(Grid* grid);
	void calculatePossibleValues();
	void setPossibleValuesForCell(int row, int col, int cell_index);
	void fillEmptyCells(); // заполнить те, которые однозначны
};