#include <iostream>
#include "Cell.h"
#include "Square.h"
#include "Grid.h"
#include <time.h>
#include <algorithm>
#include <vector>

//// swap rows in the same BigRow (0 1 2, 3 4 5 , 6 7 8 - three Big Rows)
//int swapRows(int* arr1, int* arr2, int row1, int row2)
//{
//	if (row1 / 3 != row2 / 3)
//	{
//		std::cout << "error - this small rows cannot be swapped\n";
//		return -1;
//	}
//
//	int tmp;
//	for (int i = 0; i < 9; i++)
//	{
//		tmp = *(arr1 + i);
//		*(arr1 + i) = *(arr2 + i);
//		*(arr2 + i) = tmp;
//	}
//
//	return 0;
//}
//
//// should work on it properly
//int swapCols(int* arr1, int* arr2, int col1, int col2)
//{
//	if (col1 / 3 != col2 / 3)
//	{
//		std::cout << "error - this small cols cannot be swapped\n";
//		return -1;
//	}
//
//	int tmp;
//	for (int i = 0; i < 9; i++)
//	{
//		tmp = *(arr1 + i);
//		*(arr1 + i) = *(arr2 + i);
//		*(arr2 + i) = tmp;
//	}
//
//	return 0;
//}

int main()
{
	//srand(time(NULL));// for truly randomizing

	Grid grid;
	grid.init();
	grid.show();


	return 0;
}