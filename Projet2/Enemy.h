#pragma once // Gilio
#include "Entity.h"

class Enemy : public Entity {

private:
  void death();
  int Life = 1;
  int damage = 1;


public:
  Enemy();
  Vector2 Enemypos;
};