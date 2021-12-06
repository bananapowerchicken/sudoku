#include <iostream>
#include "Cell.h"
#include "Square.h"
#include "Grid.h"
#include <time.h>
#include <algorithm>
#include <vector>

int main()
{
	//srand(time(NULL));// for truly randomizing
	int arr[5] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	shiftRightArray(arr, 5, 6);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	return 0;
}