#include "Mage.h"

Mage::Mage()
{
	Life = 1;
	Damage = 1;
}

void Mage::zoneDamage(std::vector<Enemy*>& enemies)
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i]->IsAlive())
		{
			continue;
		}
		Vector2 enemyPos = enemies[i]->GetPosition();
		int dx = enemyPos.x - position.x;
		int dy = enemyPos.y - position.y;
		if (dx >= -1 && dx <= 1 && dy >= -1 && dy <= 1)
		{
			enemies[i]->TakeDamage(Damage);
		}
	}
}

bool Mage::handleSpecialAction(char touche, std::vector<Enemy*>& enemies)
{
	if (touche == 'e' || touche == 'E')
	{
		zoneDamage(enemies);
		return true;
	}
	return false;
}
