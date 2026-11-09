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
		onCollision(enemy);
	}
}

void Warrior::onCollision(Entity& other)
{
	other.TakeDamage(Damage);
	getDamage(other.Damage);
}
