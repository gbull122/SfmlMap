#ifndef BACKINGGRID_H
#define BACKINGGRID_H

#include <vector>
#include <stdexcept>
#include <cmath>

#include "IntPoint.h"

class BackingGrid
{
public:
	BackingGrid();
	BackingGrid(int height, int width, double r);
	int height;
	int width;
	double r;
	void SetCell(int row, int col, int value);
	int GetCellValue(double x, double y);
	bool containsPoint(double x, double y);
	int GetCellRow(double x, double y);
	int GetCellColumn(double x, double y);

private:
	double cellSize;
	int rows;
	int columns;
	std::vector<int> cells;

};

#endif