#pragma once
#include "Shared Libraries and Headers.h"

// Forward Declarations
void statPointAllocationMenu();
void mainMenu();
void givePlayerWeapon(Player* player1, int weaponIndex);
int calculatePlayerStrength(Player* player1);
int calculatePlayerVitality(Player* player1);
int calculatePlayerDefense(Player* player1);
void displayPlayerStats();
void statPointsAllocationOverspendingCheck(int* statPointInput);

void firstTimeSetup()
{
	std::cout << "+---------------------+" << std::endl;
	std::cout << "| \033[31mMONSTER FIGHT ARENA\033[0m |" << std::endl; // ANSI escape code to make title red
	std::cout << "+---------------------+\n\n";

	std::cout << "Today is your first day as a professional monster fighter." << std::endl;
	std::cout << "Under the watch of thousands of people, fight to the death!!!\n\n";

	std::cout << "You will fight random monsters of varying difficulties." << std::endl;
	std::cout << "Your success relies on the allocation of your stats and also the techniques you use in battle." << std::endl;
	std::cout << "When you win a fight, your weapon will automatically upgrade. Keep fighting until you unlock the best weapon," << std::endl;
	std::cout << "the \033[34mBludgeoning Hamaxe\033[0m!\n\n";

	std::cout << "What is your name?\n";
	std::cout << "> ";
	std::cin >> player1.playerName;
	std::cout << "Let's get you set up, \033[35m" << player1.playerName << "\033[0m!";

	statPointAllocationMenu();
	mainMenu();
};

// Stats Setup Functions

void statPointsAllocationRangeCheck(int* statPointInput, int* allStatCategoriesIndex) // statPointInput uses pass-by-reference so that the new value created for it
																					 // within the function will also reflect the value outside the code.
																					 // So, the function works directly with the original variable and not a copy.
{
	bool bCheckingRange = true;

	while (bCheckingRange == true)
	{
		if (std::cin >> *statPointInput) // If the input is a valid integer (std::cin also takes an input on this line as well)
		{
			if ((*statPointInput >= 0) && (*statPointInput <= 20)) // If the integer provided is between 0-20 (valid)
			{
				bCheckingRange = false;
				statPointsAllocationOverspendingCheck(statPointInput);
				break; // Exit loop as there are no issues
			}
			else
			{
				std::cerr << "\033[41;1m[ERROR]\033[0m Invalid input! Please enter a number between 0 and 20. You have " << player1.playerUnassignedStatPoints << " unassigned stat points left." << std::endl;
				std::cout << "> ";
			}
		}
		else
		{
			// Handles invalid input
			std::cin.clear(); // Clears error flag
			std::cin.ignore(1000, '\n'); // Discards the invalid input
			std::cerr << "\033[41;1m[ERROR]\033[0m Invalid input! Please enter a number between 0 and 20. You have " << player1.playerUnassignedStatPoints << " unassigned stat points left." << std::endl;
			std::cout << "> ";
		}
	}
}

void statPointsAllocationOverspendingCheck(int* statPointInput)
{
	bool bCheckingOverspending = true;

	while (bCheckingOverspending == true)
	{
		if (*statPointInput <= player1.playerUnassignedStatPoints) // If stat point input is less than or equal to amount of stat points left
		{
			bCheckingOverspending = false;
			break;
		}
		if (*statPointInput > player1.playerUnassignedStatPoints) // If stat point input is over the amount of stat points left
		{
			std::cerr << "\033[41;1m[ERROR]\033[0m You don't have enough stat points left to assign! You have " << player1.playerUnassignedStatPoints << " unassigned stat points left. Try again." << std::endl;
			std::cout << "> ";
			std::cin >> *statPointInput;
		}
	}
}

void statPointsAllocationYesOrNoValidityCheck(char* yesOrNoInput, bool* bShowStatPointAllocation)
{
	bool bCheckingYesOrNoValidity = true;
	static bool bRunOnce = true;

	while (bCheckingYesOrNoValidity == true)
	{
		if (std::cin >> *yesOrNoInput) // if the input is a valid char
		{
			if (*yesOrNoInput == 'Y' || *yesOrNoInput == 'y')
			{
				bCheckingYesOrNoValidity = false;
				*bShowStatPointAllocation = false;
				std::cout << "\nStat point allocation completed! Here are your stats:" << std::endl;
				displayPlayerStats();
			}
			else if (*yesOrNoInput == 'N' || *yesOrNoInput == 'n')
			{
				bCheckingYesOrNoValidity = false;
				std::cout << "\nRestarting stat point allocation process...";
				player1.playerUnassignedStatPoints = 20; // Resets the unassigned stat points
				*bShowStatPointAllocation = true;
				statPointAllocationMenu();
			}
			else
			{
				if (bRunOnce == true) // Prevents this error from printing multiple times if the player enters a string (without this, the code would print an error for each char in the string)
				{
					std::cerr << "\033[41;1m[ERROR]\033[0m Invalid input! Please enter [\033[31mY\033[0m] or [\033[31mN\033[0m]." << std::endl;
					std::cout << "> ";
					bRunOnce = false;
				}
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cerr << "\033[41;1m[ERROR]\033[0m Invalid input! Please enter [\033[31mY\033[0m] or [\033[31mN\033[0m]." << std::endl;
			std::cout << "> ";
		}
	}
}

void statPointAllocationMenu()
{
	// Condition variables
	bool bShowStatPointAllocation = true;
	bool bAllStatPointsValid = false;

	// Menu input variables
	int statPointInput = 0;

	// Local stat variables
	int localPlayerStrength = 0;
	int localPlayerVitality = 0;
	int localPlayerDefense = 0;
	
	// ASCII header
	std::cout << "\n\n+-----------------------+" << std::endl;
	std::cout << "| \033[31mSTAT POINT ALLOCATION\033[0m |" << std::endl;
	std::cout << "+-----------------------+\n\n";

	// Introduction to stats and their effects
	std::cout << "You can invest " << player1.playerUnassignedStatPoints << " stat points in:\n\n";
	std::cout << "- \033[33mStrength\033[0m (boosts your attack)" << std::endl;
	std::cout << "- \033[32mVitality\033[0m (adds more health)" << std::endl;
	std::cout << "- \033[36mDefense\033[0m (decreases enemy's damage to you)" << std::endl;

	while (bShowStatPointAllocation == true)
	{
		for (int allStatCategoriesIndex = 0; allStatCategoriesIndex < 3; allStatCategoriesIndex++)
		{
			switch (allStatCategoriesIndex)
			{
			case 1:
				std::cout << "\nHow many points would you like to allocate in \033[33mStrength\033[0m?" << std::endl;
				std::cout << "> ";

				// Validity check (input is taken in this function as well)
				statPointsAllocationRangeCheck(&statPointInput, &allStatCategoriesIndex);

				// Takes away strength points from unassigned stat points
				player1.playerStrengthStatPointInput = statPointInput;
				player1.playerUnassignedStatPoints = player1.playerUnassignedStatPoints - player1.playerStrengthStatPointInput;
				std::cout << player1.playerStrengthStatPointInput << " points assigned to \033[33mStrength\033[0m. You have " << player1.playerUnassignedStatPoints << " left." << std::endl;
				statPointInput = 0; // Resets statPointInput to allocate the next stat points
			case 2:
				// Vitality points
				std::cout << "\nHow many points would you like to allocate in \033[32mVitality\033[0m?" << std::endl;
				std::cout << "> ";

				// Validity check (input is taken in this function as well)
				statPointsAllocationRangeCheck(&statPointInput, &allStatCategoriesIndex);

				// Takes away vitality points from unassigned stat points
				player1.playerVitalityStatPointInput = statPointInput;
				player1.playerUnassignedStatPoints = player1.playerUnassignedStatPoints - player1.playerVitalityStatPointInput;
				std::cout << player1.playerVitalityStatPointInput << " points assigned to \033[32mVitality\033[0m. You have " << player1.playerUnassignedStatPoints << " left." << std::endl;
				statPointInput = 0;
			case 3:
				// Defense points
				std::cout << "\nHow many points would you like to allocate in \033[36mDefense\033[0m?" << std::endl;
				std::cout << "> ";

				// Validity check (input is taken in this function as well)
				statPointsAllocationRangeCheck(&statPointInput, &allStatCategoriesIndex);

				// Takes away defense points from unassigned stat points
				player1.playerDefenseStatPointInput = statPointInput;
				player1.playerUnassignedStatPoints = player1.playerUnassignedStatPoints - player1.playerDefenseStatPointInput;
				std::cout << player1.playerDefenseStatPointInput << " assigned to \033[36mDefense\033[0m. You have " << player1.playerUnassignedStatPoints << " left." << std::endl;
				statPointInput = 0;
				allStatCategoriesIndex = 3;
			}
		}
		// If the player has leftover stat points, ask if they are okay with this and if not, if they want to redo the stat point assignment
		if (player1.playerUnassignedStatPoints <= 20)
		{
			std::cout << "\nYou have " << player1.playerUnassignedStatPoints << " unassigned stat points. Continue? [\033[31mY/N\033[0m]" << std::endl;
			std::cout << "> ";

			char yesOrNoInput = ' ';

			statPointsAllocationYesOrNoValidityCheck(&yesOrNoInput, &bShowStatPointAllocation);
			bShowStatPointAllocation = false;
		}
	}
};

void displayPlayerStats()
{
	calculatePlayerStrength(&player1);
	calculatePlayerVitality(&player1);
	calculatePlayerDefense(&player1);

	std::cout << "\n+------------+" << std::endl;
	std::cout << "| \033[31mYOUR STATS\033[0m |" << std::endl;
	std::cout << "+------------+\n\n";

	std::cout << "[PERSONAL INFO]" << std::endl;
	std::cout << "Name: " << "\033[35m" << player1.playerName << "\033[0m" << std::endl;

	std::cout << "\n[INVENTORY INFO]\n";
	std::cout << "Equipped Weapon: " << "\033[34m" << allWeapons[player1.playerCurrentWeaponId].weaponName << "\033[0m" << std::endl;

	std::cout << "\n[STATS]\n";
	std::cout << "Base Health: " << player1.playerBaseHealth << std::endl;
	std::cout << "Current Health (vitality applied): " << player1.playerVitality << std::endl;
	std::cout << "Base Attack: " << player1.playerBaseAttack << std::endl;
	std::cout << "Attack (strength applied): " << player1.playerStrength << std::endl;
	std::cout << "Defense (points subtracted from enemy's attacks): " << player1.playerDefense << std::endl;
};