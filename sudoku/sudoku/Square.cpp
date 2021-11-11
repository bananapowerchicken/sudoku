#include "Square.h"

int Square::editPossibles(int k, int j)
{
	// here should deleting i and j from possoble vectors
	for (int i = 0; i < m_i_possible.size(); i++)
	{
		if (m_i_possible[i] == k)
		{
			m_i_possible.erase(m_i_possible.begin() + k);
			break;
		}
	}

	for (int i = 0; i < m_i_possible.size(); i++)
	{
		if (m_j_possible[i] == j)
		{
			m_j_possible.erase(m_j_possible.begin() + j);
			break;
		}
	}

	return 0;
}

void Square::init(int id)
{
	m_id = id;

	int Z = id / 3; // whole part of division
	int R = id % 3; // remainder of the division

	// add checking wheter id is not ok
	switch (Z)
	{
	case 0:
		m_i_possible = { 0, 1, 2 };
		break;
	case 1:
		m_i_possible = { 3, 4, 5 };
		break;
	case 2:
		m_i_possible = { 6, 7, 8 };
		break;
	}

	switch (R)
	{
	case 0:
		m_j_possible = { 0, 1, 2 };
		break;
	case 1:
		m_j_possible = { 3, 4, 5 };
		break;
	case 2:
		m_j_possible = { 6, 7, 8 };
		break;
	}
}