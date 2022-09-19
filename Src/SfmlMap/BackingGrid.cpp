#include "BackingGrid.h"

BackingGrid::BackingGrid() {}

BackingGrid::BackingGrid(int height, int width, double r)
{
	this->height = height;
	this->width = width;
	this->r = r;
	this->cellSize = r/sqrt(2);

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

int BackingGrid::GetCellValue(double x, double y)
{
	if (x < 0 || x > height || y < 0 || y > width) 
	{
		throw std::range_error("GetCellValue");
	}

	int row = (int)floor(x / cellSize);
	int col = (int)floor(y / cellSize);
	return cells[row + col * columns];
}

int BackingGrid::GetCellRow(double x, double y)
{
	if (x < 0 || x > height || y < 0 || y > width) {
		throw std::range_error("GetCellRow");
	}
	return (int)floor(x / cellSize);
}

int BackingGrid::GetCellColumn(double x, double y)
{
	if (x < 0 || x > height || y < 0 || y > width) {
		throw std::range_error("GetCellRow");
	}
	return (int)floor(y / cellSize);
}

bool BackingGrid::containsPoint(double x, double y)
{
	if (x > 0 || x <= height || y > 0 || y <= width) {
		return true;
	}
	return false;
}
