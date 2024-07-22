#pragma once

#include "Board.h"

#include <iostream>

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	bool checkMove(int x, int y);

	void takeTurn(int player);

	bool checkContinue();

private:
	Board* _board;
	
	std::vector<std::vector<int>> _gameBoard;
	
	int _currentPlayer;

};

