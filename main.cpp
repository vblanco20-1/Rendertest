#include <iostream>
#include <string>
#include "SDLSystem.h"
#include "SDLFramebuffer.h"
#include "SDLRenderer.h"
#include <chrono>
#include "glm.hpp"
using namespace std;
using namespace glm;
int main(int argc, char **argv){
	
	SDLSystem System;

	System.CreateWindow("RenderTest", 100, 100, 600, 400, 0);

	bool quit = false;
	
	SDLFramebuffer Framebuffer(System.GetRenderer(), SDL_PIXELFORMAT_ARGB8888, 600, 400);
	SDL_Event event;

	SDLRenderer renderer(&Framebuffer);
	SDL_Color red{255,0,0,255};
	SDL_Color blue{ 0, 0, 255, 255 };
	SDL_Color green{ 0, 255, 0, 255 };
	Framebuffer.ClearPixels();

	vec2 B(0.2f, 0.7f);
	vec2 A(0.6f, 0.7f);
	vec2 C(0.6, 0.1);

	vec2 ViewRot(0.f, 0.f);
	vec2 ViewLoc(0.f, 0.f);

	while (!quit)
	{
		Framebuffer.ClearPixels();

		while (SDL_PollEvent(&event)) {

			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_w)
				{
					ViewLoc.y += 0.1;
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					ViewLoc.y -= 0.1;
				}
				if (event.key.keysym.sym == SDLK_a)
				{
					ViewLoc.x += 0.1;
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					ViewLoc.x -= 0.1;
				}
				if (event.key.keysym.sym == SDLK_q)
				{
					ViewRot.x += 0.1;
				}
				else if (event.key.keysym.sym == SDLK_e)
				{
					ViewRot.x -= 0.1;
				}
				break;
			}
		}
		
		//start profile
		//auto start_time = chrono::high_resolution_clock::now();

		//int numIterations = 100;
		//for (int i = 0; i < numIterations; i++)
		//{
		
		//renderer.DrawWall(B, C, ViewLoc,ViewRot);
		renderer.DrawWall(A, B, ViewLoc, ViewRot);
		renderer.DrawWall(A, C, ViewLoc, ViewRot);
		//}
		////stop profile
		//auto end_time = chrono::high_resolution_clock::now();
		//cout << "BasicBenchmark, at " << numIterations << " iterations: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << "milliseconds:" << endl;


		//for (int x = 40; x < 300; x++)
		//{
		//	renderer.DrawColumn(x, x / 300.f, red);
		//}
		System.DrawFrame(&Framebuffer);
	}
	return 0;
}