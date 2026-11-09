#include "Enemy.h" //Gilio

Enemy::Enemy()
{
	Life = 1;
	Damage = 1;
	symbol = 'Z';
}

Enemy::Enemy(Vector2 startPos, char enemySymbol)
{
	Life = 1;
	Damage = 1;
	position = startPos;
	symbol = enemySymbol;
}

char Enemy::getSymbol() const
{
	return symbol;
}

Vector2 Enemy::getDirection(Vector2 playerPos)
{
	return { 0, 0 };
}
