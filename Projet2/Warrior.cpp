#include "Warrior.h"					//NoahD-M
#include "Enemy.h"

void Warrior::getDamage(int damage)
{
	
	if (damage > 0)
	{
		Life -= damage;
	}
}

void Warrior::onEnnemyCollision(Vector2 enemyPos, int damage)
{
	if (position == enemyPos)
	{
		getDamage(damage);
	}
}