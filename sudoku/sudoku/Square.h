#pragma once

#include <vector>

class Square
{
private:
	std::vector<int> m_i_possible;
	std::vector<int> m_j_possible;
	int m_id; // 1 - 9

public:
	int getId() { return m_id; }
	int editPossibles(int i, int j); // only after filling target cell and for use for other adjacent squares
	std::vector<int> getPossibleRows() { return m_i_possible; };
	std::vector<int> getPossibleCols() { return m_j_possible; };
	void init(int id);
};