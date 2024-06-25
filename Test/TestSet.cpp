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
	cout << "����" << repeatTimes * cases.size() << "�β�����������";
	cout << std::fixed << std::setprecision(0) << sum << "����" << endl;
	return sum;
}
double TestSet::AccuracyTest(int printTimes = 3)
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
			TestSet::Print(cases[i], answers[i], output, matched);
		delete output;
		delete s;
	}
	sum /= cases.size();
	cout << "������" << cases.size() << "������������׼ȷ��Ϊ";
	cout << std::fixed << std::setprecision(2) << sum * 100.0 << "%" << std::endl;
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
void TestSet::Print(TestCase* c, TestAnswer* points, TestAnswer* output, bool matched)
{
	cout << "����:";
	if (c)
		c->Print();
	else
		cout << "(nullptr)" << endl;
	cout << "��ȷ���:";
	if (points)
		points->Print();
	else
		cout << "(nullptr)" << endl;
	cout << "������:";
	if (output)
		output->Print();
	else
		cout << "(nullptr)" << endl;
	if (matched)
		cout << "�����ȷ" << endl;
	else
		cout << "�������" << endl;
	cout << endl;
}