#pragma once
#include <vector>
#include "Vector.h"

struct Segment
{
	Vector2d A;
	Vector2d B;
	Vector2d Normal;
	
};

class Sector
{
public:
	Sector(std::vector<Vector2d>&Points );
	~Sector();


private:
	std::vector<Segment> Walls;



};

