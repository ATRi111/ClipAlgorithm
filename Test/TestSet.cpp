#include "TestSet.h"
using namespace std;

TestSet::TestSet(vector<TestCase*>& cases, vector<TestAnswer*>& answers, const function<Algorithm* ()>& CreateSolution)
	:cases(cases), answers(answers), CreateSolution(CreateSolution)
{

}
TestSet::~TestSet()
{

}
double TestSet::TimeTest(int repeatTimes = 1)
{
	double sum = 0.0;
	for (int j = 0; j < repeatTimes; j++)
	{
		for (int i = 0; i < cases.size(); i++)
		{
			Algorithm* s = CreateSolution();
			sum += s->TimeTest(cases[i]);
			delete s;
		}
	}
	cout << "运行" << repeatTimes * cases.size() << "次测试用例花费";
	cout << std::fixed << std::setprecision(0) << sum << "毫秒" << endl;
	return sum;
}
double TestSet::AccuracyTest(int printTimes = 3, bool guranteed = false)
{
	if (answers.size() != cases.size())
		return 0.0f;
	double sum = 0.0;
	for (int i = 0; i < cases.size(); i++)
	{
		Algorithm* s = CreateSolution();
		TestAnswer* output = s->Run(cases[i], nullptr);
		bool matched = answers[i] ? answers[i]->Match(output) : false;
		sum += matched;
		if (i < printTimes)
			TestSet::Print(cases[i], answers[i], output, matched, guranteed);
		delete output;
		delete s;
	}
	sum /= cases.size();
	if (!guranteed)
	{
		cout << "运行这" << cases.size() << "个测试用例的准确率为";
		cout << std::fixed << std::setprecision(2) << sum * 100.0 << "%" << std::endl;
	}
	return sum;
}
void TestSet::GenerateAnswers()
{
	DeleteAnswers();
	for (int i = 0; i < cases.size(); i++)
	{
		Algorithm* s = CreateSolution();
		TestAnswer* output = s->Run(cases[i], nullptr);
		answers.push_back(output);
		delete s;
	}
}
void TestSet::DeleteAnswers()
{
	for (int i = 0; i < answers.size(); i++)
	{
		delete answers[i];
	}
	answers.clear();
}
void TestSet::DeleteCases()
{
	for (int i = 0; i < cases.size(); i++)
	{
		delete cases[i];
	}
	cases.clear();
}
void TestSet::Print(TestCase* c, TestAnswer* a, TestAnswer* output, bool matched, bool guaranteed = false)
{
	cout << "输入:";
	if (c)
		c->Print();
	else
		cout << "(nullptr)" << endl;


	if (!guaranteed)
	{
		cout << "答案:";
		if (a)
			a->Print();
		else
			cout << "(nullptr)" << endl;
	}
	cout << "输出:";
	if (output)
		output->Print();
	else
		cout << "(nullptr)" << endl;

	if (!guaranteed)
	{
		if (matched)
			cout << "输出正确" << endl;
		else
			cout << "输出错误" << endl;
	}
	cout << endl;
}