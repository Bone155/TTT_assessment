#include "Marine.h"

Marine::Marine(int hp)
{
	health = hp;
}

Marine::~Marine()
{
}

int Marine::attack()
{
	return 10;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
}

bool Marine::isAlive()
{
	bool alive;
	if (health > 0)
		alive = true;
	else {
		alive = false;
	}
	return alive;
}

