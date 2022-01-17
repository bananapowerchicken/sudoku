#pragma once

void shiftRightArray(int* arr, int size, int shift);

class Grid
{
private:
	static const int m_rows = 9; // firstly hardcoded
	static const int m_cols = 9; // need to be static since it must be the same
	// for every instance of this class - it is needed to compilate
	int m_cells_arr[m_rows][m_cols];
public:
	// creates the base matrix with required start shifts
	// what should be the input? or nothing in, but the grid must be out
	void init();
};

