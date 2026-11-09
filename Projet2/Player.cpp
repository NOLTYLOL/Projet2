#include "Player.h"						//NoahD-M
#include <iostream>

Vector2 Player::getDirection(char touche) const
{
	Vector2 direction = { 0, 0 };

	if (touche == 'z' || touche == 'Z')
	{
		direction.y--;
	}
	if (touche == 's' || touche == 'S')
	{
		direction.y++;
	}
	if (touche == 'q' || touche == 'Q')
	{
		direction.x--;
	}
	if (touche == 'd' || touche == 'D')
	{
		direction.x++;
	}
	return direction;
}

void Player::movement(char touche)
{
	Vector2 direction = getDirection(touche);
	position = position + direction;
}

void Player::Playerdeath()
{
	if (Life == 0)
	{
		std::cout << "You are dead" << std::endl;
	}
}

bool Player::handleSpecialAction(char touche, std::vector<Enemy*>& enemies)
{
	return false;
}
