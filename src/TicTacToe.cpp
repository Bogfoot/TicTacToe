// ProjectHype.cpp : Defines the entry point for the application.
//

#include "../inc/AI.h"

int main()
{
	char ploca[3][3]{ {""}, {""}, {""}};

	std::cout << "How to play:\nEnter a number between 0-2 (including 0 and 2), hit enter. Do that again.\nHave fun with this crappy Tic Tac Toe game." << std::endl;

	int x, y;
	char playagain = 'y';

	while (playagain == 'y')
	{
		do
		{
			std::cout << "Where to place an 'x'? (in matrix form, 3x3 matrix)" << std::endl;
			std::cin >> x >> y;
			while ((x < 0) || (x > 2) || (y < 0) || (y > 2)) //Upon input error, redo input
			{
				std::cout << "Matrix is 3x3, use 0, 1, 2 for input please." << std::endl;
				std::cin >> x >> y;

			}

			while ((ploca[x][y] == 'o') || (ploca[x][y] == 'x')) //Upon input error, redo input
			{
				std::cout << "You can't place an 'x' there. Choose another spot." << std::endl;
				std::cin >> x >> y;
			}
			ploca[x][y] = 'x';
			if (whoWon(ploca, 'x')) //Upon victory, clear screen, show board state and exit loop
			{
				clearScreen();
				showBoard(ploca);
				break;
			}

			AI(ploca); //"AI" moves

			clearScreen();
			showBoard(ploca); //Show board state

		} while (!whoWon(ploca, 'x') || !whoWon(ploca, 'o'));

		if (whoWon(ploca, 'x'))
		{
			std::cout << "You won!" << std::endl;
		}
		else
		{
			std::cout << "You lost to the random picker AI, good job!" << std::endl;
		}
		std::cout << "Want to play again?" << std::endl;
		std::cin >> playagain;
		clearScreen();
		clearBoard(ploca); //Reset the board state
	}
}
