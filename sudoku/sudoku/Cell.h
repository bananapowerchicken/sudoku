#pragma once
#include <vector>
#include <iostream>

class Cell 
{
private:
	int m_row;
	int m_col;
	int m_value = 0;
	int m_max_row;
	int m_max_col;
	int m_sq;
	std::vector<int> m_possibleVals = {1, 2, 3, 4, 5, 6, 7, 8, 9};// ������ ���� ��� ������ ���� ������ ���� ������ ��������� ��������
	int findMaxSquareCoords();
	void setRow(int row) { m_row = row; };
	void setCol(int col) { m_col = col; };
	bool isSameSquare(int r, int c);	
	void setSquare();

public:
	int getValue() { return m_value; };
	int deletePossibleVal(int val);
	bool init(int i, int j);
	int setValue(); // sets random value
	int getVecLen() { return m_possibleVals.size(); }
	int getMaxRow() { return m_max_row; };
	int getMaxCol() { return m_max_col; };
	int getSq() { return m_sq; };
	
};
