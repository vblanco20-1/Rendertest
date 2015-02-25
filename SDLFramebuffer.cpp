#include "SDLFramebuffer.h"
SDLFramebuffer::SDLFramebuffer(SDL_Renderer * renderer, Uint32 PxFormat, unsigned int NewWidth, unsigned int NewHeight)
{
	Texture = SDL_CreateTexture(renderer, PxFormat, SDL_TEXTUREACCESS_STATIC, NewWidth, NewHeight);

	PixelArray = new Uint32[NewWidth * NewHeight];
	PixelFormat = SDL_AllocFormat(PxFormat);
	Width = NewWidth;
	Height = NewHeight;

	
}

SDLFramebuffer::~SDLFramebuffer()
{
	if (Texture != nullptr)
	{
		SDL_DestroyTexture(Texture);
	}
	if (PixelArray != nullptr)
	{
		delete[] PixelArray;
	}
	
}

SDL_Texture * SDLFramebuffer::GetTexture(bool updated /*= true*/)
{
	if (updated)
	{
		SDL_UpdateTexture(Texture, NULL, PixelArray, Width * sizeof(Uint32));
	}
	return Texture;
}

void SDLFramebuffer::DrawPoint(SDL_Color color,unsigned int x,unsigned int y)
{

	Uint32 iColor = SDL_MapRGB(PixelFormat, color.r, color.g, color.b);

	if (x < Width && y < Height)
	{
		PixelArray[x + y*Width] = iColor;
	}
}

SDL_PixelFormat * SDLFramebuffer::GetPixelFormat()
{
	return PixelFormat;
}

Uint32 * SDLFramebuffer::GetPixelArray()
{
	return PixelArray;
}

void SDLFramebuffer::ClearPixels()
{
	for (unsigned int i = 0; i < Width * Height; i++)
	{
		PixelArray[i] = 0;
	}
}

