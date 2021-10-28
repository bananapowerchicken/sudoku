#include "Cell.h"
#include <iostream>
#include <time.h>

// неполное покрытие
bool Cell::isSameSquare(int row, int col)
{
	if (row < 0 || col < 0)
		return false;

	if ( (row/3 != m_row/3) || (col/3 != m_col/3) )
		return false;

	return true; 
}

// rand() % (b - a + 1) + a
int Cell::setValue()
{
	int ind = rand() % m_possibleVals.size(); // в диапазоне длины вектора (которая уменьшается)
	m_value = m_possibleVals[ind];	
	//std::cout << "set value = " << m_value << " with random index = " << ind << "\n";

	return ind; // index to delete for other cells
}

// что за индекс?
int Cell::deletePossibleVal(int val)
{
	std::vector<int>::iterator it = std::find(m_possibleVals.begin(), m_possibleVals.end(), val);
	if (it != m_possibleVals.end())
		m_possibleVals.erase(it);

	//std::cout << "vector size = " << m_possibleVals.size() << "\n";
	//std::cout << "i = " << m_row << " j = " << m_col << "\n";
	//std::cout << "myvector contains:";
	//for (unsigned i = 0; i < m_possibleVals.size(); ++i)
	//	std::cout << ' ' << m_possibleVals[i];
	//std::cout << '\n';

	return 0;
}

int Cell::findMaxSquareCoords()
{
	// i
	if (this->isSameSquare(m_row - 2, m_col))
		m_max_row = m_row;
	else if (this->isSameSquare(m_row + 2, m_col))
		m_max_row = m_row + 2;
	else
		m_max_row = m_row + 1;

	// j
	if (this->isSameSquare(m_row, m_col - 2))
		m_max_col = m_col;
	else if (this->isSameSquare(m_row, m_col + 2))
		m_max_col = m_col + 2;
	else
		m_max_col = m_col + 1;



	return 0;
}

void Cell::setSquare()
{
	if (m_row >= 0 && m_row <= 2) {
		if (m_col >= 0 && m_col <= 2) {
			m_sq = 0;
		}
		if (m_col >= 3 && m_col <= 5) {
			m_sq = 1;
		}
		if (m_col >= 6 && m_col <= 8) {
			m_sq = 3;
		}
	}

	if (m_row >= 3 && m_row <= 5) {
		if (m_col >= 0 && m_col <= 2) {
			m_sq = 3;
		}
		if (m_col >= 3 && m_col <= 5) {
			m_sq = 4;
		}
		if (m_col >= 6 && m_col <= 8) {
			m_sq = 5;
		}
	}

	if (m_row >= 6 && m_row <= 8) {
		if (m_col >= 0 && m_col <= 2) {
			m_sq = 6;
		}
		if (m_col >= 3 && m_col <= 5) {
			m_sq = 7;
		}
		if (m_col >= 6 && m_col <= 8) {
			m_sq = 8;
		}
	}
}

bool Cell::init(int i, int j)
{
	// задает координаты
	// вычисляет максим координаты квадрата, чтобы в дальнейшем исключать лишние возможные значения в квадрате

	setRow(i);
	setCol(j);	
	//setSquare();

	findMaxSquareCoords();
	
	return true;
}