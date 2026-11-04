#pragma once
#include "Map.h"
#include "vector"

class Entity
{
private:
	int Life = 0;
	int Damage = 1;

public:


	Entity() = default;
	Entity(int life, int damage) : Life(life), Damage(damage) {}
	void Attack(Entity& target);
	void TakeDamage(int finalDamage);
	
};
