#include "Zergling.h"



Zergling::Zergling()
{
}


Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 10;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}

bool Zergling::isAlive()
{
	bool alive;
	if (health > 0)
		alive = true;
	else {
		alive = false;
	}
	return alive;
}
