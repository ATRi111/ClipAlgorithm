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
	Vector2();
	Vector2(float x, float y);
	Vector2& operator=(const Vector2& v);
	bool operator==(const Vector2& v) const;
	float SqrMagnitude() const;
	float Magnitude() const;
	Vector2 Normalize() const;
}; 

Vector2 operator+(Vector2 a, Vector2 b);
Vector2 operator-(Vector2 a, Vector2 b);
Vector2 operator*(float f, Vector2 v);
Vector2 operator*(Vector2 v, float f);
Vector2 operator/(Vector2 v, float f);
std::ostream& operator<<(std::ostream& stream, const Vector2& v);