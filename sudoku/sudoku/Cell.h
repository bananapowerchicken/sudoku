#pragma once
#include <vector>
#include <iostream>

class Cell 
{
private:
	int m_row;
	int m_col;
	int m_value = 0;
	//int m_max_row;
	//int m_max_col;
	//int m_sq;
	std::vector<int> m_possibleVals = {1, 2, 3, 4, 5, 6, 7, 8, 9};// ������ ���� ��� ������ ���� ������ ���� ������ ��������� ��������
	
	//int findMaxSquareCoords();
	//void setRow(int row) { m_row = row; };
	//void setCol(int col) { m_col = col; };
	//	
	//void setSquare();

public:
	Cell(int row, int col) { m_row = row; m_col = col; };
	//int getValue() { return m_value; };
	void showPossibleVals();
	int deletePossibleVal(int val);
	void setValue(int val, int i, int j) { m_value = val; m_row = i; m_col = j; };
	int getRow() { return m_row; };
	int getCol() { return m_col; };
	int getNumOfPossibleVals() { return m_possibleVals.size(); };
	int getPossibleValElement(int i) { return m_possibleVals.at(i); };
	//void setPossibleVals(); // many deletions
	//bool init(int i, int j);
	//int setRandomValue(); // sets random value	
	//int getVecLen() { return m_possibleVals.size(); }
	//int getMaxRow() { return m_max_row; };
	//int getMaxCol() { return m_max_col; };
	//int getSq() { return m_sq; };
	//bool isSameSquare(int r, int c);
};
