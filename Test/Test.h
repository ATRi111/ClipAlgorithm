#pragma once
#include<vector>
#include<iostream>
#include<functional>

//base class for all kinds of input
struct TestCase
{
	virtual ~TestCase();
};
//base class for all kinds of input output
struct TestAnswer
{
	virtual ~TestAnswer();
	virtual bool Match(TestAnswer* other) const;
};

//one Solution is used for solving one TestCase
class Solution
{
public:
	static Solution* CreateDefaultSolution();
	double TimeTest(TestCase* t);
	virtual TestAnswer* Run(TestCase* t);
};

//one TestLauncher is used for measuring time and correctness of a set of Testcases
class TestLauncher
{
	const std::vector<TestCase*> cases;
	const std::vector<TestAnswer*> answers;
	std::function<Solution*()> CreateSolution;
public:
	//all pointers in these vectors will be deleted on deconstructed; each pointer must be unique(or nullptr)
	TestLauncher(std::vector<TestCase*>&& cases, std::vector<TestAnswer*>&& answers, const std::function<Solution*()>& CreateSolution);
	~TestLauncher();
	double TimeTest(int repeatTimes);
	double CorrectnessTest(int printTimes);
};