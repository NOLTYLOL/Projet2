#include "Warrior.h"					//NoahD-M

void Warrior::getDamage(int damage)
{
	
	if (damage > 0)
	{
		Life -= damage;
	}
}