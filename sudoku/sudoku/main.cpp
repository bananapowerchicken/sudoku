#include <iostream>
#include "Cell.h"
#include "Square.h"
#include "Grid.h"
#include <time.h>
#include <algorithm>
#include <vector>

//void show2dArray(int* arr, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			std::cout << *(arr + i*rows + j) << " ";
//		}
//		std::cout << "\n";
//	}
//	std::cout << "\n";
//}

// swap rows in the same BigRow (0 1 2, 3 4 5 , 6 7 8 - three Big Rows)
int swapRows(int* arr1, int* arr2, int row1, int row2)
{
	if (row1 / 3 != row2 / 3)
	{
		std::cout << "error - this small rows cannot be swapped\n";
		return -1;
	}

	int tmp;
	for (int i = 0; i < 9; i++)
	{
		tmp = *(arr1 + i);
		*(arr1 + i) = *(arr2 + i);
		*(arr2 + i) = tmp;
	}

	return 0;
}

// should work on it properly
int swapCols(int* arr1, int* arr2, int col1, int col2)
{
	if (col1 / 3 != col2 / 3)
	{
		std::cout << "error - this small cols cannot be swapped\n";
		return -1;
	}

	int tmp;
	for (int i = 0; i < 9; i++)
	{
		tmp = *(arr1 + i);
		*(arr1 + i) = *(arr2 + i);
		*(arr2 + i) = tmp;
	}

	return 0;
}

int main()
{
	//srand(time(NULL));// for truly randomizing
	
	//int grid[9][9];
	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		grid[i][j] = j + 1;
	//		//std::cout << grid[i][j] << " ";
	//	}
	//	//std::cout << "\n";
	//}
	////std::cout << "\n";	
	// 
	//// Жесткий костыль!!!
	//shiftRightArray(grid[1], 9, 3);
	//shiftRightArray(grid[2], 9, 6);
	//shiftRightArray(grid[3], 9, 8);
	//shiftRightArray(grid[4], 9, 2);
	//shiftRightArray(grid[5], 9, 5);
	//shiftRightArray(grid[6], 9, 7);
	//shiftRightArray(grid[7], 9, 1);
	//shiftRightArray(grid[8], 9, 4);

	Grid grid;
	grid.init();

	/*std::cout << "Base matrix, start matrix:\n";
	show2dArray(grid[0], 9, 9);*/

	/*swapRows(grid[0], grid[3], 0, 3);
	show2dArray(grid[0], 9, 9);*/

	//swapCols(grid[0] + 1, grid[3] + 2, 1, 2); // 1 and 2 cols should be swapped here
	//show2dArray(grid[0], 9, 9);

	return 0;
}