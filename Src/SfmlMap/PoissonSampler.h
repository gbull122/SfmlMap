#ifndef POISSONSAMPLER_H
#define POISSONSAMPLER_H

#include <vector>

#include "Point.h"

class PoissonSampler
{
public:
	PoissonSampler(int height, int width, double r, int k);

	std::vector<Point> sample();

private:
	int k;
	double dx;
	int height;
	int width;

	double randomDouble(double min, double max);
	int randomRange(int min, int max);
	Point randomPoint();
};

#endif
