#include <iostream>
#include "Cell.h"
#include <time.h>
#include <algorithm>
#include <vector>

int main()
{
	srand(time(NULL));// for truly randomizing

	// ������� ������ ������ ������
	// �������� ���� ������
	// ��������� �� ����, ���� ������ - ������
	int ind = -1;
	int prev_i;
	int prev_j;
	Cell arr[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j].init(i, j);
			// ������-�� ��������� ��� ����������� ����������
			std::cout << arr[i][j].getValue() << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j].setValue();
			// ������-�� ��������� ��� ����������� ����������
			std::cout << arr[i][j].getValue() << " ";

			// �������� ��������� �������� �� ������� ������ , ���� ������ �� ����� ������� ��� ��� �����
			
			// ������� �����
			for (int ii = 0; ii < 9; ii++)
			{
				if (i != ii && arr[ii][j].getVecLen() > 1)
				{
					arr[ii][j].deletePossibleVal(arr[i][j].getValue());
				}
			}

			// ������� ������
			for (int jj = 0; jj < 9; jj++)
			{
				if (j != jj && arr[i][jj].getVecLen() > 1)
				{
					arr[i][jj].deletePossibleVal(arr[i][j].getValue());
				}
			}

			// ������� �������
			for (int iii = arr[i][j].getMaxRow() - 2; iii <= arr[i][j].getMaxRow(); iii++)
			{
				for (int jjj = arr[i][j].getMaxCol() - 2; jjj <= arr[i][j].getMaxCol(); jjj++)
				{
					if (iii != i && jjj != j) {
						arr[iii][jjj].deletePossibleVal(arr[i][j].getValue());
					}
				}
			}

		} 
		std::cout << "\n";
	}




	return 0;
}