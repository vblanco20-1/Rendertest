#include "Sector.h"



Sector::Sector(std::vector<vec2>&Points)
{
	for (int i = 0; i < Points.size() - 1; i++)
	{
		Segment newSegment;
		newSegment.A = Points[i];
		newSegment.B = Points[i + 1];
	}
}


Sector::~Sector()
{
}
