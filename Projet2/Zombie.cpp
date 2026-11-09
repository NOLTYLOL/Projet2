#include "Zombie.h" // Gilio

Zombie::Zombie(Vector2 startPos) : Enemy(startPos, 'Z')
{
}

Vector2 Zombie::getDirection(Vector2 playerPos)
{
	if (playerPos.x > position.x)
	{
		return { 1, 0 };
	}
	if (playerPos.x < position.x)
	{
		return { -1, 0 };
	}
	if (playerPos.y > position.y)
	{
		return { 0, 1 };
	}
	if (playerPos.y < position.y)
	{
		return { 0, -1 };
	}
	return { 0, 0 };
}
