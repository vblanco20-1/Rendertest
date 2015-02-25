#include <iostream>
#include <string>
#include "SDLSystem.h"
#include "SDLFramebuffer.h"
#include "SDLRenderer.h"

int main(int argc, char **argv){
	
	SDLSystem System;

	System.CreateWindow("RenderTest", 100, 100, 600, 400, 0);

	bool quit = false;
	
	SDLFramebuffer Framebuffer(System.GetRenderer(), SDL_PIXELFORMAT_ARGB8888, 600, 400);
	SDL_Event event;

	SDLRenderer renderer(&Framebuffer);
	SDL_Color red{255,0,0,255};
	Framebuffer.ClearPixels();
	while (!quit)
	{
		while (SDL_PollEvent(&event)) {

			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		
		for (int x = 40; x < 300; x++)
		{
			renderer.DrawColumn(x, x / 300.f, red);
		}
		System.DrawFrame(&Framebuffer);
	}
	return 0;
}