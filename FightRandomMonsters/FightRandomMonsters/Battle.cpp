#pragma once
#include "Shared Libraries and Headers.h"

// Forward Declarations
void givePlayerWeapon(Player* player1, int weaponIndex);
void playerDamagesEnemy(Enemy* currentEnemy, bool bBattleActive);
void playerWins(bool bBattleActive);
void playerDies(bool bBattleActive);
void enemyDamagesPlayer(Enemy currentEnemy, bool bBattleActive);
void playerGuards(Enemy* currentEnemyPtr, Enemy currentEnemy, bool bBattleActive);
int playerHeals(int currentPlayerVitality);
void playerUnlocksNextWeapon(int nextUnlockedWeaponId);
void mainMenu();

// Random Number Generator Function
int randomNumberGenerator(int min, int max)
{
	int randomNumber = 0;

	srand(time(0)); // Seeds the random number generator using the current calendar time
	randomNumber = min + rand() % (max - min + 1);

	return randomNumber;
}

// Player Stat Calculation Functions
int calculatePlayerStrength(Player* player1)
{
	player1->playerStrength = (player1->playerStrengthStatPointInput * (player1->playerBaseAttack * 1.1)); // For each strength stat point, multiply the player's 
																										// strength by the base attack (with a multiplier of
																										// 1.1 applied to the base attack)
	return player1->playerStrength;
}

int calculatePlayerVitality(Player* player1)
{
	player1->playerVitality = (player1->playerBaseHealth + (player1->playerVitalityStatPointInput * 3)); // Adds 3 health for every stat point
	player1->playerMaxHealthWithVitality = (player1->playerBaseHealth + (player1->playerVitalityStatPointInput * 3));
	return player1->playerVitality;
}

int calculatePlayerDefense(Player* player1)
{
	player1->playerDefense = (player1->playerDefenseStatPointInput * (5)); // Sets up a number to be taken away from the enemy's attack damage
	return player1->playerDefense;
}

// Information Functions
void displayEnemyInfo(Enemy currentEnemy)
{
	std::cout << "\n\nEnemy Name: " << "\033[31m" << currentEnemy.enemyName << "\033[0m" << std::endl;
	std::cout << "Enemy Max Health: " << currentEnemy.enemyMaxHealth << std::endl;
	std::cout << "Enemy Current Health: " << currentEnemy.enemyCurrentHealth << std::endl;
}

void displayPlayerStats_Shortened()
{
	std::cout << "\nYour Equipped Weapon: \033[34m" << allWeapons[player1.playerCurrentWeaponId].weaponName << "\033[0m" << std::endl;
	std::cout << "Your Max Health (with vitality applied): " << player1.playerMaxHealthWithVitality << std::endl;
	std::cout << "Your Current Health (with vitality applied): " << player1.playerVitality << std::endl;
};

// Battle Setup Functions
Enemy selectRandomEnemy()
{
	int randomEnemyNumber = randomNumberGenerator(0, 3);
	allEnemies[randomEnemyNumber].bCurrentEnemy = true;
	std::cout << "\033[31m" << allEnemies[randomEnemyNumber].enemyName << "\033[0m";
	return allEnemies[randomEnemyNumber];
}

void resetBattle(Enemy* currentEnemy)
{
	player1.bPlayerAlive = true; // Revives player
	currentEnemy->bEnemyAlive = true; // Revives enemy

	calculatePlayerVitality(&player1); // Resets player's health to full
	currentEnemy->enemyCurrentHealth = currentEnemy->enemyMaxHealth; // Resets current enemy's health to full
}

void commenceBattle()
{
	std::cin.clear(); // Ensures input is clear from any previous menus

	// Introduction to battle. Current enemy is randomly selected
	std::cout << "\nYou step into the arena!! The crowd is wild with anticipation." << std::endl;
	std::cout << "Your first enemy is a";
	Sleep(1000); // Waits for 1 second
	//std::cout << ".";
	//Sleep(1000);
	std::cout << ".";
	//Sleep(1000);
	std::cout << ". ";
	Enemy currentEnemy = selectRandomEnemy(); // Selects random enemy and prints it out
	std::cout << "!";
	resetBattle(&currentEnemy);
	//Sleep(3000);

	// Local stat variables
	int localPlayerStrength = 0;
	int localPlayerVitality = 0;
	int localPlayerDefense = 0;

	// Stat calculation functions
	calculatePlayerStrength(&player1);
	calculatePlayerVitality(&player1);
	calculatePlayerDefense(&player1);

	bool bBattleActive = true;

	// Displays current enemy's stats
	displayEnemyInfo(currentEnemy);

	// Displays a shortened version of the player stats
	displayPlayerStats_Shortened();

	// While the battle is active and both the player and current enemy are alive, the battle commences
	while (bBattleActive == true && player1.bPlayerAlive == true && currentEnemy.bEnemyAlive == true)
	{
		int battleInput = 0;

		std::cout << "\nWhat will you do?" << std::endl;
		std::cout << "1. Strike" << std::endl;
		std::cout << "2. Guard and Heal";
		std::cout << "\n> ";

		std::cin >> battleInput;

		while (std::cin.fail())
		{
			std::cerr << "\033[41;1m[ERROR]\033[0m Invalid input! Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "> ";
			std::cin >> battleInput;
		}
		// If the player strikes
		if (battleInput == 1)
		{
			// Player attempts to damage the enemy
			playerDamagesEnemy(&currentEnemy, bBattleActive);

			// If the enemy is alive
			if (currentEnemy.bEnemyAlive == true)
			{
				// The enemy takes damage
				enemyDamagesPlayer(currentEnemy, bBattleActive);
			}
			// If the enemy is dead
			else if (currentEnemy.bEnemyAlive == false)
			{
				// The player wins and the fight ends
				playerWins(bBattleActive);
			}
			// If the player is dead
			else if (player1.bPlayerAlive == false)
			{
				// The player dies and the fight and game ends
				playerDies(bBattleActive);
			}
		}
		// If the player chooses to guard and heal
		else if (battleInput == 2)
		{
			std::cout << "\nYou guard yourself so that you take less damage, and quickly take a swig from a \033[33mHealing Potion\033[0m (+20 health) (healing currently not functional)." << std::endl;
			std::cout << "Your new health is: " << player1.playerVitality << "\n\n";

			// Player takes less than the usual damage, as they are guarding
			playerGuards(&currentEnemy, currentEnemy, bBattleActive);

			// Player heals for 20 health
			playerHeals(player1.playerVitality);
		}
		// If the player's input is invalid
		while (std::cin.fail())
		{
			// An error is produced and the player is prompted to reinput
			std::cerr << "\n[ERROR] Invalid input! Please try again.";
			std::cout << "> ";
			std::cin >> battleInput;
		}
	}
}

// Battle Event Functions
void playerWins(bool bBattleActive)
{
	bBattleActive = false;
	int nextWeaponUnlockedId = allWeapons[player1.playerCurrentWeaponId].weaponId + 1;

	// Player's weapon is upgraded
	playerUnlocksNextWeapon(nextWeaponUnlockedId);
	mainMenu();
}

void playerDies(bool bBattleActive)
{
	bBattleActive = false;

	// Player marked as dead
	player1.bPlayerAlive = false;
	std::cout << "\nOh no! You have died!" << std::endl;

	// Game over; game exits
	std::cout << "\033[31;1;3mGAME OVER\033[0m\033[3m. Exiting...\033[0m" << std::endl;
	exit(0);
}

void enemyDies(Enemy* currentEnemy, bool bBattleActive)
{
	bBattleActive = false;

	// Enemy marked as dead
	currentEnemy->bEnemyAlive = false;
	std::cout << "\033[31m" << currentEnemy->enemyName << "\033[0m is dead! Congratulations!" << std::endl;
}

void playerDamagesEnemy(Enemy* currentEnemy, bool bBattleActive) // Uses pointers as the enemy's health will not update otherwise (to do with dynamic memory allocation)
{
	int damageToEnemy = player1.playerStrength;
	int localEnemyNewHealth = 0;

	// Player damages enemy
	currentEnemy->enemyCurrentHealth = currentEnemy->enemyCurrentHealth - damageToEnemy;
	//updateEnemyHealth(&, localEnemyNewHealth);
	std::cout << "\nYou damage " << "\033[31m" << currentEnemy->enemyName << "\033[0m" << " for " << damageToEnemy << " points!" << std::endl;

	// If enemy's health goes below or equal to 0 - so the player wins this fight
	if (currentEnemy->enemyCurrentHealth <= 0)
	{
		enemyDies(currentEnemy, bBattleActive);
	}
	else
	{
		std::cout << "\033[31m" << currentEnemy->enemyName << "\033[0m" << "'s new health: " << currentEnemy->enemyCurrentHealth;
	}
}

void enemyDamagesPlayer(Enemy currentEnemy, bool bBattleActive)
{
	// Enemy damages player
	int damageToPlayer = currentEnemy.enemyAttack;

	// Player's defense reduces the enemy's damage
	damageToPlayer = damageToPlayer - player1.playerDefense;

	// Player takes damage
	player1.playerVitality = player1.playerVitality - damageToPlayer;
	std::cout << "\n\n\033[31m" << currentEnemy.enemyName << "\033[0m" << " damages you for " << damageToPlayer << " points!" << std::endl;

	// If player's health goes below or equal to 0 - so the player loses
	if (player1.playerVitality <= 0)
	{
		playerDies(bBattleActive);
	}
	else
	{
		std::cout << "Your new health is: " << player1.playerVitality << std::endl;
	}
}

void playerGuards(Enemy* currentEnemyPtr, Enemy currentEnemy, bool bBattleActive)
{
	// Player's defense is deducted from the enemy's damage
	int damageToPlayer = 0;
	damageToPlayer = damageToPlayer - player1.playerDefense;

	// Player guards and enemy's attack damage is reduced
	damageToPlayer = currentEnemy.enemyAttack / 2;
	
	// Player takes damage
	player1.playerVitality = player1.playerVitality - damageToPlayer;
	std::cout << "\033[31m" << currentEnemyPtr->enemyName << "\033[0m damages you for " << damageToPlayer << " points!" << std::endl;

	// If player's health goes below or equal to 0
	if (player1.playerVitality <= 0)
	{
		playerDies(bBattleActive);
	}
	else
	{
		std::cout << "Your new health is: " << player1.playerVitality << std::endl;
		std::cout << "\033[31m" << currentEnemyPtr->enemyName << "\033[0m's new health is: " << currentEnemyPtr->enemyCurrentHealth << std::endl;
	}
}

int playerHeals(int currentPlayerVitality)
{
	// Heals player by 20 points
	currentPlayerVitality = player1.playerVitality + 20;
	return currentPlayerVitality;
}

// Inventory Functions
void playerUnlocksNextWeapon(int nextWeaponUnlockedId)
{
	switch (nextWeaponUnlockedId)
	{
	case 1: // Unlocks rusty sword
		std::cout << "You have unlocked the ";
		givePlayerWeapon(&player1, 1);
		std::cout << "! This is slightly stronger than your previous weapon (this is not currently working)." << std::endl;
		player1.playerStrength = player1.playerStrength + 10;
		break; 
	case 2: // Unlocks piercing dagger
		std::cout << "You have unlocked the ";
		givePlayerWeapon(&player1, 2);
		std::cout << "! This is slightly stronger than your previous weapon (this is not currently working)." << std::endl;
		player1.playerStrength = player1.playerStrength + 10;
		break;
	case 3: // Unlocks heavy greatsword
		std::cout << "You have unlocked the ";
		givePlayerWeapon(&player1, 3);
		std::cout << "! This is slightly stronger than your previous weapon (this is not currently working)." << std::endl;
		player1.playerStrength = player1.playerStrength + 10;
		break;
	case 4: // Unlocks bludgeoning hamaxe, final weapon available
		std::cout << "You have unlocked the ";
		givePlayerWeapon(&player1, 4);
		std::cout << "! This is the final weapon upgrade available (this is not currently working)." << std::endl;
		player1.playerStrength = player1.playerStrength + 10;
		break;
	}
}

void givePlayerWeapon(Player* player1, int weaponId)
{
	for (int weaponIndex = 0; weaponIndex < 5; weaponIndex++) // Checks through all of weapons to see if there is a match between the chosen weapon id and all weapon ids
	{
		if (weaponId == allWeapons[weaponIndex].weaponId) // If there is a match
		{
			std::cout << "\033[34m" << allWeapons[weaponIndex].weaponName << "\033[0m"; // Print name of weapon
			player1->playerCurrentWeaponId = allWeapons[weaponIndex].weaponId;
		}
		else
		{
			continue;
		}
	}
}