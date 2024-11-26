#pragma once

class Player // Blueprint for a player object
{
public:
	// Variables
	std::string playerName;

	int chosenWeaponId = 0;

	int playerHealth = 0;
	bool bPlayerAlive = true;

	int strengthStatPoints = 0;
	int luckStatPoints = 0;
	int vitalityStatPoints = 0;
	int defenceStatPoints = 0;

	int unassignedStatPoints = 20;
	int statPointInput = 0;

	// Constructor
	Player(std::string name, int itemIdx, int health, bool alive, int strength, int luck, int vitality, int defence);

	// Functions
	void statPointAllocation();
};

Player::Player(std::string name, int weapon, int health, bool alive, int strength, int luck, int vitality, int defence)
	{
		playerName = name;
		chosenWeaponId = weapon;
		playerHealth = health;
		bPlayerAlive = alive;
		strengthStatPoints = strength;
		luckStatPoints = luck;
		vitalityStatPoints = vitality;
		defenceStatPoints = defence;
	}