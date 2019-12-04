#pragma once
#include "raylib.h"
#include "Circle.h"
#include "Cross.h"

int bw = GetScreenWidth() * (1.0 / 3);//266
int bh = GetScreenHeight() * (1.0 / 3);//150
int sw = GetScreenWidth();
int sh = GetScreenHeight();

bool isFilled = false;
bool isFull = false;

Cross cross;
Circle cir;

enum icon
{
	circle,
	x
};

struct Player {
	int score;
	bool winState = false;
};

void resetPlayer(Player &target) {
	target.score = 0;
	target.winState = false;
}

void select(icon input) {
	switch (input)
	{
	case x:
		cross.draw();
		break;
	case circle:
		cir.draw();
		break;
	default:
		break;
	}
}

void bounds() {
	Vector2 mouse = { GetMousePosition().x, GetMousePosition().y };
	//colum major, top to bottom
	//col 1
	if (mouse.x > 0 && mouse.x < bw && mouse.y > 0 && mouse.y < bh) {
		Vector2 vec;
		if (CheckForClick()) {
			isFilled = true;
			select();
		}
	};
	if (mouse.x > 0 && mouse.x < bw && mouse.y > bh && mouse.y < sh - bh) {
		if (CheckForClick())
			isFilled = true;
	};
	if (mouse.x > 0 && mouse.x < bw && mouse.y > bh && mouse.y < sh) {
		if (CheckForClick())
			isFilled = true;
	};

	//col 2
	if (mouse.x > bw && mouse.x < sw - bw && mouse.y > 0 && mouse.y < bh) {
		if (CheckForClick())
			isFilled = true;
	};
	if (mouse.x > bw && mouse.x < sw - bw && mouse.y > bh && mouse.y < sh - bh) {
		if (CheckForClick())
			isFilled = true;
	};
	if (mouse.x > bw && mouse.x < sw - bw && mouse.y > bh && mouse.y < sh) {
		if (CheckForClick())
			isFilled = true;
	};

	//col 3
	if (mouse.x > sw - bw && mouse.x < sw && mouse.y > 0 && mouse.y < bh) {
		if (CheckForClick())
			isFilled = true;
	};
	if (mouse.x > sw - bw && mouse.x < sw && mouse.y > bh && mouse.y < sh - bh) {
		if (CheckForClick())
			isFilled = true;
	};
	if (mouse.x > sw - bw && mouse.x < sw && mouse.y > bh && mouse.y < sh) {
		if (CheckForClick())
			isFilled = true;
	};

}

bool CheckForClick() {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		return true;
	else
		return false;
}

//Game board
void board()
{
	DrawLine(0 + bw, 0, 0 + bw, sh, BLUE);
	DrawLine(sw - bw, 0, sw - bw, sh, BLUE);
	DrawLine(0, 0 + bh, sw, 0 + bh, BLUE);
	DrawLine(0, sh - bh, sw, sh - bh, BLUE);
}