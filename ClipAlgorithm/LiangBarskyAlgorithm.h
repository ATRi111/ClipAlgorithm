#pragma once
#include"ClipAlgorithm.h"
#include"Vector2.h"

class LiangBarskyAlgorithm : public ClipAlgorithm 
{
	Vector2 r;
	bool IntersectAndCheck(float p, float q1, float q2);
	float uIn, uOut;
public:
	static LiangBarskyAlgorithm* CreateLiangBarskyAlgorithm();
	LiangBarskyAlgorithm();
	bool Clip(float xMin, float xMax, float yMin, float yMax, Vector2& p1, Vector2& p2) override;
};