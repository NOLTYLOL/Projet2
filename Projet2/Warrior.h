#pragma once						//NoahD-M
#include "Player.h"

class Warrior : public Player
{
public:
	int Life = 5;
	int Damage = 1;
private:
	void getDamage(int damage);
	void onEnnemyCollision(int damage);

};

