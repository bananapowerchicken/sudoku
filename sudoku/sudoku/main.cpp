#include <iostream>
#include "Cell.h"
#include "Square.h"
#include <time.h>
#include <algorithm>
#include <vector>

int main()
{
	//srand(time(NULL));// for truly randomizing
	Square sq;
	for (int i = 0; i < 9; i++)
	{
		sq.init(i);
	}
	

	return 0;
}