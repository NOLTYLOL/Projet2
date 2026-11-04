#pragma once				//Gilio
#include "Entity.h"

class Enemy : public Entity {

private:
	void death();
	int hp = 1;




public:
    Enemy();
	void takeDamage(int dmg);
	bool isDead() const { return dead; }
	bool dead = false; 
}; 
