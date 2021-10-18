// ProjectHype.cpp : Defines the entry point for the application.
//

#include "../inc/AI.h"
//Krizic kruzic
//Zelim da nasumicno bira misto di ce komp stavit kruzic,
//da ocisti ekran kad korisnik unese izbor (broj ili par brojeva)



int main()
{
	char ploca[3][3]{ {""}, {""}, {""} };

	int x, y;
	do
	{
		std::cout << "Where to place an 'x'? (in matrix form, 3x3 matrix)" << std::endl;
		std::cin >> x >> y;
		while ((x < 0) || (x > 2) || (y < 0) || (y > 2))
		{
			std::cout << "Matrix is 3x3, use 0, 1, 2 for input please." << std::endl;
			std::cin >> x >> y;
			
		}

		while ((ploca[x][y] == 'o') || (ploca[x][y] == 'x'))
		{
			std::cout << "You can't place an 'x' there. Choose another spot." << std::endl;
			std::cin >> x >> y;
		}
		ploca[x][y] = 'x';
		AI(ploca);
		clearScreen();
		showBoard(ploca);

	} while (!hasWon(ploca));

	std::cout << "You won!";

}
