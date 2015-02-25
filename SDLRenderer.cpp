#include "SDLRenderer.h"
#include <math.h>

#include "glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/rotate_vector.hpp"
SDLRenderer::SDLRenderer(SDLFramebuffer * framebuffer) : Framebuffer{framebuffer}
{
	
}


SDLRenderer::~SDLRenderer()
{
}

void SDLRenderer::DrawLine(const glm::ivec2& A, const glm::ivec2& B, SDL_Color color)
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

void SDLRenderer::DrawWall(vec2& A, vec2& B, vec2& viewPos, vec2& viewDir)
{
	vec3 ChangedA = vec3(A, 0) - vec3(viewPos, 0);
	vec3 ChangedB = vec3(B, 0) - vec3(viewPos, 0);
	//A = A - viewPos;
	//B = B - viewPos;

	//glm::mat4 Projection = glm::perspective(35.0f, 1.0f, 0.1f, 100.0f);

	


	vec3 finalA = glm::rotateZ(ChangedA, viewDir.x);
	vec3 finalB = glm::rotateZ(ChangedB, viewDir.x);

	
	SDL_Color green{ 0, 255, 0, 255 };


	finalA.y /= 10;
	finalB.y /= 10;
	DrawWallLocal(vec2(finalA), vec2(finalB), green);
}



void SDLRenderer::DrawWallLocal(vec2& A, vec2& B, SDL_Color color)
{
	

	vec2 Left, Right;
	if (A.x < B.x)
	{
		Left = A;
		Right = B;
	}
	else
	{
		Left = B;
		Right = A;
	}

	int FrameWidth = Framebuffer->GetWidth();

	int startx = Left.x * FrameWidth;
	int endx = Right.x* FrameWidth;

	if (startx < 0)
	{
		startx = 0;
	}

	if (endx > FrameWidth)
	{
		endx = FrameWidth;
	}
	for (int x = startx; x < endx; x++)
	{
		//lerp value
		float dist = (endx - startx);
		float dif = (x - startx);
		float l =  dif/dist ;

		float y = (1 - l)*Left.y + l*Right.y;
		DrawColumn(x, y, color);
	}
}



void SDLRenderer::DrawSector(const Sector& sector)
{
	for (auto wall : sector.Walls)
	{
		SDL_Color green{ 0, 255, 0, 255 };
		DrawWallLocal(wall.A, wall.B, green);
	}
}
