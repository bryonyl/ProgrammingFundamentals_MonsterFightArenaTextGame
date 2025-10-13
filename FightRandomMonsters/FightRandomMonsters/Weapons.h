#pragma once
#include "Shared Libraries and Headers.h"

class Weapon
{
	// Identification variables
public:
	std::string weaponName = "";
	int weaponId = 0;

	// Battle variables
	int weaponDamage = 0;

	// Constructor
	Weapon(std::string name, int id, int damage);
};