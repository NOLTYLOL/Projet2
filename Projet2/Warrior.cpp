#include "Warrior.h"					//NoahD-M

Warrior::Warrior()
{
	Life = 5;
	Damage = 1;
}

void Warrior::getDamage(int damage)
{
	if (damage > 0)
	{
		TakeDamage(damage);
	}
}

void Warrior::onEnnemyCollision(Enemy& enemy)
{
	if (position == enemy.GetPosition())
	{
		enemy.TakeDamage(Damage);
		getDamage(enemy.Damage);
	}
}
