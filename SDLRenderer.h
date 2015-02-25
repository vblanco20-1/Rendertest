#pragma once
#include "SDLFramebuffer.h"
#include "Vector.h"

class SDLRenderer
{
public:
	SDLRenderer(SDLFramebuffer * framebuffer);
	~SDLRenderer();


	void DrawLine(const Vector2d& A, const Vector2d& B, SDL_Color color);

	void DrawColumn(unsigned int x, float height, SDL_Color color);
private:

	SDLFramebuffer * Framebuffer;
};
