#pragma once						//NoahD-M
#include "Map.h"
#include "Vector2.h"

class Entity
{
public:
	Vector2 GetPosition() const;
	int Life;
	int Damage;
	bool canSwin = false;

private:
	Entity() = default;
	Entity(int life, int damage) : Life(life), Damage(damage) {}
	void Attack(Entity& target);
	void TakeDamage(int finalDamage);
	int getLife();
	bool IsAlive();
};

