#include "ClipAlgorithm.h"
#include "Test.h"
using namespace std;

TestAnswer* ClipAlgorithm::Run(TestCase* t)
{
	return new TestAnswer_Clip();
}
vector<Vector2>* ClipAlgorithm::Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2)
{
	return new vector<Vector2>();
}


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

TestAnswer_Clip::TestAnswer_Clip():answer(nullptr)
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
