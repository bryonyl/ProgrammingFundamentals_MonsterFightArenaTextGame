#pragma once
#include "Shared Libraries and Headers.h"

// Body of Player Class' Constructor
Player::Player(std::string name, int currentWeaponId, int baseHealth, int baseAttack, int alive, int unassignedStatPoints, 
int strengthStatPoints, int vitalityStatPoints, int defenseStatPoints)
{
	playerName = name;
	playerCurrentWeaponId = currentWeaponId;
	playerBaseHealth = baseHealth;
	playerBaseAttack = baseAttack;
	bPlayerAlive = alive;
	playerUnassignedStatPoints = unassignedStatPoints;
	playerStrengthStatPointInput = strengthStatPoints;
	playerVitalityStatPointInput = vitalityStatPoints;
	playerDefenseStatPointInput = defenseStatPoints;
}