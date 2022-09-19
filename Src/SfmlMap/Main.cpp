#include "BackingGrid.h"
#include "PoissonSampler.h"
#include "DbPoint.h"

int main()
{
	BackingGrid backingGrid = BackingGrid::BackingGrid(10, 10, 1.0);
	PoissonSampler poissonSampler = PoissonSampler::PoissonSampler(backingGrid, 20);
	std::vector<DbPoint> points = poissonSampler.sample();
	return 0;
}