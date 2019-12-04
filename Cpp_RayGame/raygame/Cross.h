#pragma once
#include "Shape.h"

class Cross : public Shape
{
	Vector2 start1;
	Vector2 end1;
	Vector2 start2;
	Vector2 end2;
public:
	Cross(Vector2 s1, Vector2 e1, Vector2 s2, Vector2 e2);
	~Cross();

	void draw() override;
};

