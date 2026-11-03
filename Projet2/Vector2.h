#pragma once
struct Vector2
{
	int x = 0;
	int	y = 0;
};

Vector2 operator + (static Vector2 & vectorA,static Vector2 & vectorB)
{
	Vector2 temp;
	temp.x = vectorA.x + vectorB.x;
	temp.y = vectorA.y + vectorB.y;
	return temp;
}

bool operator == (static Vector2& vectorA, static Vector2& vectorB)
{
	return vectorA.x == vectorB.x && vectorA.y == vectorB.y;
}


