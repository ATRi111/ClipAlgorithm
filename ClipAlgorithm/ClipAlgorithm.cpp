#include"ClipAlgorithm.h"
#include"Test.h"
#include"LiangBarskyAlgorithm.h"
using namespace std;

#pragma region ClipAlgorithm
TestAnswer* ClipAlgorithm::Run(TestCase* t,Stopwatch* timer)
{
	TestCase_Clip* clip = dynamic_cast<TestCase_Clip*>(t);
	Vector2 p1 = clip->p1;
	Vector2 p2 = clip->p2;
	if (timer)
		timer->Start();
	bool valid = Clip(clip->xMin, clip->xMax, clip->yMin, clip->yMax, p1, p2);
	if (timer)
		timer->Pause();
	return new TestAnswer_Clip(p1, p2, valid);
}
bool ClipAlgorithm::Clip(float xMin, float xMax, float yMin, float yMax, Vector2& p1, Vector2& p2)
{
	return false;
}
#pragma endregion

#pragma region TestCase_Clip
TestCase_Clip::TestCase_Clip(float xMin, float xMax, float yMin, float yMax, Vector2 p1, Vector2 p2)
	:xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax), p1(p1), p2(p2)
{

}

TestCase_Clip::~TestCase_Clip()
{

}
void TestCase_Clip::Print() const
{
	cout << "xMin=" << xMin << ",";
	cout << "xMax=" << xMax << ",";
	cout << "yMin=" << yMin << ",";
	cout << "yMax=" << yMax << ",";
	cout << "p1" << p1 << ",";
	cout << "p2" << p2 << endl;
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

TestAnswer_Clip::TestAnswer_Clip() 
	:valid(false)
{

}
TestAnswer_Clip::TestAnswer_Clip(Vector2 p1, Vector2 p2, bool valid)
	:p1(p1), p2(p2), valid(valid)
{

}
bool TestAnswer_Clip::Match(TestAnswer* other) const
{
	TestAnswer_Clip* p = dynamic_cast<TestAnswer_Clip*>(other);
	if (!p || p->valid != valid)
		return false;

	if (!p->valid && !valid)
		return true;

	return Match(p1, p2, p->p1, p->p2);
}
void TestAnswer_Clip::Print() const
{
	if (!valid)
		cout << "(不保留线段)" << endl;
	else
		cout << p1 << " " << p2 << endl;
}
#pragma endregion

#pragma region TestSerializer_Clip
void TestSerializer_Clip::Serialize(std::ofstream& stream, const TestSet& set) const
{
	for (int i = 0; i < set.cases.size(); i++)
	{
		TestCase_Clip* c = dynamic_cast<TestCase_Clip*>(set.cases[i]);
		TestAnswer_Clip* a = dynamic_cast<TestAnswer_Clip*>(set.answers[i]);
		if (c && a)
		{
			stream << c->p1.x << " ";
			stream << c->p1.y << " ";
			stream << c->p2.x << " ";
			stream << c->p2.y << " ";
			if (a->valid)
			{
				stream << a->p1.x << " ";
				stream << a->p1.y << " ";
				stream << a->p2.x << " ";
				stream << a->p2.y;
			}
			stream << endl;
		}
	}
}

TestSet TestSerializer_Clip::Deserialize(std::ifstream& stream) const
{
	std::vector<TestCase*> cases;
	std::vector<TestAnswer*> answers;
	string s;
	while (getline(stream, s))
	{
		vector<string> ss = Split(s,' ');
		vector<float> fs;
		for (int i = 0; i < ss.size(); i++)
		{
			try
			{
				float f = stof(ss[i]);
				fs.push_back(f);
			}
			catch(...)
			{
				continue;
			}
		}

		Vector2 p1, p2;
		TestCase* c;
		vector<Vector2>* vs = new vector<Vector2>();
		TestAnswer* answer;
		switch (fs.size())
		{
		case 4:
			p1 = Vector2(fs[0], fs[1]);
			p2 = Vector2(fs[2], fs[3]);
			answer = new TestAnswer_Clip();
			break;
		case 8:
			p1 = Vector2(fs[0], fs[1]);
			p2 = Vector2(fs[2], fs[3]);
			answer = new TestAnswer_Clip(Vector2(fs[4], fs[5]), Vector2(fs[6], fs[7]), true);
			break;
		default:
			throw "InvalidArgument";
			continue;
			break;
		}
		c = new TestCase_Clip(10, 20, 10, 20, p1, p2);
		cases.push_back(c);
		answers.push_back(answer);
	}
	return TestSet(cases, answers, Solution::CreateDefaultSolution);
}
#pragma endregion