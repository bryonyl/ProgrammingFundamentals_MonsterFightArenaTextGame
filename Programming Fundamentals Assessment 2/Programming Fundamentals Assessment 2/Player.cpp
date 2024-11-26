#include <iostream>
#include <string>
#include "Player.h"
#include "Weapon.h"

using namespace::std;

Player::Player(string name, int itemIdx, int health, int strength, int luck, int vitality, int defence, bool bAlive) // Body of the class constructor. Constructor should have same name as class
{
	playerName = name;
	playerHealth = health;
	strengthStatPoints = strength;
	luckStatPoints = luck;
	vitalityStatPoints = vitality;
	defenceStatPoints = defence;

	if (itemIdx >= 0 && itemIdx < numberOfWeapons)
	{
		chosenWeaponId = itemIdx;
	}
	else
	{
		chosenWeaponId = 0;
	}
};

void Player::statPointAllocation()
{								
	bool bShowStatPointAllocation = true;
	bool bValidInput = false;

	while (bShowStatPointAllocation == true)
	{
		std::cout << "Allocate your stat points!" << std::endl;
		std::cout << "You can invest " << unassignedStatPoints << " stat points in:\n\n";
		std::cout << "- \033[33mStrength\033[0m" << std::endl;
		std::cout << "- \033[34mLuck\033[0m" << std::endl;
		std::cout << "- \033[32mVitality\033[0m" << std::endl;
		std::cout << "- \033[35mDefence\033[0m" << std::endl;

		std::cout << "\nHow many points would you like to allocate in \033[33mStrength\033[0m?\n\n";
		std::cout << "> ";
		std::cin >> statPointInput;
		
		while (statPointInput > unassignedStatPoints) // While the player has less points than the points they have left to assign
		{
			if (statPointInput > unassignedStatPoints) 
			{
				bValidInput = false;

				std::cerr << "[ERROR] You don't have enough stat points for that! You have " << unassignedStatPoints << " left. Please try again: ";
				std::cin >> statPointInput;
			}
			else
			{
				break;
			}

			// Takes away strength points from unassigned stat points
			strengthStatPoints = statPointInput;
			unassignedStatPoints = unassignedStatPoints - strengthStatPoints;
			std::cout << strengthStatPoints << " points assigned to \033[33mStrength\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
			statPointInput = 0; // Resets statPointInput to allocate the next stat points

			// Luck points
			std::cout << "\nHow many points would you like to allocate in \033[34mSpeed\033[0m?\n\n";
			std::cout << "> ";
			std::cin >> statPointInput;
			luckStatPoints = statPointInput;
			unassignedStatPoints = unassignedStatPoints - luckStatPoints;
			std::cout << luckStatPoints << " points assigned to \033[34mSpeed\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
			statPointInput = 0;

			// Vitality points
			std::cout << "\nHow many points would you like to allocate in \033[32mVitality\033[0m?\n\n";
			std::cout << "> ";
			std::cin >> statPointInput;
			vitalityStatPoints = statPointInput;
			unassignedStatPoints = unassignedStatPoints - vitalityStatPoints;
			std::cout << vitalityStatPoints << " points assigned to \033[32mVitality\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
			statPointInput = 0;

			// Defence points
			std::cout << "\nHow many points would you like to allocate in \033[35mDefence\033[0m?\n\n";
			std::cout << "> ";
			std::cin >> statPointInput;
			defenceStatPoints = statPointInput;
			unassignedStatPoints = unassignedStatPoints - vitalityStatPoints;
			std::cout << defenceStatPoints << " assigned to \033[35mDefence\033[0m. You have " << unassignedStatPoints << " left." << std::endl;
			statPointInput = 0;

			std::cout << "Your Stats:" << std::endl;
			std::cout << playerName;
			
		}
		
		//// If the player has leftover stat points, ask if they are okay with this and if not, if they want to redo the stat point assignment
		//if (unassignedStatPoints <= 20)
		//{
		//	std::cout << "You still have " << unassignedStatPoints << " unassigned stat points!" << std::endl;
		//	std::cout << "Continue? [Y/N]" << std::endl;

		//	char yesOrNoInput;
		//	std::cin >> yesOrNoInput;

		//	if (yesOrNoInput == 'Y' || yesOrNoInput == 'y')
		//	{
		//		std::cout << "Continuing game..." << std::endl;
		//		bShowStatPointAllocation = false;
		//	}
		//	else if (yesOrNoInput == 'N' || yesOrNoInput == 'n')
		//	{
		//		std::cout << "Restarting stat point allocation process..." << std::endl;
		//		bShowStatPointAllocation = true;
		//	}
		//	else
		//	{
		//		std::cerr << "[ERROR] Incorrect input! Please only input Y or N:" << std::endl;
		//		std::cin >> yesOrNoInput;
		//	}

		//	std::cout << "Stat point allocation completed! Here are your stats:" << std::endl;
		//}
	}
};