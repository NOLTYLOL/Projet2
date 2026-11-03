#pragma once
#include "Map.h"


class Entity
{
private:
	int Life = 0;
	int Damage = 1;

public:
	int x = 0;
	int y = 0;

	Entity() = default;
	Entity(int life, int damage) : Life(life), Damage(damage) {}
	void Attack(Entity& target);
	void TakeDamage(int finalDamage);
	
};
