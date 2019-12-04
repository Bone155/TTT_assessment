#pragma once
#include "raylib.h"
#include "Circle.h"
#include "Cross.h"

struct Player {
	int playerNum;
	bool winState;
	bool turn;
};

int vLine = 600 * ((int)1.0f / 3);
int hLine = 450 * ((int)1.0f / 3);
int bw = 600;
int bh = 450;

bool xIsFilled = false;
bool cirIsFilled = false;
bool isFull = false;
int xCount = 0;
int circleCount = 0;

Shape board[3][3];

Cross cross;
Circle cir;
Vector2* positions;

Player player1{ 0, 1, false};
Player player2{ 0, 2, false};

enum icon
{
	x,
	circle
};

void resetPlayer(Player &target) {
	target.winState = false;
}

void select(Vector2* positions) {
	cross = { positions };
	cross.draw();
}

void select(Vector2 pos, float radius) {
	cir = {pos, radius};
	cir.draw();
}

bool CheckLeftClick() {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		return true;
	else
		return false;
}

bool CheckRightClick() {
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		return true;
	else
		return false;
}

//Game board
void drawBoard()
{
	DrawLine(0 + vLine, 0, 0 + vLine, bh, BLUE);
	DrawLine(bw - vLine, 0, bw - vLine, bh, BLUE);
	DrawLine(0, 0 + hLine, bw, 0 + hLine, BLUE);
	DrawLine(0, bh - hLine, bw, bh - hLine, BLUE);
}

void update() {
	Vector2 mouse = { GetMousePosition().x, GetMousePosition().y };
	//colum major, top to bottom
	//col 1
	Vector2 center;
	float raduis = 50;
	if (mouse.x > 0 && mouse.x < vLine && mouse.y > 0 && mouse.y < hLine) {
		positions[0] = { 5.0f, 5.0f};
		positions[1] = {vLine - 5.0f, hLine - 5.0f};
		positions[2] = { vLine - 5.0f, 5.0f};
		positions[3] = { 5.0f, hLine - 5.0f};
		center = { vLine / 2.0f, hLine / 2.0f };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};
	if (mouse.x > 0 && mouse.x < vLine && mouse.y > hLine && mouse.y < bh - hLine) {
		positions[0] = { 5.0f, hLine + 5.0f };
		positions[1] = { vLine - 5.0f, (bh - hLine) - 5.0f };
		positions[2] = { vLine - 5.0f, hLine + 5.0f };
		positions[3] = { 5.0f, (bh - hLine) - 5.0f };
		center = { vLine / 2.0f, (hLine / 2.0f) + (bh/2) };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};
	if (mouse.x > 0 && mouse.x < vLine && mouse.y > (bh - hLine) && mouse.y < bh) {
		positions[0] = { 5.0f, (bh - hLine) + 5.0f };
		positions[1] = { vLine - 5.0f, bh - 5.0f };
		positions[2] = { vLine - 5.0f, (bh - hLine) + 5.0f };
		positions[3] = { 5.0f, bh - 5.0f };
		center = { vLine / 2.0f, bh - (hLine / 2.0f) };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};

	//col 2
	if (mouse.x > vLine && mouse.x < bw - vLine && mouse.y > 0 && mouse.y < hLine) {
		positions[0] = { vLine + 5.0f, 5.0f };
		positions[1] = { (bw - vLine) - 5.0f, hLine - 5.0f };
		positions[2] = { (bw - vLine) - 5.0f, 5.0f };
		positions[3] = { vLine + 5.0f, hLine - 5.0f };
		center = { bw/2, hLine / 2.0f };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};
	if (mouse.x > vLine && mouse.x < bw - vLine && mouse.y > hLine && mouse.y < bh - hLine) {
		positions[0] = { vLine + 5.0f, hLine + 5.0f };
		positions[1] = { (bw - vLine) - 5.0f, (bh - hLine) - 5.0f };
		positions[2] = { (bw - vLine) - 5.0f, hLine + 5.0f };
		positions[3] = { vLine + 5.0f, (bh - hLine) - 5.0f };
		center = { bw/2, bh/2 };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};
	if (mouse.x > vLine && mouse.x < bw - vLine && mouse.y > hLine && mouse.y < bh) {
		positions[0] = { vLine + 5.0f, (bh - hLine) + 5.0f };
		positions[1] = { (bw - vLine) - 5.0f, bh - 5.0f };
		positions[2] = { (bw - vLine) - 5.0f, (bh - hLine) + 5.0f };
		positions[3] = { vLine + 5.0f, bh - 5.0f };
		center = { bw / 2.0f, bh - (hLine / 2.0f) };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};

	//col 3
	if (mouse.x > bw - vLine && mouse.x < bw && mouse.y > 0 && mouse.y < hLine) {
		positions[0] = { (bw - vLine) + 5.0f, 5.0f };
		positions[1] = { bw - 5.0f, hLine - 5.0f };
		positions[2] = { bw - 5.0f, 5.0f };
		positions[3] = { (bw - vLine) + 5.0f, hLine - 5.0f };
		center = { bw - (vLine), hLine / 2.0f };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};
	if (mouse.x > bw - vLine && mouse.x < bw && mouse.y > hLine && mouse.y < bh - hLine) {
		positions[0] = { (bw - vLine) + 5.0f, hLine + 5.0f };
		positions[1] = { bw - 5.0f, (bh - hLine) - 5.0f };
		positions[2] = { bw - 5.0f, hLine + 5.0f };
		positions[3] = { (bw - vLine) + 5.0f, (bh - hLine) - 5.0f };
		center = { bw - (vLine/2), bh/2 };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};
	if (mouse.x > bw - vLine && mouse.x < bw && mouse.y > hLine && mouse.y < bh) {
		positions[0] = { (bw - vLine) + 5.0f, (bh - hLine) + 5.0f };
		positions[1] = { bw - 5.0f, bh - 5.0f };
		positions[2] = { bw - 5.0f, (bh - hLine) + 5.0f };
		positions[3] = { (bw - vLine) + 5.0f, bh - 5.0f };
		center = { bw - (vLine / 2.0f), bh - (hLine / 2.0f) };
		if (CheckLeftClick()) {
			player1.turn = true;
			xCount++;
			if (player1.turn) {
				select(positions);
				xIsFilled = true;
			}
		}
		if (CheckRightClick()) {
			player2.turn = true;
			circleCount++;
			if (player2.turn) {
				select(center, raduis);
				cirIsFilled = true;
			}
		}
	};

	if (xIsFilled || cirIsFilled) {

	}

}