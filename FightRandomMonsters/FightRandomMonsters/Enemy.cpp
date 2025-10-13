#pragma once
#include "Shared Libraries and Headers.h"

// Body of Enemy Class' Constructor
Enemy::Enemy(std::string name, int maxHealth, int currentHealth, int attack, bool alive, bool current)
{
	enemyName = name;
	enemyMaxHealth = maxHealth;
	enemyCurrentHealth = currentHealth;
	enemyAttack = attack;
	bEnemyAlive = alive;
	bCurrentEnemy = current;
}