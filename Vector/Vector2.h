#pragma once
#include<iostream>

struct Vector2
{
	const static Vector2 Zero;
	const static Vector2 One;
	const static Vector2 Up;
	const static Vector2 Down;
	const static Vector2 Right;
	const static Vector2 Left;

	float x, y;
	Vector2()
		:x(0.0f), y(0.0f)
	{

	}
	Vector2(float x, float y)
		:x(x), y(y)
	{

	}
	Vector2& operator=(const Vector2& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	bool operator==(const Vector2& v) const
	{
		return x == v.x && y == v.y;
	}
	float SqrMagnitude() const
	{
		return x * x + y * y;
	}
	float Magnitude() const
	{
		return sqrtf(x * x + y * y);
	}

	Vector2& Normalized()
	{
		float f = Magnitude();
		if (f != 0)
		{
			x /= f;
			y /= f;
		}
		return *this;
	}
	Vector2 Normalized() const
	{
		float f = Magnitude();
		if (f == 0)
			return Vector2::Zero;
		return Vector2(x / f, y / f);
	}
}; 

Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& a, const Vector2& b);
Vector2 operator*(float f, const Vector2& v);
Vector2 operator*(const Vector2& v, float f);
Vector2 operator/(const Vector2& v, float f);
std::ostream& operator<<(std::ostream& stream, const Vector2& v);