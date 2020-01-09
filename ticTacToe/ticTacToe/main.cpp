#include "Board.h"

void xPlayer(Board board)
{
	while (true)
	{
		size_t row, col;
		while (true)
		{
			cout << endl << "X turn" << endl << "Enter a row" << endl;
			cin >> row;
			if (cin.fail()) {
				cout << "Invalid input. Enter a row" << endl;
				cin >> row;
				break;
			}
			else {
				cout << endl;
				break;
			}
			
		}
		while (true)
		{
			cout << "Enter a column" << endl;
			cin >> col;
			if (cin.fail()) {
				cout << "Invalid input. Enter a col" << endl;
				cin >> col;
				break;
			}
			else {
				cout << endl;
				break;
			}
			
		}

		if (cin.fail()) {
			cout << "Invalid input" << endl;
			break;
		}
		else if (board.boardTiles[row - 1][col - 1] != 'X' && board.boardTiles[row - 1][col - 1] != 'O') {
			board.boardTiles[row - 1][col - 1] = 'X';
			board.drawBoard();
			break;
		}
		else
		{
			cout << "Spot taken" << endl;
		}
	}
	
}

void oPlayer(Board board)
{
	while (true)
	{
		size_t row, col;
		while (true)
		{
			cout << endl << "O turn" << endl << "Enter a row" << endl;
			cin >> row;
			if (cin.fail()) {
				cout << "Invalid input. Enter a row" << endl;
				cin >> row;
				break;
			}
			else {
				cout << endl;
				break;
			}

		}
		while (true)
		{
			cout << "Enter a column" << endl;
			cin >> col;
			if (cin.fail()) {
				cout << "Invalid input. Enter a col" << endl;
				cin >> col;
				break;
			}
			else {
				cout << endl;
				break;
			}

		}

		if (cin.fail()) {
			cout << "Invalid input" << endl;
			break;
		}
		else if (board.boardTiles[row - 1][col - 1] != 'X' && board.boardTiles[row - 1][col - 1] != 'O') {
			board.boardTiles[row - 1][col - 1] = 'O';
			board.drawBoard();
			break;
		}
		else
		{
			cout << "Spot taken" << endl;
		}
	}
}

int main() {
	Player x;
	Player o;
	
	size_t size;
	cout << "Enter the size of the board. (n*n)" << endl;
	cin >> size;
	if (cin.fail()) {
		cout << "Invalid input. enter a board size" << endl;
		cin >> size;
	}

	Board board = { size };

	int random = rand() % 2 + 1;
	if (random == 1) {
		cout << endl << "player X goes first" << endl;
		x.turn = true;
	}
	else if (random == 2) {
		cout << "player O goes first" << endl;
		o.turn = true;
	}
	board.drawBoard();
	while (!board.isFull)
	{
		if (x.turn) {
			xPlayer(board);

			x.turn = false;
			o.turn = true;
		}

		else if (o.turn) {
			oPlayer(board);

			o.turn = false;
			x.turn = true;
		}

		if (board.xVertical()) {
			cout << "player X won" << endl;
			x.winState = true;
		}
		if (board.xHorizontal()) {
			cout << "player X won" << endl;
			x.winState = true;
		}
		if (board.xLRDiagonal()) {
			cout << "player X won" << endl;
			x.winState = true;
		}
		if (board.xRLDiagonal()) {
			cout << "player X won" << endl;
			x.winState = true;
		}

		if (board.oVertical()) {
			cout << "player O won" << endl;
			o.winState = true;
		}
		if (board.oHorizontal()) {
			cout << "player O won" << endl;
			o.winState = true;
		}
		if (board.oLRDiagonal()) {
			cout << "player O won" << endl;
			o.winState = true;
		}
		if (board.oRLDiagonal()) {
			cout << "player O won" << endl;
			o.winState = true;
		}

		if (board.boardFull()) {
			cout << "Tie game" << endl;
			board.isFull = true;
		}

		if (x.winState)
			board.isFull = true;
		if (o.winState)
			board.isFull = true;

	};
	cout << endl;
	system("pause");
	return 0;
}