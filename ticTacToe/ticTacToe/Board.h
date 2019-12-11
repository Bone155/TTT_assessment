#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Player
{
	bool turn = false;
	bool winState = false;
};

class Board
{
	size_t size;
public:
	Board(size_t _size);
	~Board();

	void drawBoard();
	bool boardFull();

	bool xVertical();
	bool xHorizontal();
	bool xLRDiagonal();
	bool xRLDiagonal();

	bool oVertical();
	bool oHorizontal();
	bool oLRDiagonal();
	bool oRLDiagonal();

	char** boardTiles;
	bool isFull = false;
};

