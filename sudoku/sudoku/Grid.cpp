#include "Grid.h"
#include <iostream>

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

void Grid::init()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			m_matrix[i][j] = j + 1;
		}
		
	}	

	m_rightShiftRow(1, 3);
	m_rightShiftRow(2, 6);
	m_rightShiftRow(3, 8);
	m_rightShiftRow(4, 2);
	m_rightShiftRow(5, 5);
	m_rightShiftRow(6, 7);
	m_rightShiftRow(7, 1);
	m_rightShiftRow(8, 4);
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
}
