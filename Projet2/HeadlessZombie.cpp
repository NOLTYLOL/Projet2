#include "HeadlessZombie.h" // Gilio
#include <cstdlib>

HeadlessZombie::HeadlessZombie(Vector2 startPos) : Enemy(startPos, 'h')
{
}

Vector2 HeadlessZombie::getDirection(Vector2 playerPos)
{
	int choix = std::rand() % 4;

	if (choix == 0)
	{
		return { 0, -1 };
	}
	if (choix == 1)
	{
		return { 0, 1 };
	}
	if (choix == 2)
	{
		return { -1, 0 };
	}
	return { 1, 0 };
}
