#ifndef POISSONSAMPLER_H
#define POISSONSAMPLER_H

#include <vector>
#include <cmath>

#include "DbPoint.h"
#include "BackingGrid.h"

class PoissonSampler
{
public:
	PoissonSampler(BackingGrid backingGrid, int k);

	std::vector<DbPoint> sample();

private:
	int k;
	double dx;
	BackingGrid backingGrid;

	double randomDouble(double min, double max);
	int randomRange(int min, int max);
	DbPoint randomPoint();
	DbPoint randomDiscPoint(DbPoint center);
	bool findDiscPoint(DbPoint center, std::vector<DbPoint>& points, DbPoint* p);
	bool isSampleValid(DbPoint& p, std::vector<DbPoint>& points);
};

#endif