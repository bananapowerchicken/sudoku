#pragma once
#include <vector>

class Cell 
{
private:
	int m_row;
	int m_col;
	int m_value;
	std::vector<int> m_possibleVals;// ������ ���� ��� ������ ���� ������ ���� ������ ��������� ��������

public:
	void setRow(int row) { m_row = row; };
	void setCol(int col) { m_col = col; };
	bool isSameSquare(int r, int c);

};
