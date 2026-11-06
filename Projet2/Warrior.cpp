#include "Warrior.h"					//NoahD-M

void Warrior::getDamage()
{
	
	if (Damage > 0)
	{
		Life -= Damage;
	}
}

void Warrior::onEnnemyCollision(Vector2 enemyPos, int damage)
{
	if (position == enemyPos)
	{
		getDamage(damage);
	}
}