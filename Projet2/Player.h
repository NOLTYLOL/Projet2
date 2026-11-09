#pragma once								//NoahD-M
#include <vector>
#include "Entity.h"
#include "Vector2.h"

class Enemy;

class Player : public Entity
{
public:
	Vector2 getDirection(char touche) const;
	void Playerdeath();
	virtual bool handleSpecialAction(char touche, std::vector<Enemy*>& enemies);
};
