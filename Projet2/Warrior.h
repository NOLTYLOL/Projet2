#pragma once						//NoahD-M
#include "Player.h"
#include "Vector2.h"
#include "Enemy.h"

class Warrior : public Player
{
public:
	int Life = 5;
	int Damage = 1;

private:
	void getDamage(int damage);
	void onEnnemyCollision(Vector2 enemyPos, int damage);

};

