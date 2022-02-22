#include "Cell.h"
//#include <time.h>
//
//// неполное покрытие
//bool Cell::isSameSquare(int row, int col)
//{
//	if (row < 0 || col < 0)
//		return false;
//
//	if ( (row/3 != m_row/3) || (col/3 != m_col/3) )
//		return false;
//
//	return true; 
//}
//
//// rand() % (b - a + 1) + a
//int Cell::setRandomValue()
//{
//	int ind = rand() % m_possibleVals.size(); // в диапазоне длины вектора (которая уменьшается)
//	m_value = m_possibleVals[ind];	
//	//std::cout << "set value = " << m_value << " with random index = " << ind << "\n";
//	m_possibleVals.clear();
//	m_possibleVals = { m_value };
//	return ind; // index to delete for other cells
//}
//
//// что за индекс?
int Cell::deletePossibleVal(int val)
{
	if (m_possibleVals.size() < 1)
		return -1;

	for (int i = 0; i < m_possibleVals.size(); i++)
	{
		if (m_possibleVals[i] == val)
		{
			m_possibleVals.erase(m_possibleVals.begin() + i);
			break;
		}
	}
//
//	//std::cout << "vector size = " << m_possibleVals.size() << "\n";
//	//std::cout << "i = " << m_row << " j = " << m_col << "\n";
//	//std::cout << "myvector contains:";
//	//for (unsigned i = 0; i < m_possibleVals.size(); ++i)
//	//	std::cout << ' ' << m_possibleVals[i];
//	//std::cout << '\n';
//
	return 0;
}

void Cell::showPossibleVals()
{
	std::cout << "vector size = " << m_possibleVals.size() << "\n";
	std::cout << "possible values:";
	for (unsigned i = 0; i < m_possibleVals.size(); ++i)
		std::cout << ' ' << m_possibleVals[i];
	std::cout << '\n';
}

//void Cell::setPossibleVals()
//{
//	int k; // counter
//	// check realted row
//	for (k = 0; k < 9; ++k)
//	{
//		if (k != m_row)
//		{
//
//		}
//	}
//
//	// check related col
//
//	// check related square
//}

//
//int Cell::findMaxSquareCoords()
//{
//	// i
//	m_max_row = m_row + 2 - m_row % 3;
//
//	// j
//	m_max_col = m_col + 2 - m_col % 3;
//
//	//std::cout << "i = " << m_row << " i_max = " << m_max_row << "\n";
//	//std::cout << "j = " << m_col << " j_max = " << m_max_col << "\n";
//
//	return 0;
//}
//
//void Cell::setSquare()
//{
//	if (m_row >= 0 && m_row <= 2) {
//		if (m_col >= 0 && m_col <= 2) {
//			m_sq = 0;
//		}
//		if (m_col >= 3 && m_col <= 5) {
//			m_sq = 1;
//		}
//		if (m_col >= 6 && m_col <= 8) {
//			m_sq = 3;
//		}
//	}
//
//	if (m_row >= 3 && m_row <= 5) {
//		if (m_col >= 0 && m_col <= 2) {
//			m_sq = 3;
//		}
//		if (m_col >= 3 && m_col <= 5) {
//			m_sq = 4;
//		}
//		if (m_col >= 6 && m_col <= 8) {
//			m_sq = 5;
//		}
//	}
//
//	if (m_row >= 6 && m_row <= 8) {
//		if (m_col >= 0 && m_col <= 2) {
//			m_sq = 6;
//		}
//		if (m_col >= 3 && m_col <= 5) {
//			m_sq = 7;
//		}
//		if (m_col >= 6 && m_col <= 8) {
//			m_sq = 8;
//		}
//	}
//}
//
//bool Cell::init(int i, int j)
//{
//	// задает координаты
//	// вычисляет максим координаты квадрата, чтобы в дальнейшем исключать лишние возможные значения в квадрате
//
//	setRow(i);
//	setCol(j);	
//
//	findMaxSquareCoords();
//	
//	return true;
//}
//
