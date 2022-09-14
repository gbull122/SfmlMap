#ifndef BACKINGGRID_H
#define BACKINGGRID_H

#include <vector>

#include "Point.h"

class BackingGrid
{
public:


private:
	int height;
	int width;
	double cellSize;

	std::vector<Point> points;

};

#endif