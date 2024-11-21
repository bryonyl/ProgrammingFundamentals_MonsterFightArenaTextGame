#include <iostream>
#include "Player.h"

// Stat point variables
int unassignedStatPoints = 20;
int statPointInput = 0;

// Creating player object
Player player;

void statPointAllocation()
{
	bool bShowStatPointAllocation = true;

	while (bShowStatPointAllocation == true)
	{
		std::cout << "Allocate your stat points!" << std::endl;
		std::cout << "You can invest " << unassignedStatPoints << " stat points in:\n\n";
		std::cout << "- \033[33mStrength\033[0m" << std::endl;
		std::cout << "- \033[34mSpeed\033[0m" << std::endl;
		std::cout << "- \033[32mVitality\033[0m" << std::endl;
		std::cout << "- \033[35mDefence\033[0m" << std::endl;

		std::cout << "\nHow many points would you like to allocate in \033[33mStrength\033[0m?\n\n";
		std::cout << "> ";
		std::cin >> statPointInput;
		player.strengthStatPoints = statPointInput;
		unassignedStatPoints = unassignedStatPoints - player.strengthStatPoints;
		std::cout << player.strengthStatPoints << " points assigned to \033[33mStrength\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
		statPointInput = 0; // Resets statPointInput to allocate the next stat points

		std::cout << "\nHow many points would you like to allocate in \033[34mSpeed\033[0m?\n\n";
		std::cout << "> ";
		std::cin >> statPointInput;
		player.speedStatPoints = statPointInput;
		unassignedStatPoints = unassignedStatPoints - player.speedStatPoints;
		std::cout << player.speedStatPoints << " points assigned to \033[34mSpeed\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
		statPointInput = 0;

		std::cout << "\nHow many points would you like to allocate in \033[32mVitality\033[0m?\n\n";
		std::cout << "> ";
		std::cin >> statPointInput;
		player.vitalityStatPoints = statPointInput;
		unassignedStatPoints = unassignedStatPoints - player.vitalityStatPoints;
		std::cout << player.vitalityStatPoints << " points assigned to \033[32mVitality\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
		statPointInput = 0;

		std::cout << "\nHow many points would you like to allocate in \033[35mDefence\033[0m?\n\n";
		std::cout << "> ";
		std::cin >> statPointInput;
		player.defenceStatPoints = statPointInput;
		unassignedStatPoints = unassignedStatPoints - player.vitalityStatPoints;
		std::cout << player.defenceStatPoints << " assigned to \033[35mDefence\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
		statPointInput = 0;

		if (unassignedStatPoints <= 20)
		{
			std::cout << "You still have " << unassignedStatPoints << " unassigned stat points!" << std::endl;
			std::cout << "Continue? [Y/N]" << std::endl;

			char yesOrNoInput;
			std::cin >> yesOrNoInput;

			if (yesOrNoInput == 'Y' || yesOrNoInput == 'y')
			{
				std::cout << "Continuing game..." << std::endl;
				bShowStatPointAllocation = false;
			}
			else if (yesOrNoInput == 'N' || yesOrNoInput == 'n')
			{
				std::cout << "Restarting stat point allocation process..." << std::endl;
				bShowStatPointAllocation = true;
			}
			else
			{
				std::cerr << "[ERROR] Incorrect input! Please only input Y or N:" << std::endl;
				std::cin >> yesOrNoInput;
			}

			std::cout << "Stat point allocation completed! Here are your stats:" << std::endl;
		}
	}
}