#include "PoissonSampler.h"

PoissonSampler::PoissonSampler(BackingGrid backingGrid, int k)
{
	this->backingGrid = backingGrid;
	this->k = k;
}

std::vector<DbPoint> PoissonSampler::sample()
{
	DbPoint seed = randomPoint();
	std::vector<DbPoint> points;
	points.push_back(seed);

	std::vector<int> activeList;
	activeList.push_back(0);

	backingGrid.SetCell(seed.x, seed.y, 0);

	while (!activeList.empty()) {
		int randidx = randomRange(0, activeList.size());
		int pidx = activeList[randidx];
		DbPoint p = points[pidx];

		DbPoint newPoint;
		bool isFound = findDiscPoint(p, points, &newPoint);

		if (!isFound) {
			activeList.erase(activeList.begin() + randidx);
			continue;
		}

		int newidx = points.size();
		activeList.push_back(newidx);
		points.push_back(newPoint);

		backingGrid.SetCell(newPoint.x, newPoint.y, newidx);
	}

	return points;
}

bool PoissonSampler::findDiscPoint(DbPoint center,
	std::vector<DbPoint>& points, DbPoint* p)
{
	for (int i = 0; i < k; i++) {
		DbPoint sample = randomDiscPoint(center);
		if (!backingGrid.containsPoint(sample.x, sample.y)) {
			continue;
		}

		if (isSampleValid(sample, points)) {
			*p = sample;
			return true;
		}
	}

	return false;
}

bool PoissonSampler::isSampleValid(DbPoint& p, std::vector<DbPoint>& points)
{
	int sampleid = backingGrid.GetCellValue(p.x, p.y);
	if (sampleid != -1) {
		return false;
	}

	if (!backingGrid.containsPoint(p.x, p.y))
	{
		return false;
	}
	int cellRow = backingGrid.GetCellRow(p.x);
	int cellCol = backingGrid.GetCellColumn(p.y);

	int mini = (int)fmax(cellRow - 2, 0);
	int minj = (int)fmax(cellCol - 2, 0);
	int maxi = (int)fmin(cellRow + 2, backingGrid.width - 1);
	int maxj = (int)fmin(cellCol + 2, backingGrid.height - 1);

	double rsq = backingGrid.r * backingGrid.r;
	for (int j = minj; j <= maxj; j++) {
		for (int i = mini; i <= maxi; i++) {
			int sampleid = backingGrid.GetCellValue(i, j);
			if (sampleid == -1) {
				continue;
			}

			DbPoint o = points[sampleid];
			double dx = p.x - o.x;
			double dy = p.y - o.y;
			double distsq = dx * dx + dy * dy;
			if (distsq < rsq) {
				return false;
			}
		}
	}

	return true;
}

DbPoint PoissonSampler::randomDiscPoint(DbPoint center)
{
	double angle = randomDouble(0, 2 * 3.141592653);
	double nx = sin(angle);
	double ny = cos(angle);
	double rl = randomDouble(backingGrid.r, 2 * backingGrid.r);

	return DbPoint(center.x + nx * rl, center.y + ny * rl);
}

double PoissonSampler::randomDouble(double min, double max)
{
	return min + (double)rand() / ((double)RAND_MAX / (max - min));
}

int PoissonSampler::randomRange(int min, int max)
{
	return min + (rand() % (int)(max - min));
}

DbPoint PoissonSampler::randomPoint()
{
	double offset = backingGrid.padding;
	double px = randomDouble(offset, backingGrid.width-offset);
	double py = randomDouble(offset, backingGrid.height-offset);

	DbPoint dbPoint(px, py);
	return dbPoint;
}
