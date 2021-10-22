#include <iostream>
#include "Cell.h"

int main()
{
	Cell c;
	c.setRow(2);
	c.setCol(7);
	std::cout << c.isSameSquare(2, 2) << "\n";

	return 0;
}