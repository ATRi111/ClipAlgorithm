#include"Test.h"
#include"Stopwatch.h"
#include<vector>
using namespace std;

bool TestAnsnwer::Match(TestAnsnwer other) const
{
	return true;
}

Solution Solution::CreateDefaultSolution()
{
	return Solution();
}
double Solution::TimeTest(TestCase t)
{
	Stopwatch timer;
	timer.Start();
	Run(t);
	timer.Pause();
	return timer.Milliseconds();
}
TestAnsnwer Solution::Run(TestCase t)
{
	return TestAnsnwer();
}

TestLauncher::TestLauncher(const vector<TestCase>& cases, const vector<TestAnsnwer>& answers, const function<Solution()>& CreateSolution)
	:cases(cases),answers(answers),CreateSolution(CreateSolution)
{

}
double TestLauncher::TimeTest()
{
	double sum = 0.0;
	for (int i = 0; i < cases.size(); i++)
	{
		Solution s = CreateSolution();
		sum += s.TimeTest(cases[i]);
	}
	return sum;
}
double TestLauncher::CorrectnessTest()
{
	double sum = 0.0;
	for (int i = 0; i < cases.size(); i++)
	{
		Solution s = CreateSolution();
		TestAnsnwer answer = s.Run(cases[i]);
		sum += answers[i].Match(answer);
	}
	return sum / cases.size();
}