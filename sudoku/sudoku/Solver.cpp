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
		setPossibleValuesForCell(emptyCellsVector.at(i).getRow(), emptyCellsVector.at(i).getCol(), i);
		std::cout << "num vector: " << i << "\n";
		emptyCellsVector.at(i).showPossibleVals();	
		
	}
}

void Solver::setPossibleValuesForCell(int row, int col, int cell_index)
{			
		int k; // counter
		// check related col
		std::cout << "Check related col\n";
		std::cout << "cell: " << m_matrix[row][col] << "[" << row << "][" << col << "]\n";
		for (k = 0; k < 9; ++k)
		{
			if ( m_matrix[k][col] != 0 )
			{
				std::cout << "to delete : " << "[" << row << "][" << col << "] " << m_matrix[k][col] << "\n";				
				emptyCellsVector.at(cell_index).deletePossibleVal(m_matrix[k][col]);
			}
		}

		// check related row
		std::cout << "Check related row\n";
		for (k = 0; k < 9; ++k)
		{
			if (m_matrix[row][k] != 0)
			{
				std::cout << "to delete : " << "[" << row << "][" << col << "] " << m_matrix[row][k] << "\n";
				emptyCellsVector.at(cell_index).deletePossibleVal(m_matrix[row][k]);
			}
		}

		// check related square	
		std::cout << "Check related square\n";
		int i_min = row / 3 * 3; // min row in square
		int j_min = col / 3 * 3; // min col in square
		for (int i = i_min; i < i_min + 3; i++)
		{
			for (int j = j_min; j < j_min + 3; j++)
			{
				if (m_matrix[i][j] != 0)
				{
					std::cout << "to delete : " << "[" << row << "][" << col << "] " << m_matrix[i][j] << "\n";
					emptyCellsVector.at(cell_index).deletePossibleVal(m_matrix[i][j]);
				}
			}
		}

}

void Solver::fillEmptyCells()
{
	if (!emptyCellsVector.size())
	{
		std::cout << "Sudoku is solved! :)\n";
	}
	else 
	{	// заполн€ю однозначные клетки
		for (int i = 0; i < emptyCellsVector.size(); i++)
		{
			if (emptyCellsVector.at(i).getNumOfPossibleVals() == 1)
			{
				m_matrix[emptyCellsVector.at(i).getRow()][emptyCellsVector.at(i).getCol()] = emptyCellsVector.at(i).getPossibleValElement(0);
			}
		}
		//fillEmptyCells();		
	}	
}