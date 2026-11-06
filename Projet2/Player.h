#pragma once								//NoahD-M
#include "Entity.h"
#include "Vector2.h"

class Player : public Entity {
public:
	Vector2 position;

	void movement(char touche, Vector2 Position);

	void Playerdeath();

	
};

