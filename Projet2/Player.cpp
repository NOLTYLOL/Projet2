#include "Player.h"

void Player::movement(char touche, Vector2 direction )
{

	if (touche == 'z' || touche == 'Z') direction.y--;
	if (touche == 's' || touche == 'S') direction.y++;
	if (touche == 'q' || touche == 'Q') direction.x--;
	if (touche == 'd' || touche == 'D') direction.x++;

	position = position + direction;

	
}
