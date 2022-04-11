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
		// check related row
		std::cout << "cell: " << m_matrix[row][col] << "[" << row << "][" << col << "]\n";
		for (k = 0; k < 9; ++k)
		{
			if ( m_matrix[k][col] != 0 )
			{
				std::cout << "to delete : " << "[" << row << "][" << col << "] " << m_matrix[k][col] << "\n";
 				emptyCellsVector.at(cell_index).deletePossibleVal(m_matrix[k][row]); // 2nd cycle error here

			}
		}		

		// check related col

		// check related square	
}

void Solver::fillEmptyCells()
{
	if (!emptyCellsVector.size())
	{
		std::cout << "Sudoku is solved! :)\n";
	}
	else 
	{
		for (int i = 0; i < emptyCellsVector.size(); i++)
		{
			// если тут одно возможное значение для этой клетки - то его и поставить	
			if (emptyCellsVector.at(i).getNumOfPossibleVals() == 1)
			{		
				std::cout << "Cell [" << emptyCellsVector.at(i).getRow() << "][" << emptyCellsVector.at(i).getCol() << "]\n";
				std::cout << "The only variant is: " << emptyCellsVector.at(i).getPossibleValElement(0) << "\n";
			// заполняю матрицу	
				m_matrix[emptyCellsVector.at(i).getRow()][emptyCellsVector.at(i).getCol()] = emptyCellsVector.at(i).getPossibleValElement(0);
				emptyCellsVector.at(i).setValue(emptyCellsVector.at(i).getPossibleValElement(0), emptyCellsVector.at(i).getRow(), emptyCellsVector.at(i).getCol());
			// надо хорошенько продумать удаление, а то индекс соскальзывает и чтобы избежать рекурсии притом
			}			
		}
	
		// хочу моздать новый вектор, который будет типа урезанный старый
		std::vector <Cell> new_emptyCellsVector; // shorter
		for (int i = 0; i < emptyCellsVector.size(); i++)
		{
			if (emptyCellsVector.at(i).getNumOfPossibleVals() > 1)
			{
				new_emptyCellsVector.push_back(emptyCellsVector.at(i));
			}

		}
		emptyCellsVector = new_emptyCellsVector;
		new_emptyCellsVector.clear();
		fillEmptyCells();

		
	}	
}