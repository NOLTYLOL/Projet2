#include "Warrior.h"					//NoahD-M

Warrior::Warrior()
{
	Life = 5;
	Damage = 1;
}

void Warrior::onCollision(Entity& other)
{
	other.TakeDamage(Damage);
	TakeDamage(other.Damage);
}
