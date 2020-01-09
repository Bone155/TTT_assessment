#pragma once
#include "Entity.h"
class Zergling : public Entity
{
public:
	Zergling(int hp);
	~Zergling();

	int attack();
	void takeDamage(int damage);
	bool isAlive();
};

