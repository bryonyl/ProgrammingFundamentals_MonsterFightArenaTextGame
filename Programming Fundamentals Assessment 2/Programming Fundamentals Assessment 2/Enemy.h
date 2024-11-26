#pragma once

class Enemy 
{
public:
	// Variables
	std::string enemyName = "";

	int enemyHealth = 0;
	bool bAlive = true;

	int enemyAttack = 0;
	int enemyDefence = 0;
	
	// Constructor
	//Enemy(std::string name, int health, bool alive, int attack, int defence);
};

Enemy(std::string name, int health, bool alive, int attack, int defence);
{
	enemyHealth = name;
	bAlive = alive;
	enemyAttack = attack;
	enemyDefence = defence;
}