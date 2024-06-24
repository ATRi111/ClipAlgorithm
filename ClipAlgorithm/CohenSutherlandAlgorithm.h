#pragma once
#include"ClipAlgorithm.h"
#include"Vector2.h"

class CohenSutherlandAlgorithm : public ClipAlgorithm
{
	Vector2 p1, p2, r;
	int code1, code2;
	float xMin, xMax, yMin, yMax;
	int Calculate(Vector2 p) const;
	Vector2 Intersect(int last) const;
	Vector2 IntersectY(float y) const;
	Vector2 IntersectX(float x) const;
public:
	static CohenSutherlandAlgorithm* CreateCohenSutherlandAlgorithm();
	CohenSutherlandAlgorithm();
	bool Clip(float xMin, float xMax, float yMin, float yMax, Vector2& p1, Vector2& p2) override;
};

