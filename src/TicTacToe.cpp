// ProjectHype.cpp : Defines the entry point for the application.
//

#include "../inc/AI.h"

int main()
{
	char ploca[3][3]{ {""}, {""}, {""} };

	int x, y;
	char playagain;
	do {
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
			if (hasWon(ploca)) //Upon victory, clear screen, show board state and exit loop
			{
				clearScreen();
				showBoard(ploca);
				break;
			}

			AI(ploca); //"AI" moves
			if (AIWon(ploca)) {
				clearScreen();
				showBoard(ploca);
				break;
			}
			clearScreen();
			showBoard(ploca); //Show board state

		} while (!hasWon(ploca));

		if (hasWon(ploca))
			std::cout << "You won!" << std::endl;
		else
			std::cout << "You lost to the random picker AI, good job!" << std::endl;
		std::cout << "Want to play again?" << std::endl;
		std::cin >> playagain;
		clearScreen();
		clearBoard(ploca); //Reset the board state
	} while (playagain == 'y');
}
