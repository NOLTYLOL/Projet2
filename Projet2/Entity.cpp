#include "Entity.h"

void Entity::TakeDamage(int damage)
{
	int finalDamage = damage;

	Life -= finalDamage;
	if (Life < 0)
		Life = 0;
};
