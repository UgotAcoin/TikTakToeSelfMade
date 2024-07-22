#include "MainGame.h"

MainGame::MainGame() : _currentPlayer(0)
{
	_board = new Board(_gameBoard);
	
}

MainGame::~MainGame()
{
	delete _board;
}

void MainGame::run()
{
	bool running = true;
	while (running)
	{
		int checkWinner;
		int player = 1;
		_board->makeGameBoard();
		do
		{
			_board->draw();
			std::cout << "Player " << player << ":\n";
			takeTurn(player);
			checkWinner = _board->checkVictory();

			if (checkWinner != 0)
			{
				_board->draw();
				std::cout << "Player " << player << " is the winner!" << std::endl;
				_board->clearBoard();
				break;
			}
			if (player == 1) {
				player++;
			} 
			else if (player == 2)
			{
				player--;
			}
		} while (checkWinner == 0);
		running = checkContinue();
	}
	system("PAUSE");
}

bool MainGame::checkMove(int x, int y)
{
	bool checkResult;
	int size = _board->getSize();
	if (x < 0 || y < 0)
	{
		checkResult = false;
	}
	else 
	{
		if (x >= size || y >= size)
		{
			checkResult = false;
		}
		else
		{
			checkResult = true;
		}
	}
	return checkResult;
}

void MainGame::takeTurn(int player)
{
	bool a;
	int x, y;
	do {
		std::cout << "\nEnter X: ";
		std::cin >> x;
		std::cout << "Enter Y: ";
		std::cin >> y;
		a = checkMove(x, y);
	} while (!a);
	system("cls");
	_board->setMove(x, y, player);

}

bool MainGame::checkContinue()
{
	bool keepGoing = true;
	int con;
	std::cout << "Do you want to keep going? (1 = Yes, 2 = No) : ";
	std::cin >> con;

	if (con != 1)
	{
		keepGoing = false;
	}

	system("cls");

	return keepGoing;
}
