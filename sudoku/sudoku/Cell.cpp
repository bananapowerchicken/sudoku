#include "Cell.h"
#include <iostream>
#include <time.h>

bool Cell::isSameSquare(int row, int col)
{
	if (std::abs(row - m_row) > 2 || std::abs(col - m_col) > 2)
		return false;
	return true; 
}

// rand() % (b - a + 1) + a
int Cell::setValue()
{
	srand(time(NULL)); // for truly randomizing
	int ind = rand() % m_possibleVals.size(); // в диапазоне длины вектора (которая уменьшается)
	m_value = m_possibleVals[ind];
	std::cout << "set value = " << m_value << " with random index = " << ind << "\n";

	return ind; // index to delete for other cells
}

int Cell::deletePossibleVal(int ind)
{
	m_possibleVals.erase(m_possibleVals.begin() + ind);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < m_possibleVals.size(); ++i)
		std::cout << ' ' << m_possibleVals[i];
	std::cout << '\n';

	return 0;
}