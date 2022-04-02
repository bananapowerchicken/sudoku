#include "Grid.h"
#include <iostream>
#include <vector>
#include <time.h>

Grid::Grid()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			m_matrix[i][j] = j + 1;
		}
	}

	m_rightShiftRow(1, 6);
	m_rightShiftRow(2, 3);
	m_rightShiftRow(3, 8);
	m_rightShiftRow(4, 5);
	m_rightShiftRow(5, 2);
	m_rightShiftRow(6, 7);
	m_rightShiftRow(7, 4);
	m_rightShiftRow(8, 1);

	// debug - artificial fixed putting zeros in some positions
	m_matrix[0][0] = 0;
	m_matrix[2][1] = 0;
	m_matrix[2][2] = 0;
	m_matrix[7][3] = 0;
	m_matrix[7][4] = 0;
	m_matrix[7][5] = 0;
}

void Grid::m_rightShiftRow(int row_index, int shift)
{
	int row_len = m_cols;
	if (shift >= row_len) shift = shift % row_len;

	int tmp;
	for (int j = 0; j < shift; j++)
	{
		for (int i = 0; i < row_len; i++)
		{
			tmp = *m_matrix[row_index];
			*m_matrix[row_index] = *(m_matrix[row_index] + i);
			*(m_matrix[row_index] + i) = tmp;
		}
	}
}

void Grid::swapAnyRows(int row1, int row2)
{
	int tmp;
	for (int i = 0; i < m_cols; i++)
	{
		tmp = m_matrix[row1][i];
		m_matrix[row1][i] = m_matrix[row2][i];
		m_matrix[row2][i] = tmp;
	}
}

void Grid::swapAnyCols(int col1, int col2)
{
	int tmp;
	for (int i = 0; i < m_rows; i++)
	{
		tmp = m_matrix[i][col1];
		m_matrix[i][col1] = m_matrix[i][col2];
		m_matrix[i][col2] = tmp;
	}
}

void Grid::show()
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

void Grid::transpose()
{
	int new_matrix[m_cols][m_rows];
	for (int i = 0; i < m_cols; i++)
	{
		for (int j = 0; j < m_rows; j++)
		{
			new_matrix[i][j] = m_matrix[j][i];			
		}		
	}

	// no need to swap rows and cols since they are equal
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			m_matrix[i][j] = new_matrix[i][j];
		}
	}
}

void Grid::swapRowsSmall(int row1, int row2)
{
	if (row1 / 3 != row2 / 3) {
		std::cout << "Error. Chosen rows are from different districts.\n";
	}
	else {
		swapAnyRows(row1, row2);
	}
}

void Grid::swapColsSmall(int col1, int col2)
{
	if (col1 / 3 != col2 / 3) {
		std::cout << "Error. Chosen cols are from different districts.\n";
	}
	else {
		swapAnyCols(col1, col2);
	}
}

void Grid::swapRowsSmallRandom()
{
	// по идее тут надо выбирать райончик, но тогда
	// но тогда теряется фикс-идея случайности, если 
	// район делать аргументом - бу - надо подумать

	// и этот дубль код лучше вынести тоже в отдельную ф-ю
	
	int districtRandom = rand() % 3 + 0;
	int row1Random = (rand() % 3 + 0) + districtRandom * 3;
	int row2Random = (rand() % 3 + 0) + districtRandom * 3;
	std::cout << districtRandom << " "<< row1Random << " " << row2Random << "\n";
	swapRowsSmall(row1Random, row2Random);
}

void Grid::swapColsSmallRandom()
{
	// по идее тут надо выбирать райончик, но тогда
	// но тогда теряется фикс-идея случайности, если 
	// район делать аргументом - бу - надо подумать
	
	int districtRandom = rand() % 3 + 0;
	int col1Random = (rand() % 3 + 0) + districtRandom * 3;
	int col2Random = (rand() % 3 + 0) + districtRandom * 3;
	std::cout << districtRandom << " " << col1Random << " " << col2Random << "\n";
	swapColsSmall(col1Random, col2Random);
}

void Grid::swapRowsBig(int d1, int d2)
{
	// 3 would not be hardcoded better, but i'm too lazy now
	for (int i = 0; i < 3; i++)
	{
		swapAnyRows(d1 * 3 + i, d2 * 3 + i);
	}
}

void Grid::swapColsBig(int d1, int d2)
{
	// 3 would not be hardcoded better, but i'm too lazy now
	for (int i = 0; i < 3; i++)
	{
		swapAnyCols(d1 * 3 + i, d2 * 3 + i);
	}
}

void Grid::swapRowsBigRandom()
{
	int district1Random = rand() % 3 + 0;
	int district2Random = rand() % 3 + 0;
	std::cout << district1Random << " " << district2Random << "\n";
	swapRowsBig(district1Random, district2Random);
}

void Grid::swapColsBigRandom()
{
	int district1Random = rand() % 3 + 0;
	int district2Random = rand() % 3 + 0;
	std::cout << district1Random << " " << district2Random << "\n";
	swapColsBig(district1Random, district2Random);
}

void Grid::shakeGrid(int n)
{
	if (n < 0)
	{
		std::cout << "nothing is done since n must be >= 0\n";
		return;
	}
		
	std::vector <int> swapVars(n);
	for (int i = 0; i < n; i++)
	{
		swapVars[i] = rand() % 5 + 0;
		std::cout << "swap num = " << swapVars[i] << "\n";

		switch (swapVars[i])
		{
		case 0:
			this->transpose();
			this->show();
			break;
		case 1:
			this->swapRowsSmallRandom();
			this->show();
			break;
		case 2:
			this->swapColsSmallRandom();
			this->show();
			break;
		case 3:
			this->swapRowsBigRandom();
			this->show();
			break;
		case 4:
			this->swapColsBigRandom();
			this->show();
			break;
		}
	}
	std::cout << "\n";

	
}

void Grid::getMatrix(int** matrix)
{
	// need to copy m_matrix to matrix
}

int Grid::getElement(int row, int col)
{
	// don't like this check and magic numbers
	// TODO: need more elegance
	if (row >= 0 && col >= 0 && row < 9 && col < 9)
	{
		int element = m_matrix[row][col];
		return element;
	}
	else 
	{
		// TODO: system exit?
		std::cout << "row or col is out of range\n"; 
		return -1;
	}

}