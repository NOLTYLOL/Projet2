#pragma once						//NoahD-M
#include "Map.h"
#include "Vector2.h"

class Entity
{
public:
	Vector2 position;
	int Life = 1;
	int Damage = 1;
	bool canSwin = false;

	Entity() = default;
	Entity(int life, int damage) : Life(life), Damage(damage) {}

	Vector2 GetPosition() const;
	void SetPosition(Vector2 newPos);
	void Attack(Entity& target);
	void TakeDamage(int finalDamage);
	int getLife() const;
	bool IsAlive() const;
	void movement(Vector2 direction);
};
