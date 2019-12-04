#pragma once
#include "Shape.h"

class Cross : public Shape
{
	Vector2* positions;
public:
	Cross(Vector2* pos);
	Cross();
	~Cross();

	void draw() override;
};

