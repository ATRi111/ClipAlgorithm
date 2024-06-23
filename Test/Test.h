#pragma once
#include<vector>
#include<iostream>
#include<functional>

//Base class for all kinds of input
struct TestCase
{
	virtual ~TestCase();
};
//Base class for all kinds of input output
struct TestAnswer
{
	virtual ~TestAnswer();
	virtual bool Match(TestAnswer* other) const;
};

//One Solution is used for solving one TestCase
class Solution
{
public:
	static Solution* CreateDefaultSolution();
	double TimeTest(TestCase* t);
	virtual TestAnswer* Run(TestCase* t);
};

//One TestLauncher is used for measuring time and correctness of a set of Testcases
class TestLauncher
{
	const std::vector<TestCase*>& cases;
	const std::vector<TestAnswer*>& answers;
	std::function<Solution*()> CreateSolution;
public:
	TestLauncher(const std::vector<TestCase*>& cases, const std::vector<TestAnswer*>& answers, const std::function<Solution*()>& CreateSolution);
	double TimeTest(int repeatTimes);
	double CorrectnessTest();
};