#pragma once
#include <SDL.h>
#include <string>
#include "SDLFramebuffer.h"
class SDLSystem
{
public:
	SDLSystem();
	~SDLSystem();

	//creates an OpenGL window and its renderer
	void CreateWindow(std::string WindowName, int x, int y, int w, int h, Uint32 flags);

	//draws the frame
	void DrawFrame(SDLFramebuffer * Framebuffer = nullptr);
	SDL_Renderer * GetRenderer();
protected:

	

	SDL_Window * Window;
	SDL_Renderer * Renderer;
};

