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
	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 operator-() const
	{
		return Vector2(-x, -y);
	}
	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}
	Vector2 operator*(float f) const
	{
		return Vector2(f * x, f * y);
	}
	Vector2 operator/(float f) const
	{
		return Vector2(x / f, y / f);
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

inline Vector2 operator*(float f, const Vector2& v)
{
	return Vector2(f * v.x, f * v.y);
}
inline std::ostream& operator<<(std::ostream& stream, const Vector2& v)
{
	stream << "(" << v.x << "," << v.y << ")";
	return stream;
}