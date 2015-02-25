#include "Vector.h"

Vector2d::Vector2d() : X{ 0 }, Y{ 0 }  {}

Vector2d::Vector2d(float x, float y) : X{ x }, Y{ y }   {}

void Vector2d::operator+(Vector2d&A)
{
	X += A.X;
	Y += A.Y;
}
void Vector2d::operator-(Vector2d&A)
{
	X -= A.X;
	Y -= A.Y;
}
