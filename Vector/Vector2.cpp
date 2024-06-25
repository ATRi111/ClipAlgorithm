#include "Vector2.h"
#include<iostream>
using namespace std;

#pragma region Vector2
const Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
const Vector2 Vector2::One = Vector2(1.0f, 1.0f);
const Vector2 Vector2::Up = Vector2(1.0f, 0.0f);
const Vector2 Vector2::Down = Vector2(-1.0f, 0.0f);
const Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
const Vector2 Vector2::Left = Vector2(-1.0f, 0.0f);

Vector2 operator+(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}
Vector2 operator-(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x - b.x, a.y - b.y);
}
Vector2 operator*(float f, const Vector2& v)
{
	return Vector2(f * v.x, f * v.y);
}
Vector2 operator*(const Vector2& v, float f)
{
	return Vector2(f * v.x, f * v.y);
}
Vector2 operator/(const Vector2& v, float f)
{
	return Vector2(v.x / f, v.y / f);
}
ostream& operator<<(ostream& stream, const Vector2& v)
{
	stream << "(" << v.x << "," << v.y << ")";
	return stream;
}
#pragma endregion