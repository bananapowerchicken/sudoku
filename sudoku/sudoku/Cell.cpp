#include "Cell.h"

bool Cell::isSameSquare(int row, int col)
{
	if (std::abs(row - m_row) > 2 || std::abs(col - m_col) > 2)
		return false;
	return true; 
}