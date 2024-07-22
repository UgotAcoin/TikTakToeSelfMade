#pragma once

#include <vector>

const int TIE_VAL = -1;
const int NO_VAL = 0;
const int X_VAL = 1;
const int O_VAL = 2;

class Board
{
public:
	Board(std::vector<std::vector<int>>& gameBoard);

	void makeGameBoard();
	void draw() const;
	int checkVictory() const;
	void setMove(int x, int y, int currentPlayer);
	int getSize() const { return _size; }
	void clearBoard();

private:
	std::vector<std::vector<int>>& _gameBoard;
	int _size = 3;
};

