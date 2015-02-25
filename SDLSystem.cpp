#include "SDLSystem.h"


SDLSystem::SDLSystem()
{
	SDL_Init(SDL_INIT_VIDEO);
}


SDLSystem::~SDLSystem()
{
	if (Window != nullptr)
	{
		SDL_DestroyWindow(Window);
		
	}
	if (Renderer != nullptr)
	{
		SDL_DestroyRenderer(Renderer);
	}

	SDL_Quit();
}

void SDLSystem::CreateWindow(std::string WindowName, int x, int y, int w, int h, Uint32 flags)
{
	//create a window
	SDL_Window * newWindow = SDL_CreateWindow(WindowName.c_str(),x,y,w,h,flags);
	Window = newWindow;
	SDL_Renderer * newRenderer = SDL_CreateRenderer(Window, -1, 0);
	Renderer = newRenderer;

}

void SDLSystem::DrawFrame(SDLFramebuffer * Framebuffer )
{
	if (Renderer != nullptr)
	{
		SDL_RenderClear(Renderer);
		if (Framebuffer != nullptr)
		{
		
			SDL_RenderCopy(Renderer, Framebuffer->GetTexture(), NULL, NULL);
			
		}
		SDL_RenderPresent(Renderer);
	}
}

SDL_Renderer * SDLSystem::GetRenderer()
{
	return Renderer;
}
