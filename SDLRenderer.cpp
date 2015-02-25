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

void SDLRenderer::DrawWallLocal(Vector2d& A, Vector2d& B, SDL_Color color)
{
	A.Clamp(0,1);

	B.Clamp(0,1);

	Vector2d Left, Right;
	if (A.X < B.X)
	{
		Left = A;
		Right = B;
	}
	else
	{
		Left = B;
		Right = A;
	}

	const int startx = Left.X * Framebuffer->GetWidth();
	const int endx = Right.X * Framebuffer->GetWidth();

	for (int x = startx; x < endx; x++)
	{
		//lerp value
		float dist = (endx - startx);
		float dif = (x - startx);
		float l =  dif/dist ;

		float y = (1 - l)*Left.Y + l*Right.Y;
		DrawColumn(x, y, color);
	}
}
