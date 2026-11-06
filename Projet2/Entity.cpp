#include "Entity.h"							//NoahD-M
#include "Vector2.h"

Vector2 Entity::GetPosition() const
{
	return Vector2(0, 0);
}

void Entity::TakeDamage(int damage)
{
	int finalDamage = damage;

	Life -= finalDamage;
	if (Life < 0)
		Life = 0;
};

int Entity::getLife() {
	return Life;
}

bool Entity::IsAlive() {
	if (Life > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Entity::movement(Vector2 direction, Vector2& Newposition, Vector2& position)
{
	Newposition = position + direction;
}