#pragma once

struct Vector2
{
	int x = 0;
	int y = 0;
};

Vector2 operator+(const Vector2& vectorA, const Vector2& vectorB);
bool operator==(const Vector2& vectorA, const Vector2& vectorB);
