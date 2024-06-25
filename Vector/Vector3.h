#pragma once
#include<iostream>
#include"Vector2.h"

class Vector3
{
	const static Vector3 Zero;
	const static Vector3 One;
	const static Vector3 Up;
	const static Vector3 Down;
	const static Vector3 Right;
	const static Vector3 Left;

	union
	{
		struct
		{
			float x, y, z;
		};
		struct
		{
			Vector2 v2d;
			float z;
		};
	};
	Vector3()
		:x(0.0f), y(0.0f), z(0.0f)
	{

	}
	Vector3(float x, float y, float z = 0.0f)
		:x(x), y(y), z(z)
	{

	}
	Vector3& operator=(const Vector2& v)
	{
		v2d = v;
		return *this;
	}
	Vector3& operator=(const Vector3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	bool operator==(const Vector3& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}
	Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}
	Vector3 operator-(const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	Vector3 operator*(float f) const
	{
		return Vector3(f * x, f * y);
	}
	Vector3 operator/(float f) const
	{
		return Vector3(x / f, y / f, z / f);
	}

	float SqrMagnitude() const
	{
		return x * x + y * y + z * z;
	}
	float Magnitude() const
	{
		return sqrtf(x * x + y * y + z * z);
	}
	Vector3& Normalized()
	{
		float f = Magnitude();
		if (f != 0)
		{
			x /= f;
			y /= f;
			z /= f;
		}
		return *this;
	}
	Vector3 Normalized() const
	{
		float f = Magnitude();
		if (f == 0)
			return Vector3::Zero;
		return Vector3(x / f, y / f, z / f);
	}
};