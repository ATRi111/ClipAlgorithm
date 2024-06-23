#include"Test.h"
#include"Stopwatch.h"
#include<vector>
using namespace std;

TestAnswer::~TestAnswer()
{

}
bool TestAnswer::Match(TestAnswer* other) const
{
	return true;
}

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

TestLauncher::TestLauncher(const std::vector<TestCase*>& cases, const std::vector<TestAnswer*>& answers, const std::function<Solution*()>& CreateSolution)
	:cases(cases),answers(answers),CreateSolution(CreateSolution)
{

}
double TestLauncher::TimeTest()
{
	double sum = 0.0;
	for (int i = 0; i < cases.size(); i++)
	{
		Solution* s = CreateSolution();
		sum += s->TimeTest(cases[i]);
	}
	return sum;
}
double TestLauncher::CorrectnessTest()
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
	}
	return sum / cases.size();
}