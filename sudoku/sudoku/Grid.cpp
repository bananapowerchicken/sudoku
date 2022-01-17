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

void show2dArray(int* arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << *(arr + i * rows + j) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Grid::init()
{
	int grid[m_rows][m_cols];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = j + 1;
			//std::cout << grid[i][j] << " ";
		}
		//std::cout << "\n";
	}
	//std::cout << "\n";	

	shiftRightArray(grid[1], 9, 3);
	shiftRightArray(grid[2], 9, 6);
	shiftRightArray(grid[3], 9, 8);
	shiftRightArray(grid[4], 9, 2);
	shiftRightArray(grid[5], 9, 5);
	shiftRightArray(grid[6], 9, 7);
	shiftRightArray(grid[7], 9, 1);
	shiftRightArray(grid[8], 9, 4);

	std::cout << "Base matrix, start matrix:\n";
	show2dArray(grid[0], 9, 9);

	//m_cells_arr = grid;

	//return (int **)grid; // и шо это будет, и как оно будет работать?

}
