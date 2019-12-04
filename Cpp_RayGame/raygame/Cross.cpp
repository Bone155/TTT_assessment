#include "Cross.h"

Cross::Cross(Vector2* pos)
{
	for (int i = 0; i < 3; i++) {
		positions[i] = pos[i];
	}
}

Cross::Cross()
{
}

Cross::~Cross()
{
}

void Cross::draw()
{
	DrawLineV(positions[0], positions[1], RED);
	DrawLineV(positions[2], positions[3], RED);
}
