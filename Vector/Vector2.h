#pragma once

struct Vector2
{
	int x, y;
	Vector2():x(0),y(0)
	{

	}
	Vector2(int x, int y) :x(x), y(y)
	{

	}
	Vector2(const Vector2& v) :x(v.x), y(v.y)
	{
		
	}
	//Vector2 operator=(Vector2 v);
}; 


Vector2 operator+(Vector2 a, Vector2 b);
Vector2 operator-(Vector2 a, Vector2 b);
