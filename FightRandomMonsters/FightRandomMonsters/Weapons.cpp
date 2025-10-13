#pragma once
#include "Shared Libraries and Headers.h"

// Body of Weapons Class' Constructor
Weapon::Weapon(std::string name, int id, int damage)
{
	weaponName = name;
	weaponId = id;
	weaponDamage = damage;
}