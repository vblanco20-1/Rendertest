#pragma once
#include "SDLFramebuffer.h"

#include "Sector.h"
#include "glm.hpp"
using namespace glm;
class SDLRenderer
{
public:
	SDLRenderer(SDLFramebuffer * framebuffer);
	~SDLRenderer();


	

	
	void DrawLine(const glm::ivec2& A, const glm::ivec2& B, SDL_Color color);
	void DrawColumn(unsigned int x, float height, SDL_Color color);

	//draw a wall on local transformed coordinates(vectors will be clamped)
	void DrawWallLocal(vec2& A, vec2& B, SDL_Color color);

	//draw a wall on those global points, it will get transformed
	void DrawWall(vec2& A, vec2& B, vec2& viewPos, vec2& viewDir);

	void DrawSector(const Sector& sector);
private:

	SDLFramebuffer * Framebuffer;
};

