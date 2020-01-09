#pragma once
#include "Entity.h"
class Marine : public Entity
{
public:
	Marine(int hp);
	~Marine();

	int attack();
	void takeDamage(int damage);
	bool isAlive();
};

