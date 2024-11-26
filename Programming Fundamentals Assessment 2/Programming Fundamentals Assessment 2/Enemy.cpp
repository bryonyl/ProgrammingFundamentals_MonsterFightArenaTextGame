#include <iostream>
#include <string>
#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int attack, int defence, bool alive) // Body of class constructor
{
	std::string enemyName = name;
	int enemyHealth = health;
	int enemyAttack = attack;
	int enemyDefence = defence;
	bool bIsAlive = alive;
}