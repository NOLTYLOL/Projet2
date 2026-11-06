#include "Enemy.h" //Gilio

Enemy::Enemy()
{
	Life = 1;
	Damage = 1;
}

Enemy::Enemy(Vector2 startPos)
{
	Life = 1;
	Damage = 1;
	position = startPos;
}
