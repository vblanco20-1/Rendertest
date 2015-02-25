#include "SDLRenderer.h"




SDLRenderer::SDLRenderer(SDLFramebuffer * framebuffer) : Framebuffer{framebuffer}
{
	
}


SDLRenderer::~SDLRenderer()
{
}

void SDLRenderer::DrawLine(const Vector2d& A, const Vector2d& B, SDL_Color color)
{
	const Uint32 * Pixels = Framebuffer->GetPixelArray();


}

void SDLRenderer::DrawColumn(unsigned int x, float height, SDL_Color color)
{
	const unsigned int FrameWidth = Framebuffer->GetWidth();
	if (x <FrameWidth)
	{
		if (height > 1)
		{
			height = 1;
		}
		else if (height < 0)
		{
			height = 0;
		}

		Uint32 iColor = SDL_MapRGB(Framebuffer->GetPixelFormat(), color.r, color.g, color.b);

		Uint32 * Pixels = Framebuffer->GetPixelArray();

		const int halfHeight =  int( (Framebuffer->GetHeight() * height ) /2);

		const int top = Framebuffer->GetHeight() / 2 - halfHeight;
		const int bot = Framebuffer->GetHeight() / 2 + halfHeight;
		for (int y = top; y < bot; y++)
		{
			Pixels[y * FrameWidth + x] = iColor;
		}

	}
}
