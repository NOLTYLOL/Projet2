#include "Entity.h"							//NoahD-M

Vector2 Entity::GetPosition() const
{
	return position;
}

void Entity::SetPosition(Vector2 newPos)
{
	position = newPos;
}

void Entity::TakeDamage(int damage)
{
	Life -= damage;
	if (Life < 0)
	{
		Life = 0;
	}
}

int Entity::getLife() const
{
	return Life;
}

bool Entity::IsAlive() const
{
	return Life > 0;
}

void Entity::movement(Vector2 direction)
{
	position = position + direction;
}

void Entity::onCollision(Entity& other)
{
	TakeDamage(other.Damage);
}
