#pragma once
#include <vector>
#include "glm.hpp"
using namespace glm;
struct Segment
{
	vec2 A;
	vec2 B;
	vec2 Normal;
	
};

class Sector
{
public:
	Sector(std::vector<vec2>&Points);
	~Sector();



	std::vector<Segment> Walls;



};

