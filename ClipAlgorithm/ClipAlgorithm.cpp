#include "ClipAlgorithm.h"
#include "Test.h"
using namespace std;

#pragma region ClipAlgorithm
TestAnswer* ClipAlgorithm::Run(TestCase* t)
{
	TestCase_Clip* clip = dynamic_cast<TestCase_Clip*>(t);
	vector<Vector2>* answer = Clip(clip->xMin, clip->xMax, clip->yMin, clip->yMax, clip->p1, clip->p2);
	return new TestAnswer_Clip(answer);
}
vector<Vector2>* ClipAlgorithm::Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2)
{
	return new vector<Vector2>();
}
#pragma endregion

#pragma region TestCase_Clip
TestCase_Clip::TestCase_Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2)
	:xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax), p1(p1), p2(p2)
{

}

TestCase_Clip::~TestCase_Clip()
{
	cout << "deconstruct" << this << endl;
}
#pragma endregion

#pragma region TestAnswer_Clip
const float TestAnswer_Clip::Epsilon = 0.01f;
bool TestAnswer_Clip::Match(float a, float b)
{
	return abs(a - b) < Epsilon;
}
bool TestAnswer_Clip::Match(Vector2 a, Vector2 b)
{
	return Match(a.x, b.x) && Match(a.y, b.y);
}
bool TestAnswer_Clip::Match(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2)
{
	return Match(a1, b1) && Match(a2, b2) || Match(a1, b2) && Match(a2, b1);
}

TestAnswer_Clip::TestAnswer_Clip() :answer(nullptr)
{

}
TestAnswer_Clip::TestAnswer_Clip(vector<Vector2>* answer) :answer(answer)
{

}
TestAnswer_Clip::~TestAnswer_Clip()
{
	delete answer;
}
bool TestAnswer_Clip::Match(TestAnswer* other) const
{
	TestAnswer_Clip* p = dynamic_cast<TestAnswer_Clip*>(other);
	if (!p || !p->answer || !answer)
		return false;

	const std::vector<Vector2>& a1 = *answer;
	const std::vector<Vector2>& a2 = *p->answer;

	switch (a1.size())
	{
	case 0:
		return a2.size() == 0;
	case 2:
		return a2.size() == 2 && Match(a1[0], a1[1], a2[0], a2[1]);
	default:
		return false;
	}
	return false;
}
#pragma endregion
