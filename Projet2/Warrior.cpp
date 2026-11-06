#include "Warrior.h"					//NoahD-M

void Warrior::getDamage()
{
	
	if (Damage > 0)
	{
		Life -= Damage;
	}
}

void Warrior::onEnnemyCollision()
{
	if (Vector2(PlayerPos) == Vector2(EnemyPos))

		return getDamage();
	}