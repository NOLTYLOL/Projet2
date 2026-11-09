#pragma once // Gilio
#include "Enemy.h"

class Zombie : public Enemy
{
public:
	Zombie(Vector2 startPos);
	Vector2 getDirection(Vector2 playerPos) override;
};
