#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

struct Player {
	bool turn = false;
	int choose;
	int xCount = 0;
	int oCount = 0;
	bool winState = false;
};

void drawBoard(char** board, int row, int col) {
	for (int i = 0; i < row; i++) {
		cout << endl;
		for (int j = 0; j < col; j++) {
			cout << "[ " << board[i][j] << "]";
		}
	}
	cout << endl;
}

void resetPlayer(Player &player) {
	player.choose = 0;
	player.oCount = 0;
	player.xCount = 0;
}

void xVertical(char** board, Player x) {
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}

	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}

	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}
}

void xHorizontal(char** board, Player x) {
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}

	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}

	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}
}

void oVertical(char** board, Player o) {
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}

	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}

	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}
}

void oHorizontal(char** board, Player o) {
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}

	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}

	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}
}

void xDiagonal(char** board, Player x) {
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}

	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
		x.winState = true;
		cout << "player X won" << endl;
	}
}

void oDiagonal(char** board, Player o) {
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}

	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
		o.winState = true;
		cout << "player O won" << endl;
	}
}

int main() {
	Player x;
	Player o;

	bool xIsFilled = false;
	bool oIsFilled = false;
	bool isFull = false;

	int row = 3;
	int col = 3;
	char** board = new char*[row];
	for (int i = 0; i < row; i++)
		board[i] = new char[col];
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}

	int random = rand() % 2 + 1;
	if (random == 1) {
		cout << "player X goes first" << endl;
		x.turn = true;
	}
	else if (random == 2) {
		cout << "player O goes first" << endl;
		o.turn = true;
	}
	drawBoard(board, row, col);
	while (!(isFull || x.winState || o.winState))
	{
		xDiagonal(board, x);
		xHorizontal(board, x);
		xVertical(board, x);
		oDiagonal(board, x);
		oHorizontal(board, x);
		oVertical(board, x);
		if (x.turn) {
			cout << endl << endl << "X turn" << endl;
			cin >> x.choose;
			if (x.choose == 1) {
				board[0][0] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 2) {
				board[0][1] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 3) {
				board[0][2] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 4) {
				board[1][0] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 5) {
				board[1][1] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 6) {
				board[1][2] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 7) {
				board[2][0] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 8) {
				board[2][1] = 'X';
				xIsFilled = true;
				x.xCount++;
			}
			if (x.choose == 9) {
				board[2][2] = 'X';
				xIsFilled = true;
				x.xCount++;
			}

			cout << endl;

			x.turn = false;
			o.turn = true;
		}

		else if (o.turn) {
			cout << endl << endl << "O turn" << endl;
			cin >> o.choose;
			if (o.choose == 1) {
				board[0][0] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 2) {
				board[0][1] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 3) {
				board[0][2] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 4) {
				board[1][0] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 5) {
				board[1][1] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 6) {
				board[1][2] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 7) {
				board[2][0] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 8) {
				board[2][1] = 'O';
				oIsFilled = true;
				o.oCount++;
			}
			if (o.choose == 9) {
				board[2][2] = 'O';
				oIsFilled = true;
				o.oCount++;
			}

			cout << endl;

			o.turn = false;
			x.turn = true;
		}

		if ((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][1] == 'X' || board[0][1] == 'O') && (board[0][2] == 'X' || board[0][2] == 'O') && (board[1][0] == 'X' || board[1][0] == 'O') && (board[1][1] == 'X' || board[1][1] == 'O') && (board[1][2] == 'X' || board[1][2] == 'O') && (board[2][0] == 'X' || board[2][0] == 'O') && (board[2][1] == 'X' || board[2][1] == 'O') && (board[2][2] == 'X' || board[2][2] == 'O')) {
			isFull = true;
			cout << "Tie game" << endl;
		}

		drawBoard(board, row, col);
	};

	system("pause");
	return 0;
}