#pragma once
#include <vector>

class Cell 
{
private:
	int m_row;
	int m_col;
	int m_value;
	std::vector<int> m_possibleVals = {1, 2, 3, 4, 5, 6, 7, 8, 9};// должен быть еще массив либо вектор либо список доступных значений
	int deletePossibleVal(int val);

public:
	void setRow(int row) { m_row = row; };
	void setCol(int col) { m_col = col; };
	bool isSameSquare(int r, int c);
	int setValue(); // sets random value
};
