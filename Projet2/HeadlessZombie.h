#pragma once // Gilio
#include "Enemy.h"

class HeadlessZombie : public Enemy
{
public:
	HeadlessZombie(Vector2 startPos);
	Vector2 getDirection(Vector2 playerPos) override;
};
