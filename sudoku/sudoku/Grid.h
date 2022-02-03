#pragma once

void shiftRightArray(int* arr, int size, int shift);

class Grid
{
private:
	static const int m_rows = 9; // firstly hardcoded
	static const int m_cols = 9; // need to be static since it must be the same
	// for every instance of this class - it is needed to compilate
	int m_matrix[m_rows][m_cols];

	// all shifts - matrix metamorphoses
	void m_rightShiftRow(int row_index, int shift);
	void swapAnyRows(int row1, int row2);
	void swapAnyCols(int col1, int col2);

public:
	// creates the base matrix with required start shifts
	// what should be the input? or nothing in, but the grid must be out
	void init();
	void show();
	void transpose();
	void swapRowsSmall(int row1, int row2);
	void swapColsSmall(int col1, int col2);
	void swapRowsSmallRandom();
	void swapColsSmallRandom();
	void swapRowsBig(int district1, int disctrict2);
	void swapColsBig(int district1, int disctrict2);
};

