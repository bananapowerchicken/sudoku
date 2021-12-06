#include "Grid.h"

void shiftArray(int *arr, int size, int shift)
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

}
