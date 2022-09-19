#pragma once

struct DbPoint
{
	double x;
	double y;
	DbPoint() {};
	DbPoint(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};
