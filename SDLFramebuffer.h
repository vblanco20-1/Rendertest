#pragma once
#include <SDL.h>

class SDLFramebuffer
{
public:
	SDLFramebuffer(SDL_Renderer * renderer, Uint32 PxFormat, unsigned int NewWidth, unsigned int NewHeight);
	~SDLFramebuffer();

	SDL_Texture * GetTexture(bool updated = true);

	
	void DrawPoint(SDL_Color color, unsigned int x, unsigned int y);

	SDL_PixelFormat * GetPixelFormat();

	Uint32 * GetPixelArray();

	void ClearPixels();

	unsigned int GetWidth() const { return Width; }
	unsigned int GetHeight() const { return Height; }
private:

	SDL_Texture * Texture;
	SDL_PixelFormat * PixelFormat;

	unsigned int Width;	
	unsigned int Height;

	Uint32 * PixelArray;

};