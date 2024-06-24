#include"ClipAlgorithm.h"
#include"Test.h"
#include"LiangBarskyAlgorithm.h"
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
		return a2.empty();
	case 2:
		return a2.size() == 2 && Match(a1[0], a1[1], a2[0], a2[1]);
	default:
		return false;
	}
	return false;
}
void TestAnswer_Clip::Print() const
{
	if (!answer)
		cout << "(nullptr)" << endl;
	else if (answer->empty())
		cout << "(空数组)" << endl;
	else
	{
		int i = 0;
		for (int i = 0; i < answer->size(); i++)
		{
			cout << (*answer)[i] << " ";
		}
		cout << endl;
	}
}
#pragma endregion

#pragma region TestSerializer_Clip
void TestSerializer_Clip::Serialize(std::ofstream& stream, const TestSet& set) const
{

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
		TestAnswer* answer = new TestAnswer_Clip(vs);
		switch (fs.size())
		{
		case 4:
			p1 = Vector2(fs[0], fs[1]);
			p2 = Vector2(fs[2], fs[3]);
			break;
		case 8:
			p1 = Vector2(fs[0], fs[1]);
			p2 = Vector2(fs[2], fs[3]);
			vs->emplace_back(fs[4], fs[5]);
			vs->emplace_back(fs[6], fs[7]);
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
	return TestSet(cases, answers, LiangBarskyAlgorithm::CreateLiangBarskyAlgorithm);
}
#pragma endregion