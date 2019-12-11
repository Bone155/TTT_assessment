#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

int Entity::attack()
{
	return 0;
}

void Entity::takeDamage(int damage)
{
}

bool Entity::isAlive()
{
	bool alive;
	if (health > 0)
		alive = true;
	else {
		alive = false;
	}
	return alive;
}
