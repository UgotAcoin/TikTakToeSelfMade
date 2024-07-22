#include "Board.h"

#include <iostream>

Board::Board(std::vector<std::vector<int>>& gameBoard) : _gameBoard(gameBoard)
{
	// Empty
}

void Board::makeGameBoard()
{
	for (int y = 0; y < _size; y++)
	{
		std::vector<int> row;
		for (int x = 0; x < _size; x++)
		{
			row.push_back(0);
		}
		_gameBoard.push_back(row);
	}
}

void Board::draw() const
{
	char outputChar = NULL;
	std::cout << std::endl;
	std::cout << "    0   1   2   \n";
	std::cout << "  -------------\n";
	for (int y = 0; y < _size; y++)
	{
		std::cout << y << " |";
		for (int x = 0; x < _size; x++)
		{
			if (_gameBoard[y][x] == 0)
			{
				outputChar = ' ';
			}
			else if (_gameBoard[y][x] == 1)
			{
				outputChar = 'X';
			}
			else if (_gameBoard[y][x] == 2)
			{
				outputChar = 'O';
			}
			std::cout << " " << outputChar << " |";
		}
		std::cout << "\n  -------------\n";
	}
}

int Board::checkVictory() const
{
	bool victory;
	int holder;
	int winner = 0;
	
	for (int y = 0; y < _size; y++)
	{
		holder = _gameBoard[y][0];
		if (holder != NO_VAL)
		{
			victory = true;
			for (int x = 0; x < _size; x++)
			{
				if (_gameBoard[y][x] != holder)
				{
					victory = false;
					break;
				}
			}
			if (victory) { winner = holder; }
		}
	}
	if (winner == 0)
	{
		for (int x = 0; x < _size; x++)
		{
			holder = _gameBoard[0][x];
			if (holder != NO_VAL)
			{
				victory = true;
				for (int y = 0; y < _size; y++)
				{
					if (_gameBoard[y][x] != holder)
					{
						victory = false;
						break;
					}
				}
				if (victory) { winner = holder; }
			}
		}
	}
	return winner;
}

void Board::setMove(int x, int y, int currentPlayer)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			_gameBoard[y][x] = currentPlayer;
		}
	}
}

void Board::clearBoard()
{
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			_gameBoard[y][x] = 0;
		}
		
	}
}


