#pragma once

struct Vector2d
{

	float X;
	float Y;

	Vector2d();
	Vector2d(float x, float y);

	inline void operator+(Vector2d&A);
	inline void operator-(Vector2d&A);
	

	Vector2d Clamp(float min, float max);
};

