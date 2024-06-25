#pragma once
#include"Test.h"
#include"Stopwatch.h"
#include"Vector2.h"
#include"TestSerializer.h"
#include"Algorithm.h"
#include<vector>
#include<iostream>

class ClipAlgorithm : public Algorithm
{
public:
	TestAnswer* Run(TestCase* t, Stopwatch* timer) override;
	virtual bool Clip(float xMin, float xMax, float yMin, float yMax, Vector2& p1, Vector2& p2);
};

struct TestCase_Clip : TestCase
{
	float xMin, xMax, yMin, yMax;
	Vector2 p1, p2;
	TestCase_Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2);
	~TestCase_Clip();
	void Print() const override;
};

struct TestAnswer_Clip : TestAnswer
{
	static const float Epsilon;
	bool static Match(float a, float b);
	bool static Match(Vector2 a, Vector2 b);
	bool static Match(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2);

	Vector2 p1, p2;
	bool valid;
	TestAnswer_Clip();
	TestAnswer_Clip(Vector2 p1, Vector2 p2, bool valid);
	bool Match(TestAnswer* other) const override;
	void Print() const override;
};

class TestSerializer_Clip : public TestSerializer
{
public:
	virtual void Serialize(std::ofstream& stream, const TestSet& set) const override;
	virtual TestSet Deserialize(std::ifstream& stream) const override;
};