#include "BackingGrid.h"
#include "PoissonSampler.h"
#include "DbPoint.h"

int main()
{
	BackingGrid backingGrid = BackingGrid::BackingGrid(100, 100, 1.0);
	PoissonSampler poissonSampler = PoissonSampler::PoissonSampler(backingGrid, 20);
	std::vector<DbPoint> points = poissonSampler.sample();
	return 0;
}