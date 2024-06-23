#pragma once
#include"Test.h"
#include"Vector2.h"
#include<vector>
#include<iostream>

class ClipAlgorithm : public Solution
{
public:
	TestAnswer* Run(TestCase* t) override;
	std::vector<Vector2>* Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2);
};

struct TestAnswer_Clip : TestAnswer
{
	static const float Epsilon;
	bool static Match(float a, float b);
	bool static Match(Vector2 a, Vector2 b);
	bool static Match(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2);

	const std::vector<Vector2>* answer;
	TestAnswer_Clip();
	TestAnswer_Clip(std::vector<Vector2>* answer);
	virtual ~TestAnswer_Clip();
	bool Match(TestAnswer* other) const override;
};