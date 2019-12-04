#pragma once
#include "Shape.h"

class Circle : public Shape
{
	Vector2 position;
	float radius;
public:
	Circle(Vector2 pos, float rad);
	~Circle();

	void draw() override;
};

