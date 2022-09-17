#ifndef BACKINGGRID_H
#define BACKINGGRID_H

#include <vector>
#include <stdexcept>
#include <cmath>

#include "Point.h"

class BackingGrid
{
public:
	BackingGrid(int height, int width, double cellSize);
	void SetCell(int row, int col, int value);
	int GetCell(double x, double y);

private:
	int height;
	int width;
	double cellSize;
	int rows;
	int columns;
	std::vector<int> cells;

};

#endif