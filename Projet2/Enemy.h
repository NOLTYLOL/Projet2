#pragma once // Gilio
#include "Entity.h"

class Enemy : public Entity
{
public:
	char symbol = 'Z';

	Enemy();
	Enemy(Vector2 startPos, char enemySymbol = 'Z');

	char getSymbol() const;
	virtual Vector2 getDirection(Vector2 playerPos);
};
