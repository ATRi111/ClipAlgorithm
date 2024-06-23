#pragma once
#include"ClipAlgorithm.h"
#include"Vector2.h"

class LiangBarskyAlgorithm : public ClipAlgorithm 
{
	Vector2 r;
	bool IntersectAndCheck(float p, float q);
	float uIn, uOut;
public:
	std::vector<Vector2>* Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2) override;
};
