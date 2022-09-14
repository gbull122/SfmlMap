#include "PoissonSampler.h"

PoissonSampler::PoissonSampler(int height, int width, double r, int k)
{
    this->height = height;
    this->width = width;
    this->k = k;
    this->dx = r / sqrt(2);
}

std::vector<Point> PoissonSampler::sample()
{
    std::vector<int> activeList;
    activeList.push_back(0);

    return std::vector<Point>();
}

double PoissonSampler::randomDouble(double min, double max)
{
    return 0.0;
}

int PoissonSampler::randomRange(int min, int max)
{
    return 0;
}

Point PoissonSampler::randomPoint()
{
    return Point();
}
