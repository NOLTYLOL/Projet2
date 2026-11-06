#include "Vector2.h"

Vector2 operator+(const Vector2& vectorA, const Vector2& vectorB)
{
	Vector2 temp;
	temp.x = vectorA.x + vectorB.x;
	temp.y = vectorA.y + vectorB.y;
	return temp;
}

bool operator==(const Vector2& vectorA, const Vector2& vectorB)
{
	return vectorA.x == vectorB.x && vectorA.y == vectorB.y;
}
