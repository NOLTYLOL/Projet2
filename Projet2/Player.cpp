#include "Player.h"						//NoahD-M
#include <iostream>

void Player::movement(char touche)
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

	position = position + direction;
}

void Player::Playerdeath()
{
	if (Life == 0)
	{
		std::cout << "You are dead" << std::endl;
	}
}
