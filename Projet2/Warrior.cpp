#include "Warrior.h"					//NoahD-M
#include "Enemy.h"

void Warrior::getDamage(int damage)
{
	
	if (damage > 0)
	{
		Life -= damage;
	}
}

void Warrior::onEnnemyCollision(int damage)
{
	if (Vector2::Position)
	{
		getDamage(damage);
	}
}