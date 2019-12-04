#include "Circle.h"

Circle::Circle(Vector2 pos, float rad)
{
	position = pos;
	radius = rad;
}

Circle::Circle()
{
}

Circle::~Circle()
{
}

void Circle::draw()
{
	DrawCircleV(position, radius, GREEN);
}
