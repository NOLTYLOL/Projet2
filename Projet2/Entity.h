#pragma once						//NoahD-M
#include "Map.h"
#include "vector"

class Entity
{
public:
	int Life = 0;
	int Damage = 1;


	Entity() = default;
	Entity(int life, int damage) : Life(life), Damage(damage) {}
	void Attack(Entity& target);
	void TakeDamage(int finalDamage);
	
};
