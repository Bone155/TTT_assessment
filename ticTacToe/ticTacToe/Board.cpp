#include "Board.h"

Board::Board(size_t _size)
{
	size = _size;
	boardTiles = new char*[size];
	for (int i = 0; i < size; i++)
		boardTiles[i] = new char[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			boardTiles[i][j] = ' ';
		}
	}
}

Board::~Board()
{
}

void Board::drawBoard()
{
	for (int i = 0; i < size; i++) {
		cout << endl;
		for (int j = 0; j < size; j++) {
			cout << "[ " << boardTiles[i][j] << "]";
		}
	}
	cout << endl;
}

bool Board::boardFull()
{
	int full = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (boardTiles[i][j] == 'X' || boardTiles[i][j] == 'O')
			{
				full++;
			}

		}

	}
	if (full >= (size * size)) {
		isFull = true;
	}
	else {
		isFull = false;
	}
	return isFull;
}

bool Board::xVertical()
{
	bool check = false;
	int count;
	for (int i = 0; i < size ; i++) {
		count = 0;
		for (int j = 0; j < size-1; j++) {
			if (boardTiles[j][i] == 'X' && boardTiles[j + 1][i] == 'X') {
				count++;
			}
		}
		if (count >= size - 1)
			check = true;
	}
	
	return check;
}

bool Board::xHorizontal()
{
	bool check = false;
	int count;
	for (int i = 0; i < size - 1; i++) {
		count = 0;
		for (int j = 0; j < size; j++) {
			if (boardTiles[i][j] == 'X' && boardTiles[i][j + 1] == 'X') {
				count++;
			}
		}
		if (count >= size - 1)
			check = true;
	}
	return check;
}

bool Board::xLRDiagonal()
{
	bool check = false;
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (boardTiles[i][i] == 'X' && boardTiles[i + 1][i + 1] == 'X') {
			count++;
		}
	if (count >= size - 1)
		check = true;
	}
	return check;
}

bool Board::xRLDiagonal()
{
	bool check = false;
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (boardTiles[(size - 1) - i][i] == 'X' && boardTiles[(size - 1) - i - 1][i + 1] == 'X') {
			count++;
		}
		if (count >= size - 1)
			check = true;
	}
	return check;
}

bool Board::oVertical()
{
	bool check = false;
	int count;
	for (int i = 0; i < size; i++) {
		count = 0;
		for (int j = 0; j < size - 1; j++) {
			if (boardTiles[j][i] == 'O' && boardTiles[j + 1][i] == 'O') {
				count++;
			}
		}
		if (count >= size - 1)
			check = true;
	}

	return check;
}

bool Board::oHorizontal()
{
	bool check = false;
	int count;
	for (int i = 0; i < size - 1; i++) {
		count = 0;
		for (int j = 0; j < size; j++) {
			if (boardTiles[i][j] == 'O' && boardTiles[i][j + 1] == 'O') {
				count++;
			}
		}
		if (count >= size - 1)
			check = true;
	}
	return check;
}

bool Board::oLRDiagonal()
{
	bool check = false;
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (boardTiles[i][i] == 'O' && boardTiles[i + 1][i + 1] == 'O') {
			count++;
		}
		if (count >= size - 1)
			check = true;
	}
	return check;
}

bool Board::oRLDiagonal()
{
	bool check = false;
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (boardTiles[(size - 1) - i][i] == 'O' && boardTiles[(size - 1) - i - 1][i + 1] == 'O') {
			count++;
		}
		if (count >= size - 1)
			check = true;
	}
	return check;
}
