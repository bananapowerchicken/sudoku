#include "Solver.h"

void Solver::getEmptyCells(Grid* grid)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			if (!m_matrix[i][j])
			{
				// here should fill my empty vector with empty cells
				Cell cell;
				cell.setValue(m_matrix[i][j]);
				emptyCellsVector.push_back(cell);
			}
			else
			{
				std::cout << "No empty cells, sudoku is solved :)\n";
				return;
			}
		}		
	}
	
}

void Solver::showCurrentMatrix()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Solver::fillMatrix(Grid* grid)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			m_matrix[i][j] = grid->getElement(i, j);
		}

	}
}

void Solver::solve(Grid* grid)
{
	fillMatrix(grid);
}