#pragma once						//NoahD-M
#include "Player.h"
#include "Enemy.h"

class Warrior : public Player
{
public:
	Warrior();
	void getDamage(int damage);
	void onEnnemyCollision(Enemy& enemy);
	void onCollision(Entity& other) override;
};
