#include"Test.h"
#include"Stopwatch.h"
#include<vector>
using namespace std;

#pragma region TestCase
TestCase::~TestCase()
{

}
void TestCase::Print() const
{
	cout << endl;
}
#pragma endregion

#pragma region TestAnswer
TestAnswer::~TestAnswer()
{

}
bool TestAnswer::Match(TestAnswer* other) const
{
	return other;
}
void TestAnswer::Print() const
{
	cout << endl;
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
TestLauncher::TestLauncher(const std::vector<TestCase*>& cases, const std::vector<TestAnswer*>& answers, const std::function<Solution* ()>& CreateSolution)
	:cases(cases), answers(answers), CreateSolution(CreateSolution)
{

}
TestLauncher::~TestLauncher()
{

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
double TestLauncher::CorrectnessTest(int printTimes = 3)
{
	if (answers.size() != cases.size())
		return 0.0f;
	double sum = 0.0;
	for (int i = 0; i < cases.size(); i++)
	{
		Solution* s = CreateSolution();
		TestAnswer* output = s->Run(cases[i]);
		bool matched = answers[i] ? answers[i]->Match(output) : false;
		sum += matched;
		if (i < printTimes)
			TestLauncher::Print(cases[i], answers[i], output, matched);
		delete output;
		delete s;
	}
	return sum / cases.size();
}
void TestLauncher::Print(TestCase* c, TestAnswer* answer, TestAnswer* output, bool matched)
{
	cout << "输入:";
	if (c)
		c->Print();
	else
		cout << "(nullptr)" << endl;
	cout << "正确输出:";
	if (answer)
		answer->Print();
	else
		cout << "(nullptr)" << endl;
	cout << "你的输出:";
	if (output)
		output->Print();
	else
		cout << "(nullptr)" << endl;
	if (matched)
		cout << "输出正确" << endl;
	else
		cout << "输出错误" << endl;
	cout << endl;
}
#pragma endregion