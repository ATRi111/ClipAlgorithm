#include<iostream>
#include<vector>
#include"Vector2.h"
#include"Test.h"
#include"LiangBarskyAlgorithm.h"
#include"CohenSutherlandAlgorithm.h"
using namespace std;

int main()
{
	TestCase_Clip* c = new TestCase_Clip(10, 20, 10, 20, Vector2(0, 0), Vector2(30, 30));
	Solution* s = CohenSutherlandAlgorithm::CreateCohenSutherlandAlgorithm();

	vector<TestCase*> cases;
	for (int i = 0; i < 100; i++)
	{
		cases.push_back(new TestCase_Clip(10, 20, 10, 20, Vector2(0, 0), Vector2(30, 30)));
	}
	vector<TestAnswer*> answers;
	for (int i = 0; i < 100; i++)
	{
		answers.push_back(nullptr);
	}
	TestLauncher l = TestLauncher(move(cases), move(answers), CohenSutherlandAlgorithm::CreateCohenSutherlandAlgorithm);
	for (int i = 0; i < 100; i++)
	{
		delete cases[i];
		delete answers[i];
	}
}