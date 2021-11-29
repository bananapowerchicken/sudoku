#include <iostream>
#include "Cell.h"
#include "Square.h"
#include <time.h>
#include <algorithm>
#include <vector>

int main()
{
	//srand(time(NULL));// for truly randomizing
	Square sq[9];
	for (int i = 0; i < 9; i++)
	{
		sq[i].init(i);
	}

	Cell arr[9][9];	
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j].init(i, j);
		}			
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++) // go throw row - need row without repeats
			{				
					arr[i][j].deletePossibleVal(arr[i][k].getValue());					
				
			}
			arr[i][j].setRandomValue();	
			std::cout << arr[i][j].getValue() << " ";
		}
		std::cout << "\n";
	}
	
	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		std::cout << arr[i][j].getValue() << " ";
	//	}
	//	std::cout << "\n";
	//}
	

	return 0;
}