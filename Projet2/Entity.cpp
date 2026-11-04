#include "Entity.h"							//NoahD-M

void Entity::TakeDamage(int damage)
{
	int finalDamage = damage;

	Life -= finalDamage;
	if (Life < 0)
		Life = 0;
};

