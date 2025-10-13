#pragma once
#include "Shared Libraries and Headers.h"

class Player
{
private: // Ensures members within are private and can only be accessed by functions within the class
	int m_intValue{}; // m_ prefix indicates this is a member apart of a class
public:
	// Personal details related variables
	std::string playerName = "";

	// Weapon/inventory related variables
	int playerCurrentWeaponId = 0;

	// Health related variables
	int playerBaseHealth = 100; // Health before vitality is added (vitality gives extra health)
	int playerBaseAttack = 5;
	bool bPlayerAlive = true;

	// Stat related variables
	int playerUnassignedStatPoints = 20;
	int playerStrengthStatPointInput = 0;
	int playerStrength = 0;
	int playerVitalityStatPointInput = 0;
	int playerVitality = 0; // Health after vitality is added (this is calculated outside of the class, in Battle.cpp)
	int playerMaxHealthWithVitality = 0;
	int playerDefenseStatPointInput = 0;
	int playerDefense = 0;

	// Overloading to make Player type and int type compatible
	// Constructor for overload - constructors set up the initial state of the object, initialising the member variables so that it starts in a valid state
	Player(int intValue = 0) : m_intValue{ intValue } {
	}

	// Overloaded type conversion operator. Allows a Player object to be converted to an int. Uses implicit conversion (converts automatically)
	operator int() const { return m_intValue; }

	// Getter function
	int getPlayerValueFromInt() const { return m_intValue; }

	// Setter function. Sets m_intValue to the provided intValue
	void setPlayerValueFromInt(int intValue) { m_intValue = intValue; }

	// Class Constructor
	Player(std::string name, int currentWeaponId, int baseHealth, int baseAttack, int alive, int unassignedStatPoints, 
		int strengthStatPoints, int vitalityStatPoints, int defenseStatPoints);
};

