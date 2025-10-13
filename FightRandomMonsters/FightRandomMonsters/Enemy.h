#pragma once
#include "Shared Libraries and Headers.h"

class Enemy
{
	// Personal details variables
public:
	std::string enemyName = "";

	// Health variables
	int enemyMaxHealth = 0;
	int enemyCurrentHealth = 0;
	bool bEnemyAlive = true;

	// Attack variables
	int enemyAttack = 0;

	// Status variables
	bool bCurrentEnemy = false;

	// Constructor
	Enemy(std::string name, int maxHealth, int currentHealth, int attack, bool alive, bool current);
};