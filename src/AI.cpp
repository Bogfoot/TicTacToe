#include "../inc/AI.h"

void clearScreen() //Clear screen 
{ 
	std::cout <<("\033c");
}

void showBoard(char ploca[3][3]) //Shows the state of the board to user
{
	

	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{ 
			if (j != 2)
				std::cout << ploca[i][j] << "\t" << "|\t";
			else
				std::cout << ploca[i][j] << "\t";;
		}
		std::cout << std::endl;
	}


}
void clearBoard(char ploca[3][3])
{
	for (int i = 0; i < 3 ; i++)
	{
		for (int j = 0; j < 3; j++)
			ploca[i][j] = ' ';
	}
}


bool whoWon(char ploca[3][3], char move) {
	if ((ploca[0][0] == ploca[0][1]) && (ploca[0][1] == ploca[0][2]) && (ploca[0][1] == move))	   return true;
	else if ((ploca[0][0] == ploca[0][1]) && (ploca[0][1] == ploca[0][2]) && (ploca[0][1] == move)) return true;
	else if ((ploca[1][0] == ploca[1][1]) && (ploca[1][2] == ploca[1][1]) && (ploca[1][1] == move)) return true;
	else if ((ploca[2][0] == ploca[2][1]) && (ploca[2][1] == ploca[2][2]) && (ploca[2][1] == move)) return true;
	else if ((ploca[0][0] == ploca[1][0]) && (ploca[1][0] == ploca[2][0]) && (ploca[1][0] == move)) return true;
	else if ((ploca[0][1] == ploca[1][1]) && (ploca[1][1] == ploca[2][1]) && (ploca[1][1] == move)) return true;
	else if ((ploca[0][2] == ploca[1][2]) && (ploca[1][2] == ploca[2][2]) && (ploca[1][2] == move)) return true;
	else if ((ploca[0][0] == ploca[1][1]) && (ploca[1][1] == ploca[2][2]) && (ploca[1][1] == move)) return true;
	else if ((ploca[2][0] == ploca[1][1]) && (ploca[1][1] == ploca[0][2]) && (ploca[1][1] == move)) return true;
	else																						   return false;
	
}
int rng()
{

	std::random_device seeder;
	auto seed = seeder.entropy() ? seeder() : std::time(nullptr);
	static std::default_random_engine generator(
		static_cast<std::default_random_engine::result_type>(seed));
	std::uniform_int_distribution<int> distribution(0, 2);

	return distribution(generator);
}
void AI(char ploca[3][3])
{

	int x = rng() , y = rng();
	if (ploca[x][y] == 'x')
		AI(ploca);
	else if (ploca[x][y] == 'o')
		AI(ploca);
	else
		ploca[x][y] = 'o';
}
