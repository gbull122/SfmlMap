#include "BackingGrid.h"

BackingGrid::BackingGrid(int height, int width, double cellSize)
{
	this->height = height;
	this->width = width;
	this->cellSize = cellSize;

	this->columns = (int)ceil(this->width / cellSize);
	this->rows = (int)ceil(this->height / cellSize);
	this->cells = std::vector<int>(rows * columns);
}

void BackingGrid::SetCell(int row, int col, int value)
{
	if (row < 0 || row > rows || col < 0 || col > columns) {
		throw std::range_error("SetCell");
	}
	cells[row + col * columns] = value;
}

int BackingGrid::GetCell(double x, double y)
{
	if (x < 0 || x > height || y < 0 || y > width) {
		throw std::range_error("GetCell");
	}
	int row = (int)floor(x / cellSize);
	int col = (int)floor(y / cellSize);
	return cells[row + col * columns];
	return 0;
}
