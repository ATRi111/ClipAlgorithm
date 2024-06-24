#include"Test.h"
#include"Stopwatch.h"
#include<vector>
using namespace std;

#pragma region TestCase
TestCase::~TestCase()
{

}
#pragma endregion

#pragma region TestAnswer
TestAnswer::~TestAnswer()
{

}
bool TestAnswer::Match(TestAnswer* other) const
{
	return true;
}
#pragma endregion

#pragma region Solution
Solution* Solution::CreateDefaultSolution()
{
	return new Solution();
}
double Solution::TimeTest(TestCase* t)
{
	Stopwatch timer;
	timer.Start();
	Run(t);
	timer.Pause();
	return timer.Milliseconds();
}
TestAnswer* Solution::Run(TestCase* t)
{
	return new TestAnswer();
}
#pragma endregion

#pragma region TestLauncher
TestLauncher::TestLauncher(std::vector<TestCase*>&& cases, std::vector<TestAnswer*>&& answers, const std::function<Solution* ()>& CreateSolution)
	:cases(cases), answers(answers), CreateSolution(CreateSolution)
{

}
TestLauncher::~TestLauncher()
{
	for (int i = 0; i < cases.size(); i++)
	{
		delete cases[i];
	}
	for (int i = 0; i < answers.size(); i++)
	{
		delete answers[i];
	}
}
double TestLauncher::TimeTest(int repeatTimes = 1)
{
	double sum = 0.0;
	for (int i = 0; i < repeatTimes; i++)
	{
		for (int i = 0; i < cases.size(); i++)
		{
			Solution* s = CreateSolution();
			sum += s->TimeTest(cases[i]);
			delete s;
		}
	}
	return sum;
}
double TestLauncher::CorrectnessTest(int printTimes)
{
	if (answers.size() != cases.size())
		return 0.0f;
	double sum = 0.0;
	for (int i = 0; i < cases.size(); i++)
	{
		Solution* s = CreateSolution();
		TestAnswer* answer = s->Run(cases[i]);
		sum += answers[i]->Match(answer);
		delete answer;
		delete s;
	}
	return sum / cases.size();
}
#pragma endregion