#include "Cross.h"

Cross::Cross(Vector2 s1, Vector2 e1, Vector2 s2, Vector2 e2)
{
	start1 = s1;
	end1 = e1;
	start2 = s2;
	end2 = e2;
}

Cross::~Cross()
{
}

void Cross::draw()
{
	DrawLineV(start1, end1, RED);
	DrawLineV(start2, end2, RED);
}
