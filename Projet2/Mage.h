#pragma once
#include "Player.h"
#include "Vector2.h"

class Mage : public Player
{
public:

	int Life = 1;
	int Damage = 1;
private:

	void zoneDamage(int damage);
};

