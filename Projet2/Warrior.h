#pragma once						//NoahD-M
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior();
	void onCollision(Entity& other) override;
};
