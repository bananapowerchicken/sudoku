#include <iostream>
#include "Cell.h"
#include "Square.h"
#include "Grid.h"
#include <time.h>
#include <algorithm>
#include <vector>

int main()
{
	srand(time(NULL));// for truly randomizing

	Grid grid;
	grid.init();
	grid.show();
	grid.swapColsBigRandom();
	grid.show();
	//grid.swapRowsSmallRandom();
	//grid.show();
	//grid.swapColsSmallRandom();
	//grid.show();

	/*grid.transpose();
	grid.show();*/
	//
	//grid.swapRowsSmall(1, 2);
	//grid.show();
	//grid.swapColsSmall(4, 3);
	//grid.show();

	//grid.swapColsBig(2, 1);
	//grid.show();

	return 0;
}