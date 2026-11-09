#pragma once //NoahD-M
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Mage : public Player
{
public:
	Mage();
	void zoneDamage(std::vector<Enemy*>& enemies);
	bool handleSpecialAction(char touche, std::vector<Enemy*>& enemies) override;
};
