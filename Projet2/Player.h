#pragma once
#include "Entity.h"
#include "Vector2.h"

class Player : public Entity {
private:
	Vector2 position;

	void movement(char touche, Vector2 position);
    
};
