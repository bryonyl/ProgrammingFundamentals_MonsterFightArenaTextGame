#pragma once
#include "Shared Libraries and Headers.h"

// Forward Declarations
void statPointAllocationMenu();
void displayPlayerStats();
void commenceBattle();
int calculatePlayerStrength(Player* player1);
int calculatePlayerVitality(Player* player1);
int calculatePlayerDefense(Player* player1);

void mainMenu()
{
	// Menu input variables
	int menuInput = 0;
	bool bValidMenuInput = false;

	// Local stat variables
	int localPlayerStrength = 0;
	int localPlayerVitality = 0;
	int localPlayerDefense = 0;

	// Stat calculation functions
	calculatePlayerStrength(&player1);
	calculatePlayerVitality(&player1);
	calculatePlayerDefense(&player1);

	while (bValidMenuInput == false)
	{
		// ASCII header
		std::cout << "\n+-----------+" << std::endl;
		std::cout << "| \033[31mMAIN MENU\033[0m |" << std::endl; // Uses ANSI escape codes to colour text
		std::cout << "+-----------+\n\n";

		// Menu options
		std::cout << "1. Fight!!!" << std::endl;
		std::cout << "2. View Stats" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "> ";

		std::cin >> menuInput;

		// If player types 1, start battle
		if (menuInput == 1)
		{
			bValidMenuInput = true;
			commenceBattle();
		}
		// If player types 2, display stats
		else if (menuInput == 2)
		{
			bValidMenuInput = true;
			displayPlayerStats();
			mainMenu();
		}
		// If player types 3, exit program
		else if (menuInput == 3)
		{
			bValidMenuInput = true;
			std::cout << "\n\033[3mExiting game...\033[0m" << std::endl;
			exit(1);
		}
		// If player types anything other than 1, 2 or 3, then display an error and ask player to reinput
		while (std::cin.fail())
		{
			std::cerr << "\033[41;1m[ERROR]\033[0m Invalid input! Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "> ";
			std::cin >> menuInput;
		}
	}
}