#pragma once								//NoahD-M
#include "Entity.h"
#include "Vector2.h"

class Player : public Entity {
public:

	void movement(char touche, Vector2 direction, Vector2& position);

	void Playerdeath();
};

