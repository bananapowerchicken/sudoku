#include "Solver.h"

void Solver::getEmptyCells(Grid* grid)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			//std::cout << "test\n";
			if (m_matrix[i][j] == 0)
			{
				std::cout << "Empty cell:[" << i << "][" << j << "]\n";
				// here should fill my empty vector with empty cells
				Cell cell(i, j);
				cell.setValue(m_matrix[i][j], i, j);
				emptyCellsVector.push_back(cell);
			}		
		}		
	}
	std::cout << "Total empty cells: " << emptyCellsVector.size() << "\n";
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

void Solver::calculatePossibleValues()
{
	for (int i = 0; i < emptyCellsVector.size(); i++)
	{
		setPossibleValuesForCell(emptyCellsVector.at(i).getRow(), emptyCellsVector.at(i).getCol());
		emptyCellsVector.at(i).showPossibleVals();
	}
}

void Solver::setPossibleValuesForCell(int row, int col)
{			
		int k; // counter
		// check related row
		for (k = 0; k < 9; ++k)
		{
			if (k != col && m_matrix[row][k] != 0 )
			{
				std::cout << m_matrix[row][k] << "\n";
				emptyCellsVector.at(row).deletePossibleVal(m_matrix[row][k]);
			}
		}		

		// check related col

		// check related square	
}