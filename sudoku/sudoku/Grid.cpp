#include "Grid.h"
#include <iostream>

void shiftRightArray(int *arr, int size, int shift)
{
	if (shift >= size) shift = shift % size;

	int tmp;
	for (int j = 0; j < shift; j++)
	{
		for (int i = 0; i < size; i++)
			{
				tmp = *arr;
				*arr = *(arr + i);
				*(arr + i) = tmp;
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

	shiftRightArray(m_matrix[1], 9, 3);
	shiftRightArray(m_matrix[2], 9, 6);
	shiftRightArray(m_matrix[3], 9, 8);
	shiftRightArray(m_matrix[4], 9, 2);
	shiftRightArray(m_matrix[5], 9, 5);
	shiftRightArray(m_matrix[6], 9, 7);
	shiftRightArray(m_matrix[7], 9, 1);
	shiftRightArray(m_matrix[8], 9, 4);
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
